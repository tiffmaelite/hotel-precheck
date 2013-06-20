#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"
#include <QDebug>
#include <QtSql>

/*!
 * \details SH_DatabaseManager::_instance
 */
SH_DatabaseManager *SH_DatabaseManager::_instance = 0;


/*!
 \details

 \fn SH_AppDatabase::getInstance
*/
SH_DatabaseManager *SH_DatabaseManager::getInstance()
{
    if (_instance == 0)
    {
        _instance = new SH_DatabaseManager;
    }
    qDebug() << dbFilePathStr;
    return _instance;
}


/*!
 \details

 \fn SH_AppDatabase::~AppDatabase
*/
SH_DatabaseManager::~SH_DatabaseManager()
{
    dbDisconnect();
}


/*!
 \details

 \fn SH_AppDatabase::AppDatabase
*/
SH_DatabaseManager::SH_DatabaseManager()
{
    /*
     *Check the existence of the database driver.
     */
    if (!QSqlDatabase::isDriverAvailable(dbDriverStr))
    {
        /*
        *Gui message that informs that the driver does not exist
        */
        SH_MessageManager::errorMessage(dbDriverNotExistStr);
        qDebug() << dbConnection.lastError();
        for (int i = 0; i < dbConnection.drivers().count(); i++)
        {
            qDebug() << "AVAILABLE DRIVERS : " << dbConnection.drivers()[i] << endl;
        }
        exit(1);
    }

    /*
    *Connect to the database with the following driver.
    */
    dbConnection = QSqlDatabase::addDatabase(dbDriverStr);
    if (dbDriverStr == "QIBASE")
    {
        dbConnection.setDatabaseName(dbFilePathStr);
    } else {
        dbConnection.setDatabaseName(dbFileNameStr);
    }

    dbConnection.setUserName(dbUsernameStr);
    dbConnection.setPassword(dbPasswordStr);
    dbConnect();

}

/*
         *connect to database
         */

/*!
         \details

         \fn SH_AppDatabase::dbConnect
        */
bool SH_DatabaseManager::dbConnect()
{
    /*
            *Open database, if the database cannot open for
            *any reason print a warning.
            */
    if (!dbConnection.open())
    {
        /*
                 *Gui message that informs that the database cannot open
                 */
        SH_MessageManager::errorMessage(dbCannotOpenStr);
        qDebug() << dbConnection.lastError();

        /*
                 *@return false if database connection failed.
                 */
        return false;
    }

    /*
             *@return true if database connection successed
             */
    return dbConnection.isOpen();
}

/*
         *disconnects from a database
         */

/*!
         \details

         \fn SH_AppDatabase::dbDisconnect
        */
bool SH_DatabaseManager::dbDisconnect()
{
    /*
             *close database
             */
    dbConnection.close();
    return (!dbConnection.isOpen());
}


/*!
         \details

         \fn SH_AppDatabase::isConnected
        */
bool SH_DatabaseManager::isConnected()
{
    return dbConnection.isOpen();
}


/*!
         \details

         \fn SH_AppDatabase::getDbConnection
        */
QSqlDatabase SH_DatabaseManager::getDbConnection()
{
    return dbConnection;
}

/*!
         \details

         \fn SH_AppDatabase::tableExistsl
        */
bool SH_DatabaseManager::tableExists(QString tableName)
{
    return dbConnection.tables(QSql::Views).contains(tableName.toUpper(), Qt::CaseInsensitive) || dbConnection.tables(QSql::Tables).contains(tableName.toUpper(), Qt::CaseInsensitive);
}

/*!
         \details

         \fn SH_AppDatabase::dataExists
        */
int SH_DatabaseManager::dataCount(QString tableName, QString filter) {
    if(!tableName.isEmpty() && !filter.isEmpty()) {
        QSqlQuery result = execSelectQuery(tableName, QStringList("COUNT(*) AS MATCH"), filter);
        if(dbConnection.driver()->hasFeature(QSqlDriver::QuerySize)) {
            return result.size();
        } else {
            if(result.next()) {
                QSqlRecord rec = result.record();
                if(!rec.isEmpty()  && result.isValid()) {
                    return rec.value(rec.indexOf("MATCH")).toInt();
                }
            }
        }
    }
    return 0;
}


/*!
         \details

         \fn SH_AppDatabase::execQuery
        */
QSqlQuery SH_DatabaseManager::execSelectQuery(QString tableName, QStringList fields, QString condition, QString ordering) {
    if(fields.isEmpty()) {
        fields.append("*");
    }

    QString query;
    if(dbConnection.driverName() == "QIBASE") {
        query = QString("SELECT %1 FROM %2").arg(fields.join(", ")).arg(tableName);
        if(!condition.isEmpty()) {
            query = QString("%1 WHERE %2").arg(query).arg(condition);
        }
        if(!ordering.isEmpty()) {
            query = QString("%1 ORDER BY %2").arg(query).arg(ordering);
        }
    }
    qDebug() << query;
    QSqlQuery result;
    result.exec(query);
    qDebug() << result.executedQuery() << " > " << result.isValid() <<" "<< result.isActive();
    return result;
}


/*!
         \details
         \fn SH_AppDatabase::execReplaceQuery TODO comment this
        */
bool SH_DatabaseManager::execReplaceQuery(QString tableName, QVariantMap values) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    if(dbConnection.driverName() == "QIBASE") {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID)").arg(tableName).arg(fields).arg(vals);
    }
    QSqlQuery result = dbConnection.exec(query);
    qDebug() << result.executedQuery() << " > " << result.isValid() <<" "<< result.isActive();
    return (result.numRowsAffected() > 0);
}

/*!
         \details
         \fn SH_AppDatabase::execInsertReturningQuery TODO comment this
        */
QVariant SH_DatabaseManager::execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    if(dbConnection.driverName() == "QIBASE") {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID) RETURNING %4").arg(tableName).arg(fields).arg(vals).arg(returningField);
    }
    QSqlQuery result = dbConnection.exec(query);
    qDebug() << result.executedQuery() << " > " << result.isValid() <<" "<< result.isActive();
    if(result.next()) {
        QSqlRecord rec = result.record();
        if(!rec.isEmpty()  && result.isValid()) {
            return rec.value(rec.indexOf(returningField));
        }
    }
    return QVariant();
}

/*!
         \details
         \fn SH_divideQVariantMap TODO comment this
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
            vals += "'"+dateVal.toString()+"'',"; /*FIXME adapt date format*/
        }
        QDateTime dateTimeVal = val.toDateTime();
        if(dateTimeVal.isValid()) {
            vals += "'"+dateTimeVal.toString()+"'',"; /*FIXME adapt datetime format*/
        }
        QString stringVal = val.toString();
        vals += "'"+stringVal+"'',";
    }
    fields = fields.left(fields.lastIndexOf(',')-1);
    vals = vals.left(vals.lastIndexOf(',')-1);
}

