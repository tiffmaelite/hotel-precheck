#ifndef APPDATABASESINGLETON_H
#define APPDATABASESINGLETON_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QtCore>

/*
 * declare DB driver and filename.
 */
/*!
 * \brief dbDriverStr
 */
static const QString dbDriverStr = "QIBASE";
/*!
 * \brief dbFileNameStr
 */
static const QString dbFileNameStr = "PreCheckDB.fdb";
/*!
 * \brief dbAliasNameStr
 */
static const QString dbAliasNameStr = "precheck-hotel";
/*!
 * \brief dbUsernameStr
 */
static const QString dbUsernameStr = "SYSDBA";
/*!
 * \brief dbPasswordStr
 */
static const QString dbPasswordStr = "masterkey";

/*!
 * \brief dbFolderPathStr
 */
static const QString dbFolderPathStr = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/");
/*!
 * \brief dbFilePathStr
 */
static const QString dbFilePathStr = QString("%1/%2").arg(dbFolderPathStr).arg(dbFileNameStr);


/*
 * GUI string messages.
 */
/*!
 * \brief dbDriverNotExistStr
 */
static QString dbDriverNotExistStr = QObject::tr("%1 database driver is not available.").arg(dbDriverStr);
/*!
 * \brief dbCannotOpenStr
 */
static QString dbCannotOpenStr = QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr);



/*!
 \brief

 \class SH_AppDatabase database_manager.h "models/database_manager.h"
*/
class SH_DatabaseManager: public QObject
{
    Q_OBJECT
    private:
        static SH_DatabaseManager *_instance;

        /*!
         \brief
         \fn SH_divideQVariantMap TODO comment this
         \param[in] values TODO comment this
         \param[ou] fields TODO comment this
         \param[ou] vals TODO comment this
        */
        void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
protected:

/*!
 \brief

 \fn SH_AppDatabase
*/
        SH_DatabaseManager();
        /*!
         * \brief dbConnection
         */
        QSqlDatabase dbConnection;

    public:


        /*!
         \brief

         \fn SH_getInstance
         \return AppDatabase
        */
        static SH_DatabaseManager *getInstance();



        /*!
         \brief

         \fn SH_dbConnect
         \return bool
        */
        bool dbConnect();

        /*!
         \brief

         \fn SH_isConnected
         \return bool
        */
        bool isConnected();


        /*!
         \brief

         \fn SH_dbDisconnect
         \return bool
        */
        bool dbDisconnect();


        /*!
         \brief

         \fn SH_getDbConnection
         \return QSqlDatabase
        */
        QSqlDatabase getDbConnection();


        /*!
         \brief

         \fn SH_~AppDatabase
        */
        ~SH_DatabaseManager();
        /*!
         \brief

         \fn SH_tableExists
         \param tableName
         \return bool
        */
        bool tableExists(QString tableName);
        /*!
         \brief

         \fn SH_dataExists
         \param tableName
         \param filter
         \return int
        */
        int dataCount(QString tableName, QString filter);
        /*!
         \brief

         \fn SH_execQuery
         \param query
         \return QSqlQuery
        */
        QSqlQuery execSelectQuery(QString tableName, QStringList fields=QStringList("*"), QString condition="", QString ordering="");
        /*!
         \brief
         \fn SH_execReplaceQuery TODO comment this
         \param query TODO comment this
         \return bool TODO comment this
        */
        bool execReplaceQuery(QString tableName, QVariantMap values);
        /*!
         \brief
         \fn SH_execInsertReturningQuery TODO comment this
         \param query TODO comment this
         \param returningField TODO comment this
         \return QVariant TODO comment this
        */
        QVariant execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField);
};

#endif /* APPDATABASESINGLETON_H*/
