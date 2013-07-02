#include <QtSql/QSqlRecord>
#include <QDebug>
#include "SH_ExtendedSqlProxyModel.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ExtendedProxyModel::CheckableSortFilterProxyModel
*/
SH_ExtendedProxyModel::SH_ExtendedProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    this->setDynamicSortFilter(false);
    this->model = new SH_SqlDataModel(parent);
    this->setSourceModel(this->model);
    this->sortIndex = 0;

    /*connect(this->model, tableChanged(), tableName());*/
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::replaceSet
*/
void SH_ExtendedProxyModel::replaceSet(QList<int>& originalSet, QList<int> newSet) {
    originalSet.clear();
    foreach(int col, newSet) {
        if(!originalSet.contains(col)) {
            originalSet.append(col);
        }
    }
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setBooleanColumns
*/
void SH_ExtendedProxyModel::setBooleanColumns(QList<int> boolCols) {
    replaceSet(this->booleanSet, boolCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setReadOnlyColumns
*/
void SH_ExtendedProxyModel::setReadOnlyColumns(QList<int> readonlyCols) {
    replaceSet(this->readonlySet, readonlyCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setPasswordColumns
*/
void SH_ExtendedProxyModel::setPasswordColumns(QList<int> passwordCols) {
    replaceSet(this->passwordSet, passwordCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setNullColumns
*/
void SH_ExtendedProxyModel::setNullColumns(QList<int> nullCols) {
    if (sourceModel()->inherits("QSqlQueryModel")) {
        replaceSet(this->nullSet, nullCols);
    }
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setNotNullColumns
 \param notNullCols
*/
void SH_ExtendedProxyModel::setNotNullColumns(QList<int> notNullCols) {
    if (sourceModel()->inherits("QSqlQueryModel")) {
        replaceSet(this->notNullSet, notNullCols);
    }
}


/*!
 \details \~french

 \fn SH_ExtendedProxyModel::filterAcceptsRow
*/
bool SH_ExtendedProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
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
 \details \~french

 \fn SH_ExtendedProxyModel::data
*/
QVariant SH_ExtendedProxyModel::data(const QModelIndex &index, int role) const
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
        else if(!this->hiddenSet.contains(role))
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
 \details \~french

 \fn SH_ExtendedProxyModel::setData
*/
bool SH_ExtendedProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
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
 \details \~french

 \fn SH_ExtendedProxyModel::flags
*/
Qt::ItemFlags SH_ExtendedProxyModel::flags(const QModelIndex &index) const
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
 \details \~french

 \fn SH_ExtendedProxyModel::invalidateFilter
*/
void SH_ExtendedProxyModel::invalidateFilter()
{
    this->resetColumnsList();
}

void SH_ExtendedProxyModel::resetColumnsList()
{
    this->hiddenSet.clear();
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::removeFilterKeyColumn
*/
void SH_ExtendedProxyModel::removeFilterKeyColumn(int column)
{
    this->addHiddenColumn(column);
}

void SH_ExtendedProxyModel::showHiddenColumn(int column)
{
    this->hiddenSet.removeAt(this->hiddenSet.indexOf(column));
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::containsFilterKeyColumn
*/
bool SH_ExtendedProxyModel::containsFilterKeyColumn(int column)
{
    return !this->isHidingColumn(column);
}

bool SH_ExtendedProxyModel::isHidingColumn(int column)
{
    return this->hiddenSet.contains(column);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::sort
*/
void SH_ExtendedProxyModel::sort(int column, Qt::SortOrder newOrder)
{
    this->model->field(column)->setSortOrder(newOrder);
    this->setSortKeyColumn(column);
}

/*!
 \details \~french
 \fn SH_ExtendedProxyModel::setSortKeyColumn
*/
void SH_ExtendedProxyModel::setSortKeyColumn(int column)
{
    this->sortIndex = column;
    this->setSortRole(this->model->roleForField(column));
    this->sort(0, this->model->field(column)->sortOrder());
    emit sortChanged();
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setFilterKeyColumn
*/
void SH_ExtendedProxyModel::setFilterKeyColumn(int column)
{
    this->addFilterKeyColumn(column);
    int nbFields = this->model->fieldsCount();
    for(int fieldIndex = 0; fieldIndex < column; fieldIndex++) {
        this->removeFilterKeyColumn(fieldIndex);
    }
    for(int fieldIndex = column + 1; fieldIndex < nbFields; fieldIndex++) {
        this->removeFilterKeyColumn(fieldIndex);
    }
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::addFilterKeyColumn
*/
void SH_ExtendedProxyModel::addFilterKeyColumn(int column)
{
    this->showHiddenColumn(column);
}

void SH_ExtendedProxyModel::addHiddenColumn(int column)
{
    this->hiddenSet.append(column);
}

/*inspired by: http://www.qtcentre.org/threads/52850-How-to-get-data-from-TableView-QML-Desktop-Components*/
/*QVariantMap SH_ExtendedProxyModel::get(int idx) const {
    QVariantMap map;
    foreach(int k, roleNames().keys()) {
        map[roleNames().value(k)] = data(index(idx, 0), k);
    }
    return map;
}*/

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::data
*/
QVariant SH_ExtendedProxyModel::data(int row, int column) const
{
    QModelIndex modelIndex = this->index(row, 0);
    if(column !=-1) {
        return this->data(modelIndex, this->model->roleForField(column));
    } else {
        QVariantMap map;
        QStringList list =  this->model->fieldsList();
        foreach(QString field, list) {
            map.insert(field,this->data(modelIndex, this->model->roleForField(list.indexOf(field))));
        }
        return QVariant(map);
    }
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::fetch
*/
bool SH_ExtendedProxyModel::fetch(QString tableName, QString filter, QString sort, QStringList fields)
{
    bool fetched = this->model->fetch(tableName, filter, sort, fields);
    if (fetched)
    {
        this->fillModel();
        QStringList fieldList = this->model->fieldsList();
        foreach(QString field, fieldList) {
            int fieldIndex = fieldList.indexOf(field);
            if(this->headerData(fieldIndex, Qt::Horizontal).toString() == field) {
                this->addHiddenColumn(fieldIndex);
            }
        }
    }
    this->setSourceModel(this->model);
    return fetched;
}
/*}*/
