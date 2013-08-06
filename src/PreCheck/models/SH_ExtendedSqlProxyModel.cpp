#include <QtSql/QSqlRecord>
#include <QDebug>
#include "SH_ExtendedSqlProxyModel.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ExtendedProxyModel::SH_ExtendedProxyModel
*/
SH_ExtendedProxyModel::SH_ExtendedProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent), m_fetched(false), m_sortIndex(0)
{
    this->setDynamicSortFilter(false);
}


int SH_ExtendedProxyModel::fieldIndex(QString fieldname) {
    foreach(SH_SqlDataFields* field, this->modelFields) {
        if(field->name().toUpper() == fieldname.toUpper()) {
            return this->modelFields.indexOf(field);
        }
    }
    return -1;
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
    replaceSet(this->m_booleanSet, boolCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setReadOnlyColumns
*/
void SH_ExtendedProxyModel::setReadOnlyColumns(QList<int> readonlyCols) {
    replaceSet(this->m_readonlySet, readonlyCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setPasswordColumns
*/
void SH_ExtendedProxyModel::setPasswordColumns(QList<int> passwordCols) {
    replaceSet(this->m_passwordSet, passwordCols);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setNullColumns
*/
void SH_ExtendedProxyModel::setNullColumns(QList<int> nullCols) {
    if (sourceModel()->inherits("SH_SqlQueryModel")) {
        replaceSet(this->m_nullSet, nullCols);
    }
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::setNotNullColumns
 \param notNullCols
*/
void SH_ExtendedProxyModel::setNotNullColumns(QList<int> notNullCols) {
    if (sourceModel()->inherits("SH_SqlQueryModel")) {
        replaceSet(this->m_notNullSet, notNullCols);
    }
}


/*!
 \details \~french

 \fn SH_ExtendedProxyModel::filterAcceptsRow
*/
bool SH_ExtendedProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent);

    if (!this->m_notNullSet.isEmpty())
    {
        foreach(int column, this->m_notNullSet)
        {
            if (!this->model->data(QSortFilterProxyModel::mapToSource(this->index(source_row, 0)), this->model->roleForField(column)).isNull())
            {
                return false;
            }
        }
    }

    if (!this->m_nullSet.isEmpty())
    {
        foreach(int column, this->m_nullSet)
        {
            if (!this->model->data(QSortFilterProxyModel::mapToSource(this->index(source_row, 0)), this->model->roleForField(column)).isNull())
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
QVariant SH_ExtendedProxyModel::data(const QModelIndex &index, int role)
{
    if(!m_fetched) {
        this->fetch();
        this->m_roles= this->model->roleNames();
    }
    if (index.isValid())
    {
        if (this->m_booleanSet.contains(role))
        {
            return index.data(Qt::EditRole).toBool() ? QVariant(Qt::Checked) : QVariant(Qt::Unchecked);
        }
        else if (this->m_passwordSet.contains(role))
        {
            return QVariant("***");
        }
        else if(!this->m_hiddenSet.contains(role))
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

    if (this->m_booleanSet.contains(role))
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
    if (!this->m_booleanSet.isEmpty())
    {
        return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    }
    else if (!this->m_readonlySet.isEmpty())
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
    this->m_hiddenSet.clear();
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
    this->m_hiddenSet.removeAt(this->m_hiddenSet.indexOf(column));
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
    return this->m_hiddenSet.contains(column);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::sort
*/
void SH_ExtendedProxyModel::sort(int column, Qt::SortOrder newOrder)
{
    if(this->m_sortIndex != column || newOrder != this->modelFields.at(column)->sortOrder()) {
        this->m_sortIndex = column;
        this->modelFields.at(column)->setSortOrder(newOrder);
        this->setSortRole(this->model->roleForField(column));
        emit sortChanged();
    }
}

/*!
 \details \~french
 \fn SH_ExtendedProxyModel::setSortKeyColumn
*/
void SH_ExtendedProxyModel::setSortKeyColumn(int column)
{
    this->sort(column, this->modelFields.at(column)->sortOrder());
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
    this->m_hiddenSet.append(column);
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
QVariant SH_ExtendedProxyModel::data(int row, int column)
{
    if(!this->m_fetched) {
        this->fetch();
        this->m_roles= this->model->roleNames();
    }
    QModelIndex modelIndex = this->index(row, 0);
    if(column !=-1) {
        return this->data(modelIndex, this->model->roleForField(column));
    } else {
        QVariantMap map;
        foreach(SH_SqlDataFields* field, this->modelFields) {
            map.insert(field->name(),this->data(modelIndex, this->model->roleForField(this->modelFields.indexOf(field))));
        }
        return QVariant(map);
    }
}


/*!
 \details \~french
 \fn SH_ExtendedProxyModel::setHeaderData
*/
bool SH_ExtendedProxyModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if(!this->isHidingColumn(section) && (orientation == Qt::Horizontal)) {
        this->modelFields.at(section)->setText(value.toString().toUpper());
        return (this->modelFields.at(section)->text() == value.toString().toUpper());
    }
    return false;
}

/*!
 \details \~french
 \fn SH_ExtendedProxyModel::setHeaderData
*/
QVariant SH_ExtendedProxyModel::headerData(int section, Qt::Orientation orientation, int role)
{
    Q_UNUSED(role);
    if(!this->isHidingColumn(section) && (orientation == Qt::Horizontal)) {
        return QVariant(this->modelFields.at(section)->text());
    }
    return false;
}
/*}*/
