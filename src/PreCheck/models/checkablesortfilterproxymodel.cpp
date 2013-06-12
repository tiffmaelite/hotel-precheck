#include "checkablesortfilterproxymodel.h"
#include <QtSql/QSqlRecord>

CheckableSortFilterProxyModel::CheckableSortFilterProxyModel(QString tableName, QString filter, QObject *parent) :
    QSortFilterProxyModel(parent)
{
    this->m_model = new QQuickRelationalTableModel(tableName, filter, parent);
}

QQuickRelationalTableModel *CheckableSortFilterProxyModel::model() const
{
    return m_model;
}

void CheckableSortFilterProxyModel::setModel(QQuickRelationalTableModel *m)
{
    m_model = m;
}

void CheckableSortFilterProxyModel::validate() {
    setSourceModel(this->m_model);
}

void CheckableSortFilterProxyModel::setParameters(QList<int> boolCols, QList<int> readonlyCols, QList<int> passwordCols) {
    booleanSet.clear();
    readonlySet.clear();
    passwordSet.clear();

    if (!boolCols.isEmpty())        {
        foreach(int column , boolCols)     {
            booleanSet.append(column);
        }
    }
    if (!readonlyCols.isEmpty())    {
        foreach(int column , readonlyCols) {
            readonlySet.append(column);
        }
    }
    if (!passwordCols.isEmpty())    {
        foreach(int column , passwordCols) {
            passwordSet.append(column);
        }
    }

}


void CheckableSortFilterProxyModel::setNullAndNotNullColumns(QList<int> nullCols, QList<int> notNullCols) {
    notNullSet.clear();
    nullSet.clear();

    if (!notNullCols.isEmpty()) {
        // this only works when our model is a QSqlQueryModel subclass
        if (sourceModel()->inherits("QSqlQueryModel")) {
            foreach(int column , notNullCols) { notNullSet.append(column); }
        }
        invalidateFilter();
    }

    if (!nullCols.isEmpty()) {
        // this only works when our model is a QSqlQueryModel subclass
        if (sourceModel()->inherits("QSqlQueryModel")) {
            foreach(int column , nullCols) { nullSet.append(column); }
        }
        invalidateFilter();
    }
}

bool CheckableSortFilterProxyModel::filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const {
    Q_UNUSED(source_parent);

    if (!notNullSet.isEmpty()) {
        QSqlQueryModel *m = static_cast<QSqlQueryModel*>(sourceModel());
        foreach (int column, notNullSet) {
            if (m->record(source_row).isNull(column)) {
                return false;
            }
        }
    }

    if (!nullSet.isEmpty()) {
        QSqlQueryModel *m = static_cast<QSqlQueryModel*>(sourceModel());
        foreach (int column, nullSet) {
            if (!m->record(source_row).isNull(column)) {
                return false;
            }
        }
    }
    return true;
}


QVariant CheckableSortFilterProxyModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }
    if (booleanSet.contains(index.column()) && (role == Qt::CheckStateRole || role == Qt::DisplayRole)) {
        if (role == Qt::CheckStateRole) {
            return index.data(Qt::EditRole).toBool() ? QVariant(Qt::Checked) : QVariant(Qt::Unchecked);
        } else if (role == Qt::DisplayRole) {
            return QVariant();
        }
    }  else if (passwordSet.contains(index.column()) && (role == Qt::DisplayRole)) {
        return QVariant("***");
    } else {
        return QSortFilterProxyModel::data(index,role);
    }


    return QVariant();
}

bool CheckableSortFilterProxyModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(!index.isValid())
        return false;

    if(booleanSet.contains(index.column()) && role==Qt::CheckStateRole)
    {
        QVariant data = (value.toInt()==Qt::Checked) ? QVariant(1) : QVariant (0);
        return QSortFilterProxyModel::setData(index, data, Qt::EditRole);
    }
    else {
        return QSortFilterProxyModel::setData(index,value,role);
    }

}

Qt::ItemFlags CheckableSortFilterProxyModel::flags ( const QModelIndex & index ) const {
    if(!index.isValid()) {
        return Qt::ItemIsEnabled;
    }
    if (booleanSet.contains(index.column())) {
        return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    } else if (readonlySet.contains(index.column())) {
        return Qt::ItemIsSelectable;
    } else {
        return QSortFilterProxyModel::flags(index);
    }

}
