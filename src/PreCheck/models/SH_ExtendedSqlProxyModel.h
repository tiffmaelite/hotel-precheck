#ifndef CHECKABLESORTFILTERPROXYMODEL_H
#define CHECKABLESORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "SH_SqlDataModel.h"

/*!
 \brief

 \class SH_CheckableSortFilterProxyMode
 \headerfile checkable_sort_filter_proxy_model.h "models/checkable_sort_filter_proxy_model.h"
*/
class SH_ExtendedProxyModel : public QSortFilterProxyModel
{

    Q_OBJECT
    Q_PROPERTY(QString table READ tableName)
    Q_PROPERTY(QString fieldsList READ fields)
    Q_PROPERTY(QString lastError READ lastError)
    Q_PROPERTY(int sortKeyColumn READ currentSortKeyColumn WRITE setSortKeyColumn NOTIFY sortChanged)
    Q_PROPERTY(bool empty READ isEmpty)

public:
/*!
 \brief

 \fn SH_CheckableSortFilterProxyModel
 \param parent
*/
    SH_ExtendedProxyModel(QObject *parent = 0);

    /*!
     \brief

     \fn SH_currentSortKeyColumn
     \return const int
    */
    const int currentSortKeyColumn() const {return this->sortIndex;}
    /*!
     \brief

     \fn SH_tableName
     \return const QString
    */
    const QString tableName() const { return this->model->tableName(); }
    /*!
     \brief

     \fn SH_fields
     \return const QString
    */
    const QString fields() const { if(this->model->fieldsList().isEmpty()){ return "*";} else { return this->model->fieldsList().join(", ");} }
    /*!
     \brief

     \fn SH_lastError
     \return const QString
    */
    const QString lastError() const { return this->model->lastError(); }
    /*!
     \brief

     \fn SH_isEmpty
     \return const bool
    */
    const bool isEmpty() const { return this->model->isEmpty(); }
    /*!
     \brief

     \fn SH_setSortKeyColumn
     \param column
    */
    void setSortKeyColumn(int column);

    /*!
     \brief

     \fn SH_field
     \param i
     \return SqlDataFields
    */
    Q_INVOKABLE SH_SqlDataFields *field(int i) const { return this->model->field(i); }
    /*!
     \brief

     \fn SH_fieldsCount
     \return int
    */
    Q_INVOKABLE int fieldsCount() const { return this->model->fieldsCount(); }
    /*!
     \brief

     \fn SH_fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    Q_INVOKABLE bool fetch(QString tableName = "", QString filter = "", QString sort = "", QStringList fields = QStringList());
    /*!
     \brief

     \fn SH_sort
     \param column
     \param newOrder
    */
    Q_INVOKABLE void sort(int column, Qt::SortOrder newOrder = Qt::AscendingOrder);
    /*!
     \brief

     \fn SH_addFilterKeyColumn
     \param column
    */
    Q_INVOKABLE void addFilterKeyColumn(int column);
    /*!
     \brief

     \fn SH_removeFilterKeyColumn
     \param column
    */
    Q_INVOKABLE void removeFilterKeyColumn(int column);
    /*!
     \brief

     \fn SH_containsFilterKeyColumn
     \param column
     \return bool
    */
    Q_INVOKABLE bool containsFilterKeyColumn(int column);
    /*!
     \brief

     \fn SH_data
     \param row
     \param column
     \return QVariant
    */
    Q_INVOKABLE QVariant data(int row, int column) const;
    /*!
     \brief

     \fn SH_data
     \param index
     \param role
     \return QVariant
    */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    /*!
     \brief

     \fn SH_setData
     \param index
     \param value
     \param role
     \return bool
    */
    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    /*!
     \brief

     \fn SH_roleNames
     \return QHash<int, QByteArray>
    */
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const { return this->model->roleNames(); }
    /*!
     \brief

     \fn SH_flags
     \param index
     \return Qt::ItemFlags
    */
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;

    /*!
     \brief

     \fn SH_invalidateFilter
    */
    void invalidateFilter();
    /*!
     \brief

     \fn SH_setBooleanColumns
     \param boolCols
    */
    void setBooleanColumns(QList<int> boolCols);
    /*!
     \brief

     \fn SH_setReadOnlyColumns
     \param readonlyCols
    */
    void setReadOnlyColumns(QList<int> readonlyCols);
    /*!
     \brief

     \fn SH_setPasswordColumns
     \param passwordCols
    */
    void setPasswordColumns(QList<int> passwordCols);
    /*!
     \brief

     \fn SH_setNullColumns
     \param nullCols
    */
    void setNullColumns(QList<int> nullCols);
    /*!
     \brief

     \fn SH_setNotNullColumns
     \param notNullCols
    */
    void setNotNullColumns(QList<int> notNullCols);

signals:
    /*!
     \brief

     \fn SH_sortChanged
    */
    void sortChanged();

protected:
    /*!
     \brief

     \fn SH_fillModel
    */
    virtual void fillModel() = 0;
    /*!
     \brief

     \fn SH_filterAcceptsRow
     \param source_row
     \param source_parent
     \return bool
    */
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    SH_SqlDataModel *model;

private:
    /*!
     \brief

     \fn SH_replaceSet
     \param originalSet
     \param newSet
    */
    void replaceSet(QList<int>& originalSet, QList<int> newSet);
    /*!
     * \brief booleanSet
     */
    QList<int> booleanSet;
    /*!
     * \brief passwordSet
     */
    QList<int> passwordSet;
    /*!
     * \brief readonlySet
     */
    QList<int> readonlySet;
    /*!
     * \brief notNullSet
     */
    QList<int> notNullSet;
    /*!
     * \brief nullSet
     */
    QList<int> nullSet;
    /*!
     * \brief filters
     */
    QList<int> filters;
    /*!
     * \brief sortIndex
     */
    int sortIndex;
};
#endif
