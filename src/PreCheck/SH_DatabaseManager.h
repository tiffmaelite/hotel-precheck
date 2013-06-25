#ifndef SH_DatabaseManagerSINGLETON_H
#define SH_DatabaseManagerSINGLETON_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QtCore>
/*namespace SimplHotel
{*/
/* declare DB driver and filename.
 */
/*!
 * \brief \~french dbDriverStr
 */
static const QString dbDriverStr = "QIBASE";
/*!
 * \brief \~french dbFileNameStr
 */
static const QString dbFileNameStr = "PreCheckDB.fdb";
/*!
 * \brief \~french dbAliasNameStr
 */
static const QString dbAliasNameStr = "precheck-hotel";
/*!
 * \brief \~french dbUsernameStr
 */
static const QString dbUsernameStr = "SYSDBA";
/*!
 * \brief \~french dbPasswordStr
 */
static const QString dbPasswordStr = "masterkey";

/*!
 * \brief \~french dbFolderPathStr
 */
static const QString dbFolderPathStr = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/");
/*!
 * \brief \~french dbFilePathStr
 */
static const QString dbFilePathStr = QString("%1/%2").arg(dbFolderPathStr).arg(dbFileNameStr);


/* GUI string messages.
 */
/*!
 * \brief \~french dbDriverNotExistStr
 */
static QString dbDriverNotExistStr = QObject::tr("%1 database driver is not available.").arg(dbDriverStr);
/*!
 * \brief \~french dbCannotOpenStr
 */
static QString dbCannotOpenStr = QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr);



/*!
 * \brief \~french
 * \class SH_SH_DatabaseManager
 * \headerfile database_manager.h "models/database_manager.h"
*/
class SH_DatabaseManager: public QObject
{
    Q_OBJECT
private:

    /*!
    * \brief _instance
    */
    static SH_DatabaseManager *_instance;


    /*!
    * \brief \~french
    * \fn divideQVariantMap
    * \param[in] values
    * \param[ou] fields
    * \param[ou] vals
    */
    void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
protected:

    /*!
    * \brief \~french
    * \fn SH_DatabaseManager
    */
    SH_DatabaseManager();


    /*!
    * \brief \~french dbConnection
    */
    QSqlDatabase dbConnection;

public:



    /*!
    * \brief \~french
    * \fn getInstance
    * \return SH_DatabaseManager
    */
    static SH_DatabaseManager *getInstance();




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
};
/*}*/
#endif /* SH_DatabaseManagerSINGLETON_H*/
