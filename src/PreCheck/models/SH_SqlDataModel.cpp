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
    SH_SqlQueryModel(parent)
{
}

/*!
 \details \~french
 \fn SH_SqlDataModel::setTableName
*/
void SH_SqlDataModel::setTableName(const QString &tableName)
{
    if (m_tableName.toUpper() != tableName.toUpper() && tableName != "")
    {
        m_tableName = tableName.toUpper();
        emit tableNameChanged();
    }
}


/*!
 \details \~french
 \fn SH_SqlDataModel::fetchQuery
*/
void SH_SqlDataModel::fetchQuery(QString tableName, QString filter, QString sort, QStringList fieldsList)
{
    if(!m_tableName.isEmpty() || !tableName.isEmpty()) {
        SH_MessageManager::debugMessage("Bienvenue dans fetch");
        //SH_MessageManager::debugMessage(m_tableName + " " + this->fieldsList().join(", ") + " " +m_condition + " " + m_order);
        this->setFields(fieldsList);
        this->setTableName(tableName);
        this->setFilterCondition(filter);
        this->setOrderBy(sort);
        //SH_MessageManager::debugMessage(m_tableName + " " + this->fieldsList().join(", ") + " " +filter + " " + sort);
        m_query = SH_DatabaseManager::getInstance()->execSelectQuery(this->tableName(), this->fieldsList(), this->filterCondition(), m_order);
    }
}
/*}*/
