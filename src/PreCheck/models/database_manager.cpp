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
        dbConnection.setDatabaseName(dbFilePathStr + dbFileNameStr);
    }
    else
    {
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
int AppDatabase::dataExists(QString tableName, QString filter) {
    if(!tableName.isEmpty() && !filter.isEmpty()) {
        QString query = QString("SELECT COUNT(*) AS MATCH FROM %1 WHERE %2").arg(tableName).arg(filter);
        QSqlQuery result = execQuery(query);
        if(dbConnection.driver()->hasFeature(QSqlDriver::QuerySize)) {
            return result.size();
        } else {
            if(result.next()) {
                QSqlRecord rec = result.record();
                if(rec.isEmpty() || !result.isValid()) {
                    return 0;
                } else {
                    return rec.value(rec.indexOf("MATCH")).toInt();
                }
            } else {
                return 0;
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
QSqlQuery AppDatabase::execQuery(QString query) {
    return dbConnection.exec(query);
}
