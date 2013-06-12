#include "my_sql_relational_table_model.h"
#include "database_manager.h"
#include <QtSql/QSqlRecord>


QQuickRelationalTableModel::QQuickRelationalTableModel(QString tableName, QString filter, QObject *parent):
    QSqlRelationalTableModel(parent, AppDatabase::getInstance()->getDbConnection())
{
    if(tableName != "") {
        this->init(tableName, filter);
    }
}

void QQuickRelationalTableModel::init(QString tableName, QString filter) {
    this->setTable(tableName);
    if (filter != "")
    {
        this->setFilter(filter);
    }
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
}


bool QQuickRelationalTableModel::select()
{
    this->applyRoles();
    return QSqlRelationalTableModel::select();
}

QSqlRecord QQuickRelationalTableModel::record(int row) const
{
    QSqlTableModel mod;
    QSqlRecord rec = QSqlQueryModel::record(row);

    mod.setTable(tableName());
    mod.select();
    mod.setFilter(QString("idxxx = %2").arg(rec.value("idxxx").toInt()));

    return mod.record(0);
}



QVariant QQuickRelationalTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value;
    if (role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}



void QQuickRelationalTableModel::applyRoles()
{
    roles.clear();
    for (int i = 0; i < this->columnCount(); i++)
    {
        QString role = this->headerData(i, Qt::Horizontal).toString();
        roles[Qt::UserRole + i + 1] = QVariant(role).toByteArray();
    }
    //setRoleNames(roles);
}
