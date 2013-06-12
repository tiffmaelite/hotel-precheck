#ifndef APPDATABASESINGLETON_H
#define APPDATABASESINGLETON_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>


/*
 * declare DB driver and filename.
 */
static const QString dbDriverStr = "QIBASE"; /*!< TODO */
static const QString dbFilePathStr = "/home/tiff/Stage-IUT/app/QtQMLapp/src/PreCheck/"; /*!< TODO */
static const QString dbFileNameStr = "PreCheckDB.fbd"; /*!< TODO */
static const QString dbUsernameStr = "SYSDBA"; /*!< TODO */
static const QString dbPasswordStr = "masterkey"; /*!< TODO */

/*
 * GUI string messages.
 */
static QString dbDriverNotExistStr = QObject::tr("%1 database driver is not available.").arg(dbDriverStr); /*!< TODO */
static QString dbCannotOpenStr = QObject::tr("The database %1 cannot be opened.").arg(dbFilePathStr + /*!< TODO */ dbFileNameStr);





/*!
 \brief

 \class AppDatabase database_manager.h "models/database_manager.h"
*/
class AppDatabase: public QObject
{
    Q_OBJECT
    private:
        static AppDatabase *_instance; /*!< TODO */

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
        int dataExists(QString tableName, QString filter);
        /*!
         \brief

         \fn execQuery
         \param query
         \return QSqlQuery
        */
        QSqlQuery execQuery(QString query);
};

#endif // APPDATABASESINGLETON_H
