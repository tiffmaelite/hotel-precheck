#include "database_manager.h"
#include "views/message_manager.h"
#include <QDebug>
#include <QtSql>

AppDatabase *AppDatabase::_instance = 0; /*!< TODO */


/*!
 \brief

 \fn AppDatabase::getInstance
 \return AppDatabase
*/
AppDatabase *AppDatabase::getInstance()
{
    if (_instance == 0)
    {
        _instance = new AppDatabase;
    }
    qDebug() << dbFilePathStr;
    return _instance;
}


/*!
 \brief

 \fn AppDatabase::~AppDatabase
*/
AppDatabase::~AppDatabase()
{
    dbDisconnect();
}


/*!
 \brief

 \fn AppDatabase::AppDatabase
*/
AppDatabase::AppDatabase()
{
    /*
     *Check the existence of the database driver.
     */
    if (!QSqlDatabase::isDriverAvailable(dbDriverStr))
    {
        /*
        *Gui message that informs that the driver does not exist
        */
        MessageManager::errorMessage(dbDriverNotExistStr);
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
         \brief

         \fn AppDatabase::dbConnect
         \return bool
        */
bool AppDatabase::dbConnect()
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
        MessageManager::errorMessage(dbCannotOpenStr);
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
         \brief

         \fn AppDatabase::dbDisconnect
         \return bool
        */
bool AppDatabase::dbDisconnect()
{
    /*
             *close database
             */
    dbConnection.close();
    return (!dbConnection.isOpen());
}


/*!
         \brief

         \fn AppDatabase::isConnected
         \return bool
        */
bool AppDatabase::isConnected()
{
    return dbConnection.isOpen();
}


/*!
         \brief

         \fn AppDatabase::getDbConnection
         \return QSqlDatabase
        */
QSqlDatabase AppDatabase::getDbConnection()
{
    return dbConnection;
}

/*!
         \brief

         \fn AppDatabase::tableExists
         \param tableName
         \return bool
        */
bool AppDatabase::tableExists(QString tableName)
{
    return dbConnection.tables(QSql::Views).contains(tableName.toUpper(), Qt::CaseInsensitive) || dbConnection.tables(QSql::Tables).contains(tableName.toUpper(), Qt::CaseInsensitive);
}

/*!
         \brief

         \fn AppDatabase::dataExists
         \param tableName
         \param filter
         \return int
        */
int AppDatabase::dataCount(QString tableName, QString filter) {
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
         \brief

         \fn AppDatabase::execQuery
         \param query
         \return QSqlQuery
        */
QSqlQuery AppDatabase::execSelectQuery(QString tableName, QStringList fields, QString condition, QString ordering) {
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
    return dbConnection.exec(query);
}


/*!
         \brief
         \fn AppDatabase::execReplaceQuery TODO comment this
         \param query TODO comment this
         \return bool TODO comment this
        */
bool AppDatabase::execReplaceQuery(QString tableName, QVariantMap values) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    if(dbConnection.driverName() == "QIBASE") {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID)").arg(tableName).arg(fields).arg(vals);
    }
    QSqlQuery result = dbConnection.exec(query);
    return (result.numRowsAffected() > 0);
}

/*!
         \brief
         \fn AppDatabase::execInsertReturningQuery TODO comment this
         \param query TODO comment this
         \param returningField TODO comment this
         \return QVariant TODO comment this
        */
QVariant AppDatabase::execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField) {
    QString fields;
    QString vals;
    divideQVariantMap(values, fields, vals);
    QString query;
    if(dbConnection.driverName() == "QIBASE") {
        query = QString("UPDATE OR INSERT INTO %1(%2) VALUES(%3) MATCHING(ID) RETURNING %4").arg(tableName).arg(fields).arg(vals).arg(returningField);
    }
    QSqlQuery result = dbConnection.exec(query);
    if(result.next()) {
        QSqlRecord rec = result.record();
        if(!rec.isEmpty()  && result.isValid()) {
            return rec.value(rec.indexOf(returningField));
        }
    }
    return QVariant();
}

/*!
         \brief
         \fn divideQVariantMap TODO comment this
         \param values TODO comment this
         \param fields TODO comment this
         \param vals TODO comment this
        */
void AppDatabase::divideQVariantMap(QVariantMap values, QString& fields, QString& vals) {
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
            vals += "'"+dateVal.toString()+"'',"; //FIXME adapt date format
        }
        QDateTime dateTimeVal = val.toDateTime();
        if(dateTimeVal.isValid()) {
            vals += "'"+dateTimeVal.toString()+"'',"; //FIXME adapt datetime format
        }
        QString stringVal = val.toString();
        vals += "'"+stringVal+"'',";
    }
    fields = fields.left(fields.lastIndexOf(',')-1);
    vals = vals.left(vals.lastIndexOf(',')-1);
}

