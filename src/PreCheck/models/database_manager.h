#ifndef APPDATABASESINGLETON_H
#define APPDATABASESINGLETON_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>
#include <QtCore>
#include <QApplication>

/*
 * declare DB driver and filename.
 */
static const QString dbDriverStr = "QIBASE"; /*!< TODO */
static const QString dbFileNameStr = "PreCheckDB.fdb"; /*!< TODO */
static const QString dbAliasNameStr = "precheck-hotel"; /*!< TODO */
static const QString dbUsernameStr = "SYSDBA"; /*!< TODO */
static const QString dbPasswordStr = "masterkey"; /*!< TODO */


static const QString dbFolderPathStr = QDir::cleanPath(QApplication::applicationDirPath()+"/src/Database/"); /*!< TODO */
static const QString dbFilePathStr = QString("%1/%2").arg(dbFolderPathStr).arg(dbFileNameStr); /*!< TODO */


/*
 * GUI string messages.
 */
static QString dbDriverNotExistStr = QObject::tr("%1 database driver is not available.").arg(dbDriverStr); /*!< TODO */
static QString dbCannotOpenStr = QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr); /*!< TODO */





/*!
 \brief

 \class AppDatabase database_manager.h "models/database_manager.h"
*/
class AppDatabase: public QObject
{
    Q_OBJECT
    private:
        static AppDatabase *_instance; /*!< TODO */

        /*!
         \brief
         \fn divideQVariantMap TODO comment this
         \param[in] values TODO comment this
         \param[ou] fields TODO comment this
         \param[ou] vals TODO comment this
        */
        void divideQVariantMap(QVariantMap values, QString &fields, QString &vals);
protected:

/*!
 \brief

 \fn AppDatabase
*/
        AppDatabase();

        QSqlDatabase dbConnection; /*!< TODO */

    public:


        /*!
         \brief

         \fn getInstance
         \return AppDatabase
        */
        static AppDatabase *getInstance();



        /*!
         \brief

         \fn dbConnect
         \return bool
        */
        bool dbConnect();

        /*!
         \brief

         \fn isConnected
         \return bool
        */
        bool isConnected();


        /*!
         \brief

         \fn dbDisconnect
         \return bool
        */
        bool dbDisconnect();


        /*!
         \brief

         \fn getDbConnection
         \return QSqlDatabase
        */
        QSqlDatabase getDbConnection();


        /*!
         \brief

         \fn ~AppDatabase
        */
        ~AppDatabase();
        /*!
         \brief

         \fn tableExists
         \param tableName
         \return bool
        */
        bool tableExists(QString tableName);
        /*!
         \brief

         \fn dataExists
         \param tableName
         \param filter
         \return int
        */
        int dataCount(QString tableName, QString filter);
        /*!
         \brief

         \fn execQuery
         \param query
         \return QSqlQuery
        */
        QSqlQuery execSelectQuery(QString tableName, QStringList fields=QStringList("*"), QString condition="", QString ordering="");
        /*!
         \brief
         \fn execReplaceQuery TODO comment this
         \param query TODO comment this
         \return bool TODO comment this
        */
        bool execReplaceQuery(QString tableName, QVariantMap values);
        /*!
         \brief
         \fn execInsertReturningQuery TODO comment this
         \param query TODO comment this
         \param returningField TODO comment this
         \return QVariant TODO comment this
        */
        QVariant execInsertReturningQuery(QString tableName, QVariantMap values, QString returningField);
};

#endif // APPDATABASESINGLETON_H
