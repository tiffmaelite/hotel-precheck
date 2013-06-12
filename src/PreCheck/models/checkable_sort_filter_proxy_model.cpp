#include "checkable_sort_filter_proxy_model.h"
#include <QtSql/QSqlRecord>
#include "views/message_manager.h"
#include <QDebug>


/*!
 \brief

 \fn CheckableSortFilterProxyModel::CheckableSortFilterProxyModel
 \param parent
*/
CheckableSortFilterProxyModel::CheckableSortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    this->setDynamicSortFilter(false);
    this->model = new SqlDataModel(parent);
    this->setSourceModel(this->model);
    this->sortIndex = 0;
    //connect(this->model, tableChanged(), tableName());
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::replaceSet
 \param originalSet
 \param newSet
*/
void CheckableSortFilterProxyModel::replaceSet(QList<int>& originalSet, QList<int> newSet) {
    originalSet.clear();
    foreach(int col, newSet) {
        if(!originalSet.contains(col)) {
            originalSet.append(col);
        }
    }
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setBooleanColumns
 \param boolCols
*/
void CheckableSortFilterProxyModel::setBooleanColumns(QList<int> boolCols) {
    replaceSet(this->booleanSet, boolCols);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setReadOnlyColumns
 \param readonlyCols
*/
void CheckableSortFilterProxyModel::setReadOnlyColumns(QList<int> readonlyCols) {
    replaceSet(this->readonlySet, readonlyCols);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setPasswordColumns
 \param passwordCols
*/
void CheckableSortFilterProxyModel::setPasswordColumns(QList<int> passwordCols) {
    replaceSet(this->passwordSet, passwordCols);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setNullColumns
 \param nullCols
*/
void CheckableSortFilterProxyModel::setNullColumns(QList<int> nullCols) {
    if (sourceModel()->inherits("QSqlQueryModel")) {
        replaceSet(this->nullSet, nullCols);
    }
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setNotNullColumns
 \param notNullCols
*/
void CheckableSortFilterProxyModel::setNotNullColumns(QList<int> notNullCols) {
    if (sourceModel()->inherits("QSqlQueryModel")) {
        replaceSet(this->notNullSet, notNullCols);
    }
}


/*!
 \brief

 \fn CheckableSortFilterProxyModel::filterAcceptsRow
 \param source_row
 \param source_parent
 \return bool
*/
bool CheckableSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent);

    if (!this->notNullSet.isEmpty())
    {
        QSqlQueryModel *m = static_cast<QSqlQueryModel *>(sourceModel());
        foreach(int column, this->notNullSet)
        {
            if (m->record(source_row).isNull(column))
            {
                return false;
            }
        }
    }

    if (!this->nullSet.isEmpty())
    {
        QSqlQueryModel *m = static_cast<QSqlQueryModel *>(sourceModel());
        foreach(int column, this->nullSet)
        {
            if (!m->record(source_row).isNull(column))
            {
                return false;
            }
        }
    }
    return true;
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::data
 \param index
 \param role
 \return QVariant
*/
QVariant CheckableSortFilterProxyModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        if (this->booleanSet.contains(role))
        {
            return index.data(Qt::EditRole).toBool() ? QVariant(Qt::Checked) : QVariant(Qt::Unchecked);
        }
        else if (this->passwordSet.contains(role))
        {
            return QVariant("***");
        }
        else if(!this->filters.contains(role))
        {
            QModelIndex source_index = QSortFilterProxyModel::mapToSource(index);
            if (source_index.isValid()) {
                return this->model->data(source_index, role);
            }
        }
    }
    return QVariant();
}


/*!
 \brief

 \fn CheckableSortFilterProxyModel::setData
 \param index
 \param value
 \param role
 \return bool
*/
bool CheckableSortFilterProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    if (this->booleanSet.contains(role))
    {
        QVariant data = (value.toInt() == Qt::Checked) ? QVariant(1) : QVariant(0);
        return QSortFilterProxyModel::setData(index, data, role);
    }
    else
    {
        return QSortFilterProxyModel::setData(index, value, role);
    }

}


/*!
 \brief

 \fn CheckableSortFilterProxyModel::flags
 \param index
 \return Qt::ItemFlags
*/
Qt::ItemFlags CheckableSortFilterProxyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    if (!this->booleanSet.isEmpty())
    {
        return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    }
    else if (!this->readonlySet.isEmpty())
    {
        return Qt::ItemIsSelectable;
    }
    else
    {
        return QSortFilterProxyModel::flags(index);
    }

}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::invalidateFilter
*/
void CheckableSortFilterProxyModel::invalidateFilter()
{
    this->filters.clear();
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::removeFilterKeyColumn
 \param column
*/
void CheckableSortFilterProxyModel::removeFilterKeyColumn(int column)
{
    this->filters.removeAt(this->filters.indexOf(column));
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::containsFilterKeyColumn
 \param column
 \return bool
*/
bool CheckableSortFilterProxyModel::containsFilterKeyColumn(int column)
{
    return this->filters.contains(column);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::sort
 \param column
 \param newOrder
*/
void CheckableSortFilterProxyModel::sort(int column, Qt::SortOrder newOrder)
{
    this->model->field(column)->setSortOrder(newOrder);
    CheckableSortFilterProxyModel::setSortKeyColumn(column);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::setSortKeyColumn
 \param column
*/
void CheckableSortFilterProxyModel::setSortKeyColumn(int column)
{
    this->sortIndex = column;
    QSortFilterProxyModel::setSortRole(this->model->roleForField(column));
    QSortFilterProxyModel::sort(0, this->model->field(column)->sortOrder());
    emit sortChanged();
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::addFilterKeyColumn
 \param column
*/
void CheckableSortFilterProxyModel::addFilterKeyColumn(int column)
{
    this->filters.append(column);
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::data
 \param row
 \param column
 \return QVariant
*/
QVariant CheckableSortFilterProxyModel::data(int row, int column) const
{
    QModelIndex modelIndex = this->index(row, 0);
    return this->data(modelIndex, this->model->roleForField(column));
}

/*!
 \brief

 \fn CheckableSortFilterProxyModel::fetch
 \param tableName
 \param filter
 \param sort
 \param fields
 \return bool
*/
bool CheckableSortFilterProxyModel::fetch(QString tableName, QString filter, QString sort, QStringList fields)
{
    bool fetched = this->model->fetch(tableName, filter, sort, fields);
    if (fetched)
    {
        this->fillModel();
    }
    this->setSourceModel(this->model);
    return fetched;
}



