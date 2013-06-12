#include "databasesingleton.h"

AppDatabase * AppDatabase::_instance = 0;

AppDatabase* AppDatabase::getInstance() 
{
    if (_instance == 0) 
	{
        _instance = new AppDatabase;
    }
    return _instance;
}

AppDatabase::~AppDatabase()
{
    dbDisconnect();
}

AppDatabase::AppDatabase() 
{

    /*
     *Check the existence of the database driver.
     */
   if (!QSqlDatabase::isDriverAvailable (dbDriverStr))
    {
       /*
        *Gui message that informs that the driver does not exist
        */
       QMessageBox::critical(0,dbConnectErrorStr,dbDriverNotExistStr);

       exit(1);
   }

  /*
   *Connect to the database with the following driver.
   */
   dbConnection = QSqlDatabase::addDatabase(dbDriverStr);

   dbConnection.setDatabaseName(dbFileNameStr);
   dbConnect();

}

/*
 *connect to database
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
        QMessageBox::critical(0,dbConnectErrorStr,dbCannotOpenStr);

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
bool AppDatabase::dbDisconnect()
{
    /*
     *close database
     */
    dbConnection.close();
    return (!dbConnection.isOpen());
}



bool AppDatabase::isConnected()
{
   return dbConnection.isOpen();
}


QSqlDatabase AppDatabase::getDbConnection() {
	return dbConnection;
}