#include "SH_AdaptDatabaseState.h"
#include "SH_DatabaseManager.h"
#include <QtCore>

/*!
 \details
 \fn SH_adaptDatabase::adaptDatabase TODO comment this
*/
SH_AdaptDatabaseState::SH_AdaptDatabaseState(QString name, QState *parent) :
    SH_GenericState(name, parent)
{
}

/*!
 \details
 \fn SH_adaptDatabase::insertUpdate TODO comment this
*/
QVariant SH_AdaptDatabaseState::insertUpdate(QString table, QVariantMap content)
{
    QVariant id = SH_DatabaseManager::getInstance()->execInsertReturningQuery(table, content, "id");
    if(id.isValid()) {
        emit next();
    }
    return id;
}
