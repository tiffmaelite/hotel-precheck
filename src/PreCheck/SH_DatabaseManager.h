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
protected:

    static QString driverNameFromEnum(SH_DatabaseManager::dbDrivers driver) {
        switch(driver) {
        case InterbaseDriver: return dbInterbaseDriverStr; break;
        case FirebirdDriver: return dbFirebirdDriverStr; break;
        case PostgresqlDriver: return dbPostgresqlDriverStr; break;
        case MysqlDriver: return dbMysqlDriverStr; break;
        default: return "";
        }
    }

    static SH_DatabaseManager::dbDrivers driverEnumFromName(QString driver) {
        if(driver == dbInterbaseDriverStr) { return InterbaseDriver; }
        else if(driver == dbFirebirdDriverStr) { return FirebirdDriver; }
        else if(driver == dbPostgresqlDriverStr) { return PostgresqlDriver; }
        else if(driver == dbMysqlDriverStr) { return MysqlDriver; }
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
    static const QString dbFileNameStr;
    /*!
     * \brief \~french dbAliasNameStr
     */
    static const QString dbAliasNameStr;
    /*!
     * \brief \~french dbUsernameStr
     */
    static const QString dbUsernameStr;
    /*!
     * \brief \~french dbPasswordStr
     */
    static const QString dbPasswordStr;

    /*!
     * \brief \~french dbFolderPathStr
     */
    static const QString dbFolderPathStr;
    /*!
     * \brief \~french dbFilePathStr
     */
    static const QString dbFilePathStr;

    static const QString dbInterbaseDriverStr;
    static const QString dbFirebirdDriverStr;
    static const QString dbPostgresqlDriverStr;
    static const QString dbMysqlDriverStr;

    /*!
    * \brief \~french
    * \fn divideQVariantMap
    * \param[in] values
    * \param[ou] fields
    * \param[ou] vals
    */
    void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
};

/*}*/
#endif /* SH_DatabaseManagerSINGLETON_H*/
