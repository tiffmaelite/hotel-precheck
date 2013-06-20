#include "SH_AdaptDatabaseState.h"
#include "SH_DatabaseManager.h"
#include <QtCore>

/*!
 \brief
 \fn adaptDatabase::adaptDatabase TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
SH_AdaptDatabaseState::SH_AdaptDatabaseState(QString name, QState *parent) :
    SH_GenericState(name, parent)
{
}

/*!
 \brief
 \fn adaptDatabase::insertUpdate TODO comment this
 \param table TODO comment this
 \param content TODO comment this
 \return bool TODO comment this
*/
QVariant SH_AdaptDatabaseState::insertUpdate(QString table, QVariantMap content)
{
    QVariant id = SH_DatabaseManager::getInstance()->execInsertReturningQuery(table, content, "id");
    if(id.isValid()) {
        emit next();
    }
    return id;
}
