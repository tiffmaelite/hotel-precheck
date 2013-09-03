#include "SH_AdaptDatabaseState.h"
#include "SH_MessageManager.h"
#include "SH_DatabaseManager.h"
#include <QtSql>
#include <QtCore>
/*namespace SimplHotel
{*/
/*!
 * \details \~french Construit une instance de la classe SH_AdaptDatabaseState
 * \fn SH_AdaptDatabaseState::SH_AdaptDatabaseState
*/
SH_AdaptDatabaseState::SH_AdaptDatabaseState(QString name, QState *parent) :
    SH_GenericState(name, parent)
{
}
/*!
 * \details \~french Enregistre dans la base de données les valeurs données, sous forme d'une insertion ou d'une mise à jour, selon le besoin
 * \fn SH_AdaptDatabaseState::insertUpdate
*/
QVariant SH_AdaptDatabaseState::insertUpdate(QString table, QMultiMap<QString, QVariant> content)
{
    QVariant id;
    if(!content.isEmpty()) {
        foreach(QVariant io, content) {
            SH_MessageManager::debugMessage(QString("%L1 : %L2").arg(content.key(io)).arg(io.toString()));
        }
        id = SH_DatabaseManager::getInstance()->execInsertReturningQuery(table, content, "id");
        if(id.isValid()) {
            SH_MessageManager::debugMessage(QString("Nouvel upsert réussi dans la base de données pour la table : %1").arg(table));
            emit goNext();
        } else {
            SH_MessageManager::debugMessage("upsert échoué");
        }
    } else {
        SH_MessageManager::debugMessage("nothing to upsert");
    }
    return id;
}
/*}*/
