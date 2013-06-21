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
 *\brief \~french  dbDriverStr
 */
static const QString dbDriverStr = "QIBASE";
/*!
 *\brief \~french  dbFileNameStr
 */
static const QString dbFileNameStr = "PreCheckDB.fdb";
/*!
 *\brief \~french  dbAliasNameStr
 */
static const QString dbAliasNameStr = "precheck-hotel";
/*!
 *\brief \~french  dbUsernameStr
 */
static const QString dbUsernameStr = "SYSDBA";
/*!
 *\brief \~french  dbPasswordStr
 */
static const QString dbPasswordStr = "masterkey";

/*!
 *\brief \~french  dbFolderPathStr
 */
static const QString dbFolderPathStr = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/");
/*!
 *\brief \~french  dbFilePathStr
 */
static const QString dbFilePathStr = QString("%1/%2").arg(dbFolderPathStr).arg(dbFileNameStr);


/*
 * GUI string messages.
 */
/*!
 *\brief \~french  dbDriverNotExistStr
 */
static QString dbDriverNotExistStr = QObject::tr("%1 database driver is not available.").arg(dbDriverStr);
/*!
 *\brief \~french  dbCannotOpenStr
 */
static QString dbCannotOpenStr = QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr);



/*!
\brief \~french 

 \class SH_AppDatabase database_manager.h "models/database_manager.h"
*/
class SH_DatabaseManager: public QObject
{
    Q_OBJECT
    private:
        static SH_DatabaseManager *_instance;

        /*!
        \brief \~french 
         \fn SH_divideQVariantMap TODO comment this
         \param[in] values TODO comment this
         \param[ou] fields TODO comment this
         \param[ou] vals TODO comment this
        */
        void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
protected:

/*!
\brief \~french 

 \fn SH_AppDatabase
*/
        SH_DatabaseManager();
        /*!
         *\brief \~french  dbConnection
         */
        QSqlDatabase dbConnection;

    public:


        /*!
        \brief \~french 

         \fn SH_getInstance
         \return AppDatabase
        */
        static SH_DatabaseManager *getInstance();



        /*!
        \brief \~french 

         \fn SH_dbConnect
         \return bool
        */
        bool dbConnect();

        /*!
        \brief \~french 

         \fn SH_isConnected
         \return bool
        */
        bool isConnected();


        /*!
        \brief \~french 

         \fn SH_dbDisconnect
         \return bool
        */
        bool dbDisconnect();


        /*!
        \brief \~french 

         \fn SH_getDbConnection
         \return QSqlDatabase
        */
        QSqlDatabase getDbConnection();


        /*!
        \brief \~french 

         \fn SH_~AppDatabase
        */
        ~SH_DatabaseManager();
        /*!
        \brief \~french 

         \fn SH_tableExists
         \param tableName
         \return bool
        */
        bool tableExists(QString tableName);
        /*!
        \brief \~french 

         \fn SH_dataExists
         \param tableName
         \param filter
         \return int
        */
        int dataCount(QString tableName, QString filter);
        /*!
        \brief \~french 

         \fn SH_execQuery
         \param query
         \return QSqlQuery
        */
        QSqlQuery execSelectQuery(QString tableName, QStringList fields=QStringList("*"), QString condition="", QString ordering="");
        /*!
        \brief \~french 
         \fn SH_execReplaceQuery TODO comment this
         \param query TODO comment this
         \return bool TODO comment this
        */
        bool execReplaceQuery(QString tableName, QVariantMap values);
        /*!
        \brief \~french 
         \fn SH_execInsertReturningQuery TODO comment this
         \param query TODO comment this
         \param returningField TODO comment this
         \return QVariant TODO comment this
        */
        QVariant execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField);
};

#endif /* APPDATABASESINGLETON_H*/
