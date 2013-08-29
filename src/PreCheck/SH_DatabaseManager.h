#ifndef SH_DatabaseManagerSINGLETON_H
#define SH_DatabaseManagerSINGLETON_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QtCore>
/*namespace SimplHotel
{*/

/*!
 * \brief \~french
 * \class SH_DatabaseManager
 * \headerfile database_manager.h "models/database_manager.h"
*/
class SH_DatabaseManager: public QObject
{
    Q_OBJECT
    Q_ENUMS(dbDrivers)

public:
    enum dbDrivers { InterbaseDriver, FirebirdDriver, PostgresqlDriver, MysqlDriver};


    /*!
* \brief \~french
* \fn getInstance
* \return SH_DatabaseManager
*/
    static SH_DatabaseManager *getInstance();

    static void setDriver(SH_DatabaseManager::dbDrivers driver);

    QSqlDriver *dbDriver();

    /*!
* \brief \~french
* \fn dbConnect
* \return bool
*/
    bool dbConnect();


    /*!
* \brief \~french
* \fn isConnected
* \return bool
*/
    bool isConnected();



    /*!
* \brief \~french
* \fn dbDisconnect
* \return bool
*/
    bool dbDisconnect();



    /*!
* \brief \~french
* \fn getDbConnection
* \return QSqlDatabase
*/
    QSqlDatabase getDbConnection();



    /*!
* \brief \~french
* \fn ~SH_DatabaseManager
*/
    ~SH_DatabaseManager();


    /*!
* \brief \~french
* \fn tableExists
* \param tableName
* \return bool
*/
    bool tableExists(QString tableName);


    /*!
* \brief \~french
* \fn dataExists
* \param tableName
* \param filter
* \return int
*/
    int dataCount(QString tableName, QString filter);


    /*!
* \brief \~french
* \fn execQuery
* \param query
* \return QSqlQuery
*/
    QSqlQuery execSelectQuery(QString tableName, QStringList fields=QStringList("*"), QString condition="", QString ordering="");


    /*!
* \brief \~french
* \fn execReplaceQuery
* \param query
* \return bool
*/
    bool execReplaceQuery(QString tableName, QVariantMap values);


    /*!
* \brief \~french
* \fn execInsertReturningQuery
* \param query
* \param returningField
* \return QVariant
*/
    QVariant execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField);

    QString dbDriverName();

    dbDrivers dbDriverLabel();
    QSqlQuery execProcedure(QString procedureCall);

protected:

    static QString driverNameFromEnum(SH_DatabaseManager::dbDrivers driver) {
        switch(driver) {
        case InterbaseDriver: return dbInterbaseDriver; break;
        case FirebirdDriver: return dbFirebirdDriver; break;
        case PostgresqlDriver: return dbPostgresqlDriver; break;
        case MysqlDriver: return dbMysqlDriver; break;
        default: return "";
        }
    }

    static SH_DatabaseManager::dbDrivers driverEnumFromName(QString driver) {
        if(driver == dbInterbaseDriver) { return InterbaseDriver; }
        else if(driver == dbFirebirdDriver) { return FirebirdDriver; }
        else if(driver == dbPostgresqlDriver) { return PostgresqlDriver; }
        else if(driver == dbMysqlDriver) { return MysqlDriver; }
    }

    /*!
    * \brief \~french dbConnection
    */
    QSqlDatabase dbConnection;

    bool checkDriver();
    void addDatabase();
private:
    /*!
    * \brief _instance
    */
    static SH_DatabaseManager *_instance;

    static SH_DatabaseManager::dbDrivers _dbDriver;

    /*!
    * \brief \~french
    * \fn SH_DatabaseManager
    */
    SH_DatabaseManager();

    /* declare DB filename and path.
     */

    /*!
     * \brief \~french dbFileNameStr
     */
    static const QString mainDbName;
    /*!
     * \brief \~french dbAliasNameStr
     */
    static const QString mainDbAliasName;
    /*!
     * \brief \~french dbUsernameStr
     */
    static const QString mainDbUsername;
    /*!
     * \brief \~french dbPasswordStr
     */
    static const QString mainDbPassword;

    static const QString mainDbHost;
    static const int mainDbPort;
    /*!
     * \brief \~french dbFolderPathStr
     */
    static const QString mainDbFolderPath;
    /*!
     * \brief \~french dbFilePathStr
     */
    static const QString mainDbFilePath;



    /*!
     * \brief \~french dbFileNameStr
     */
    static const QString archivesDbName;
    /*!
     * \brief \~french dbAliasNameStr
     */
    static const QString archivesDbAliasName;
    /*!
     * \brief \~french dbUsernameStr
     */
    static const QString archivesDbUsername;
    /*!
     * \brief \~french dbPasswordStr
     */
    static const QString archivesDbPassword;

    static const QString archivesDbHost;
    static const int archivesDbPort;
    /*!
     * \brief \~french dbFolderPathStr
     */
    static const QString archivesDbFolderPath;
    /*!
     * \brief \~french dbFilePathStr
     */
    static const QString archivesDbFilePath;


    static const QString dbInterbaseDriver;
    static const QString dbFirebirdDriver;
    static const QString dbPostgresqlDriver;
    static const QString dbMysqlDriver;

    /*!
    * \brief \~french
    * \fn divideQVariantMap
    * \param[in] values
    * \param[ou] fields
    * \param[ou] vals
    */
    void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
    QString qVariantMapToHStore(QVariantMap values);
};

/*}*/
#endif /* SH_DatabaseManagerSINGLETON_H*/
