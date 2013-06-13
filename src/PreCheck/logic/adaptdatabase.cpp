#include "adaptdatabase.h"
#include <QtCore>
#include "models/database_manager.h"

/*!
 \brief
 \fn adaptDatabase::adaptDatabase TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
adaptDatabase::adaptDatabase(QString name, QState *parent) :
    GenericState(name, parent)
{
}

/*!
 \brief
 \fn adaptDatabase::insertUpdate TODO comment this
 \param table TODO comment this
 \param content TODO comment this
 \return bool TODO comment this
*/
QVariant adaptDatabase::insertUpdate(QString table, QVariantMap content)
{
    QVariant id = AppDatabase::getInstance()->execInsertReturningQuery(table, content, "id");
    if(id.isValid()) {
        emit next();
    }
    return id;
}
