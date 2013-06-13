#ifndef CHECKABLESORTFILTERPROXYMODEL_H
#define CHECKABLESORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "SqlDataModel.h"

/*!
 \brief

 \class CheckableSortFilterProxyModel checkable_sort_filter_proxy_model.h "models/checkable_sort_filter_proxy_model.h"
*/
class CheckableSortFilterProxyModel : public QSortFilterProxyModel
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

 \fn CheckableSortFilterProxyModel
 \param parent
*/
    CheckableSortFilterProxyModel(QObject *parent = 0);

    /*!
     \brief

     \fn currentSortKeyColumn
     \return const int
    */
    const int currentSortKeyColumn() const {return this->sortIndex;}
    /*!
     \brief

     \fn tableName
     \return const QString
    */
    const QString tableName() const { return this->model->tableName(); }
    /*!
     \brief

     \fn fields
     \return const QString
    */
    const QString fields() const { if(this->model->fieldsList().isEmpty()){ return "*";} else { return this->model->fieldsList().join(", ");} }
    /*!
     \brief

     \fn lastError
     \return const QString
    */
    const QString lastError() const { return this->model->lastError(); }
    /*!
     \brief

     \fn isEmpty
     \return const bool
    */
    const bool isEmpty() const { return this->model->isEmpty(); }
    /*!
     \brief

     \fn setSortKeyColumn
     \param column
    */
    void setSortKeyColumn(int column);

    /*!
     \brief

     \fn field
     \param i
     \return SqlDataFields
    */
    Q_INVOKABLE SqlDataFields *field(int i) const { return this->model->field(i); }
    /*!
     \brief

     \fn fieldsCount
     \return int
    */
    Q_INVOKABLE int fieldsCount() const { return this->model->fieldsCount(); }
    /*!
     \brief

     \fn fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    Q_INVOKABLE bool fetch(QString tableName = "", QString filter = "", QString sort = "", QStringList fields = QStringList());
    /*!
     \brief

     \fn sort
     \param column
     \param newOrder
    */
    Q_INVOKABLE void sort(int column, Qt::SortOrder newOrder = Qt::AscendingOrder);
    /*!
     \brief

     \fn addFilterKeyColumn
     \param column
    */
    Q_INVOKABLE void addFilterKeyColumn(int column);
    /*!
     \brief

     \fn removeFilterKeyColumn
     \param column
    */
    Q_INVOKABLE void removeFilterKeyColumn(int column);
    /*!
     \brief

     \fn containsFilterKeyColumn
     \param column
     \return bool
    */
    Q_INVOKABLE bool containsFilterKeyColumn(int column);
    /*!
     \brief

     \fn data
     \param row
     \param column
     \return QVariant
    */
    Q_INVOKABLE QVariant data(int row, int column) const;
    /*!
     \brief

     \fn data
     \param index
     \param role
     \return QVariant
    */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    /*!
     \brief

     \fn setData
     \param index
     \param value
     \param role
     \return bool
    */
    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    /*!
     \brief

     \fn roleNames
     \return QHash<int, QByteArray>
    */
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const { return this->model->roleNames(); }
    /*!
     \brief

     \fn flags
     \param index
     \return Qt::ItemFlags
    */
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;

    /*!
     \brief

     \fn invalidateFilter
    */
    void invalidateFilter();
    /*!
     \brief

     \fn setBooleanColumns
     \param boolCols
    */
    void setBooleanColumns(QList<int> boolCols);
    /*!
     \brief

     \fn setReadOnlyColumns
     \param readonlyCols
    */
    void setReadOnlyColumns(QList<int> readonlyCols);
    /*!
     \brief

     \fn setPasswordColumns
     \param passwordCols
    */
    void setPasswordColumns(QList<int> passwordCols);
    /*!
     \brief

     \fn setNullColumns
     \param nullCols
    */
    void setNullColumns(QList<int> nullCols);
    /*!
     \brief

     \fn setNotNullColumns
     \param notNullCols
    */
    void setNotNullColumns(QList<int> notNullCols);

signals:
    /*!
     \brief

     \fn sortChanged
    */
    void sortChanged();

protected:
    /*!
     \brief

     \fn fillModel
    */
    virtual void fillModel() = 0;
    /*!
     \brief

     \fn filterAcceptsRow
     \param source_row
     \param source_parent
     \return bool
    */
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    SqlDataModel *model; /*!< TODO */

private:
    /*!
     \brief

     \fn replaceSet
     \param originalSet
     \param newSet
    */
    void replaceSet(QList<int>& originalSet, QList<int> newSet);
    QList<int> booleanSet; /*!< TODO */
    QList<int> passwordSet; /*!< TODO */
    QList<int> readonlySet; /*!< TODO */
    QList<int> notNullSet; /*!< TODO */
    QList<int> nullSet; /*!< TODO */
    QList<int> filters; /*!< TODO */
    int sortIndex; /*!< TODO */
};
#endif
