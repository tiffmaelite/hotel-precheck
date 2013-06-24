#include "SH_AdaptDatabaseState.h"
#include "SH_DatabaseManager.h"
#include <QtCore>

/*!
\details \~french Construit une instance de la classe SH_AdaptDatabaseState
 \fn SH_AdaptDatabaseState::SH_AdaptDatabaseState
*/
SH_AdaptDatabaseState::SH_AdaptDatabaseState(QString name, QState *parent) :
    SH_GenericState(name, parent)
{
}

/*!
 \details \~french Enregistre dans la base de données les valeurs données, sous forme d'une insertion ou d'une mise à jour, selon le besoin
 \fn SH_AdaptDatabaseState::insertUpdate
*/
QVariant SH_AdaptDatabaseState::insertUpdate(QString table, QVariantMap content)
{
    QVariant id = SH_DatabaseManager::getInstance()->execInsertReturningQuery(table, content, "id");
    if(id.isValid()) {
        emit goNext();
    }
    return id;
}
