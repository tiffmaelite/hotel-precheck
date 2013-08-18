#include <QDir>
#include <QDebug>
#include "SH_MessageManager.h"
#include <QtSql/QSqlDriver>
#include <QtCore>
#include "SH_SqlDataModel.h"
#include "SH_DatabaseManager.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french
 \fn SH_SqlDataModel::SqlDataModel
*/
SH_SqlDataModel::SH_SqlDataModel(QObject *parent) :
    SH_SqlQueryModel(parent), m_tableName("")
{
}

/*!
 \details \~french
 \fn SH_SqlDataModel::setTableName
*/
void SH_SqlDataModel::setTableName(const QString &tableName)
{
    if (this->m_tableName.toUpper() != tableName.toUpper() && tableName != "")
    {
        this->m_tableName = tableName.toUpper();
        emit tableNameChanged();
    }
}

void SH_SqlDataModel::fetchQuery() {
    this->fetchQuery("");
}

/*!
 \details \~french
 \fn SH_SqlDataModel::fetchQuery
*/
void SH_SqlDataModel::fetchQuery(QString tableName, QString filter, QString sort, QStringList fieldsList)
{
    if(!m_tableName.isEmpty() || !tableName.isEmpty()) {
        //SH_MessageManager::debugMessage("Bienvenue dans fetch");
        //SH_MessageManager::debugMessage(this->m_tableName + " " + this->fieldsList().join(", ") + " " +m_condition + " " + this->m_order);
        this->setFields(fieldsList);
        this->setTableName(tableName);
        this->setFilterCondition(filter);
        this->setOrderBy(sort);
        //SH_MessageManager::debugMessage(this->m_tableName + " " + this->fieldsList().join(", ") + " " +filter + " " + sort);
        this->m_query = SH_DatabaseManager::getInstance()->execSelectQuery(this->tableName(), this->fieldsList(), this->filterCondition(), this->m_order);
    }
}
/*}*/
