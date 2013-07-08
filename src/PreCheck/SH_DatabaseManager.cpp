#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"
#include <QDebug>
#include <QtSql>
#include "SH_DatabaseManagerSettings.cpp"

/*namespace SimplHotel
{*/

const QString SH_DatabaseManager::dbInterbaseDriverStr = "QIBASE";
const QString SH_DatabaseManager::dbFirebirdDriverStr= "QIBASE";
const QString SH_DatabaseManager::dbPostgresqlDriverStr = "QPSQL";
const QString SH_DatabaseManager::dbMysqlDriverStr = "QMYSQL";


const QString SH_DatabaseManager::dbFilePathStr = QString("%1/%2").arg(SH_DatabaseManager::dbFolderPathStr).arg(SH_DatabaseManager::dbFileNameStr);

/*!
 * \details \~french
 * \fn SH_DatabaseManager::getInstance
*/
SH_DatabaseManager *SH_DatabaseManager::getInstance()
{
    if (SH_DatabaseManager::_instance == 0)
    {
        SH_DatabaseManager::_instance = new SH_DatabaseManager();
    }
    return SH_DatabaseManager::_instance;
}

void SH_DatabaseManager::setDriver(SH_DatabaseManager::dbDrivers driver)
{
    SH_DatabaseManager::_dbDriver = driver;
}

QSqlDriver *SH_DatabaseManager::dbDriver()
{
    return dbConnection.driver();
}


QString SH_DatabaseManager::dbDriverName()
{
    return dbConnection.driverName();
}

SH_DatabaseManager::dbDrivers SH_DatabaseManager::dbDriverLabel() {
    return SH_DatabaseManager::driverEnumFromName(dbDriverName());
}

/*!
 * \details \~french
 * \fn SH_DatabaseManager::~SH_DatabaseManager
*/
SH_DatabaseManager::~SH_DatabaseManager()
{
    dbDisconnect();
    SH_DatabaseManager::_instance = 0;
}


/*!
 * \details \~french
 * \fn SH_DatabaseManager::SH_DatabaseManager
*/
SH_DatabaseManager::SH_DatabaseManager()
{
    if(checkDriver()) {
        addDatabase();
        dbConnect();
    }
}

bool SH_DatabaseManager::checkDriver() {
    /*Check the existence of the database driver.*/
    if (!QSqlDatabase::isDriverAvailable(driverNameFromEnum(SH_DatabaseManager::_dbDriver)))
    {
        /*Gui message that informs that the driver does not exist*/
        SH_MessageManager::errorMessage(QObject::tr("%1 database driver is not available.").arg(driverNameFromEnum(SH_DatabaseManager::_dbDriver)));
        SH_MessageManager::errorMessage(dbConnection.lastError().text());
        SH_MessageManager::errorMessage("AVAILABLE DRIVERS: "+dbConnection.drivers().join(", "));
        return false;
    }
    return true;
}

void SH_DatabaseManager::addDatabase() {
    /*Connect to the database with the following driver.*/
    dbConnection = QSqlDatabase::addDatabase(driverNameFromEnum(SH_DatabaseManager::_dbDriver));
    if (dbDriverLabel() == SH_DatabaseManager::InterbaseDriver || dbDriverLabel() == SH_DatabaseManager::FirebirdDriver)
    {
        dbConnection.setDatabaseName(dbFilePathStr);
    } else {
        dbConnection.setDatabaseName(dbFileNameStr);
    }

    dbConnection.setUserName(dbUsernameStr);
    dbConnection.setPassword(dbPasswordStr);
}

/*connect to database
    */

/*!
    * \details \~french
 * \fn SH_DatabaseManager::dbConnect
    */
bool SH_DatabaseManager::dbConnect()
{

    /*Open database, if the database cannot open for
    *any reason print a warning.
    */
    if (!dbConnection.open())
    {

        /*Gui message that informs that the database cannot open
    */
        SH_MessageManager::errorMessage(QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr));
        SH_MessageManager::errorMessage(dbConnection.lastError().text());


        /*@return false if database connection failed.
    */
        return false;
    }


    /*@return true if database connection successed
    */
    return dbConnection.isOpen();
}

/*disconnects from a database
    */

/*!
    * \details \~french
 * \fn SH_DatabaseManager::dbDisconnect
    */
bool SH_DatabaseManager::dbDisconnect()
{

    /*close database
    */
    dbConnection.close();
    return (!dbConnection.isOpen());
}


/*!
    * \details \~french
 * \fn SH_DatabaseManager::isConnected
    */
bool SH_DatabaseManager::isConnected()
{
    return dbConnection.isOpen();
}


/*!
    * \details \~french
 * \fn SH_DatabaseManager::getDbConnection
    */
QSqlDatabase SH_DatabaseManager::getDbConnection()
{
    return dbConnection;
}

/*!
    * \details \~french
 * \fn SH_DatabaseManager::tableExistsl
    */
bool SH_DatabaseManager::tableExists(QString tableName)
{
    return dbConnection.tables(QSql::Views).contains(tableName.toUpper(), Qt::CaseInsensitive) || dbConnection.tables(QSql::Tables).contains(tableName.toUpper(), Qt::CaseInsensitive);
}

/*!
    * \details \~french
 * \fn SH_DatabaseManager::dataExists
    */
int SH_DatabaseManager::dataCount(QString tableName, QString filter) {
    if(!tableName.isEmpty() && !filter.isEmpty()) {
        QSqlQuery result = execSelectQuery(tableName, QStringList("COUNT(*) AS MATCH"), filter);
        if(dbDriver()->hasFeature(QSqlDriver::QuerySize)) {
            return result.size();
        } else {
            if(result.next()) {
                QSqlRecord rec = result.record();
                if(!rec.isEmpty() && result.isValid()) {
                    return rec.value(rec.indexOf("MATCH")).toInt();
                }
            }
        }
    }
    return 0;
}


/*!
    * \details \~french
 * \fn SH_DatabaseManager::execQuery
    */
QSqlQuery SH_DatabaseManager::execSelectQuery(QString tableName, QStringList fields, QString condition, QString ordering) {
    if(fields.isEmpty()) {
        fields.append("*");
    }

    QString query;
    if (dbDriverLabel() == SH_DatabaseManager::InterbaseDriver || dbDriverLabel() == SH_DatabaseManager::FirebirdDriver || dbDriverLabel() == SH_DatabaseManager::PostgresqlDriver|| dbDriverLabel() == SH_DatabaseManager::MysqlDriver) {
        query = QString("SELECT %1 FROM %2").arg(fields.join(", ")).arg(tableName);
        if(!condition.isEmpty()) {
            query = QString("%1 WHERE %2").arg(query).arg(condition);
        }
        if(!ordering.isEmpty()) {
            query = QString("%1 ORDER BY %2").arg(query).arg(ordering);
        }
    }
    //SH_MessageManager::debugMessage(query);
    QSqlQuery result;
    result.exec(query);
    //SH_MessageManager::debugMessage(QString("executed query %1: valid ? %2 active ? %3").arg(result.executedQuery()).arg(result.isValid()).arg(result.isActive()));
    return result;
}


/*!
    * \details \~french
 * \fn SH_DatabaseManager::execReplaceQuery
    */
bool SH_DatabaseManager::execReplaceQuery(QString tableName, QVariantMap values) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    if (dbDriverLabel() == SH_DatabaseManager::InterbaseDriver || dbDriverLabel() == SH_DatabaseManager::FirebirdDriver) {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID)").arg(tableName).arg(fields).arg(vals);
    } else if (dbDriverLabel() == SH_DatabaseManager::PostgresqlDriver) {
        //query = QString("REPLACE INTO %1(%2) VALUES(%3) MATCHING(ID)").arg(tableName).arg(fields).arg(vals);
    }
    QSqlQuery result = dbConnection.exec(query);
    //SH_MessageManager::debugMessage(QString("query %1: valid ? %2 active ? %3").arg(result.executedQuery()).arg(result.isValid()).arg(result.isActive()));
    return (result.numRowsAffected() > 0);
}

/*!
    * \details \~french
 * \fn SH_DatabaseManager::execInsertReturningQuery
    */
QVariant SH_DatabaseManager::execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    dbDrivers label = dbDriverLabel();
    if (label == SH_DatabaseManager::InterbaseDriver || label == SH_DatabaseManager::FirebirdDriver) {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID) RETURNING %4").arg(tableName).arg(fields).arg(vals).arg(returningField);
    } else if (label == SH_DatabaseManager::PostgresqlDriver) {
        //query = QString("REPLACE INTO %1(%2) VALUES(%3) MATCHING(ID) RETURNING %4").arg(tableName).arg(fields).arg(vals).arg(returningField);
    }
    QSqlQuery result = dbConnection.exec(query);
    //SH_MessageManager::debugMessage(QString("query %1: valid ? %2 active ? %3").arg(result.executedQuery()).arg(result.isValid()).arg(result.isActive()));
    if(result.next()) {
        QSqlRecord rec = result.record();
        if(!rec.isEmpty() && result.isValid()) {
            return rec.value(rec.indexOf(returningField));
        }
    }
    return QVariant();
}

/*!
    * \details \~french
 * \fn SH_divideQVariantMap
    */
void SH_DatabaseManager::divideQVariantMap(QVariantMap values, QString& fields, QString& vals) {
    for(auto field : values.keys())
    {
        fields += field+",";
        QVariant val = values.value(field);
        bool ok;
        int intVal = val.toInt(&ok);
        if(ok) {
            vals += QString::number(intVal)+",";
        }
        double dbVal = val.toDouble(&ok);
        if(ok) {
            vals += QString::number(dbVal)+",";
        }

        /*bool boolVal = val.toBool();
    if(boolVal) {
    &vals += "'"+1+"'',";
    }*/
        QDate dateVal = val.toDate();
        if(dateVal.isValid()) {
            vals += "'"+dateVal.toString()+"'',";
            /*FIXME adapt date format*/
        }
        QDateTime dateTimeVal = val.toDateTime();
        if(dateTimeVal.isValid()) {
            vals += "'"+dateTimeVal.toString()+"'',";
            /*FIXME adapt datetime format*/
        }
        QString stringVal = val.toString();
        vals += "'"+stringVal+"'',";
    }
    fields = fields.left(fields.lastIndexOf(',')-1);
    vals = vals.left(vals.lastIndexOf(',')-1);
}

/*}*/
