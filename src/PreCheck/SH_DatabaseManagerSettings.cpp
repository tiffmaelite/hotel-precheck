#include "SH_DatabaseManager.h"

/*namespace SimplHotel
{*/

SH_DatabaseManager *SH_DatabaseManager::_instance = 0;

SH_DatabaseManager::dbDrivers SH_DatabaseManager::_dbDriver = SH_DatabaseManager::FirebirdDriver;
const QString SH_DatabaseManager::dbFileNameStr = "PreCheckDB.fdb";
//SH_DatabaseManager::dbDrivers SH_DatabaseManager::_dbDriver = SH_DatabaseManager::PostgresqlDriver;
//const QString SH_DatabaseManager::dbFileNameStr = "PreCheck.pdb";

const QString SH_DatabaseManager::dbAliasNameStr = "precheck-hotel";
const QString SH_DatabaseManager::dbUsernameStr = "precheck";
const QString SH_DatabaseManager::dbPasswordStr = "hotel";
const QString SH_DatabaseManager::dbFolderPathStr = QDir::cleanPath(QDir::currentPath()+"/../../../src/Database/");
/*}*/
