#ifndef APPDATABASESINGLETON_H
#define APPDATABASESINGLETON_H
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>

#include "fileHandler.h"

/*
 * declare DB driver and filename.
 */
static const QString dbDriverStr = "QODBC";
static const QString dbFileNameStr = "PreCheck.db";

/*
 * GUI string messages.
 */
static QString dbConnectErrorStr = 
       QObject::tr("Database Connection Error");
static QString dbDriverNotExistStr = 
       QObject::tr("ODBC database driver is not available.");
static QString dbCannotOpenStr = 
       QObject::tr("The database cannot open."); 

class AppDatabase
{
  private:
    static AppDatabase * _instance;

  protected:
    AppDatabase();

    QSqlDatabase dbConnection;
    FileHandler dbFile;

  public:
    static AppDatabase * getInstance();

    bool dbConnect();
    bool isConnected();
    bool dbDisconnect();
	QSqlDatabase getDbConnection();
    ~AppDatabase();
};

#endif // APPDATABASESINGLETON_H
