#include "SH_DatabaseManager.h"

/*namespace SimplHotel
{*/

SH_DatabaseManager *SH_DatabaseManager::_instance = 0;

//SH_DatabaseManager::dbDrivers SH_DatabaseManager::_dbDriver = SH_DatabaseManager::FirebirdDriver;
//const QString SH_DatabaseManager::dbFileNameStr = "PreCheckDB.fdb";
SH_DatabaseManager::dbDrivers SH_DatabaseManager::_dbDriver = SH_DatabaseManager::PostgresqlDriver;

const int SH_DatabaseManager::mainDbPort = 5434;
const int SH_DatabaseManager::archivesDbPort = 5434;
const QString SH_DatabaseManager::mainDbHost = "/var/run/postgresql";
const QString SH_DatabaseManager::archivesDbHost = "/var/run/postgresql";
const QString SH_DatabaseManager::mainDbName = "precheckdb";
const QString SH_DatabaseManager::archivesDbName = "precheckdb";
const QString SH_DatabaseManager::mainDbAliasName = "precheck-hotel";
const QString SH_DatabaseManager::archivesDbAliasName = "archvives-hotel";

const QString SH_DatabaseManager::mainDbFolderPath = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/datas");
const QString SH_DatabaseManager::archivesDbFolderPath = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/datas");

const QString SH_DatabaseManager::mainDbUsername = "precheck";
const QString SH_DatabaseManager::mainDbPassword = "hotel";
/*}*/
