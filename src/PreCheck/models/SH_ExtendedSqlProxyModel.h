#ifndef SH_ExtendedProxyModel_H
#define SH_ExtendedProxyModel_H

#include <QSortFilterProxyModel>
#include "SH_SqlDataModel.h"

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_CheckableSortFilterProxyMode
 \headerfile checkable_sort_filter_proxy_model.h "models/checkable_sort_filter_proxy_model.h"
*/
class SH_ExtendedProxyModel : public QSortFilterProxyModel
{

    Q_OBJECT
    Q_PROPERTY(QString table READ tableName STORED false)
    Q_PROPERTY(QString fieldsList READ fields STORED false)
    Q_PROPERTY(QString fieldsCount READ fieldsCount STORED false)
    Q_PROPERTY(bool empty READ isEmpty STORED false)
    Q_PROPERTY(QString lastError READ lastError STORED false)
    Q_PROPERTY(int sortKeyColumn MEMBER sortIndex WRITE setSortKeyColumn NOTIFY sortChanged)

public:
/*!
\brief \~french

 \fn SH_ExtendedProxyModel
 \param parent
*/
    SH_ExtendedProxyModel(QObject *parent = 0);

/*!
    \brief \~french

    \fn tableName
    \return const QString
    */
    const QString tableName() const { return (this->model->property("tableName")).value<QString>(); }

/*!
    \brief \~french

    \fn fields
    \return const QString
    */
    const QString fields() const { if(this->model->fieldsList().isEmpty()){ return "*";} else { return this->model->fieldsList().join(", ");} }

/*!
    \brief \~french

    \fn lastError
    \return const QString
    */
    const QString lastError() const { return this->model->lastError(); }

/*!
    \brief \~french

    \fn isEmpty
    \return const bool
    */
    bool isEmpty() const { return this->model->isEmpty(); }

/*!
    \brief \~french

    \fn setSortKeyColumn
    \param column
    */
    void setSortKeyColumn(int column);


/*!
    \brief \~french

    \fn field
    \param i
    \return SqlDataFields
    */
    Q_INVOKABLE SH_SqlDataFields *field(int i) const { return this->model->field(i); }

/*!
    \brief \~french

    \fn fieldsCount
    \return int
    */
    int fieldsCount() const { return this->model->fieldsCount(); }

/*!
    \brief \~french

    \fn fetch
    \param tableName
    \param filter
    \param sort
    \param fields
    \return bool
    */
    Q_INVOKABLE bool fetch(QString tableName = "", QString filter = "", QString sort = "", QStringList fields = QStringList());

/*!
    \brief \~french

    \fn sort
    \param column
    \param newOrder
    */
    Q_INVOKABLE void sort(int column, Qt::SortOrder newOrder = Qt::AscendingOrder);

/*!
    \brief \~french

    \fn addFilterKeyColumn
    \param column
    */
    Q_INVOKABLE void addHiddenColumn(int column);

/*!
    \brief \~french

    \fn removeFilterKeyColumn
    \param column
    */
    Q_INVOKABLE void showHiddenColumn(int column);

/*!
    \brief \~french

    \fn containsFilterKeyColumn
    \param column
    \return bool
    */
    Q_INVOKABLE bool isHidingColumn(int column);

/*!
    \brief \~french

    \fn data
    \param row
    \param column
    \return QVariant
    */
    Q_INVOKABLE QVariant data(int row, int column = -1) const;

/*!
    \brief \~french

    \fn data
    \param index
    \param role
    \return QVariant
    */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

/*!
    \brief \~french

    \fn setData
    \param index
    \param value
    \param role
    \return bool
    */
    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

/*!
    \brief \~french

    \fn roleNames
    \return QHash<int, QByteArray>
    */
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const { return this->model->roleNames(); }

/*!
    \brief \~french

    \fn flags
    \param index
    \return Qt::ItemFlags
    */
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;


/*!
    \brief \~french

    \fn invalidateFilter
    */
    void invalidateFilter();

/*!
    \brief \~french

    \fn setBooleanColumns
    \param boolCols
    */
    void setBooleanColumns(QList<int> boolCols);

/*!
    \brief \~french

    \fn setReadOnlyColumns
    \param readonlyCols
    */
    void setReadOnlyColumns(QList<int> readonlyCols);

/*!
    \brief \~french

    \fn setPasswordColumns
    \param passwordCols
    */
    void setPasswordColumns(QList<int> passwordCols);

/*!
    \brief \~french

    \fn setNullColumns
    \param nullCols
    */
    void setNullColumns(QList<int> nullCols);

/*!
    \brief \~french

    \fn setNotNullColumns
    \param notNullCols
    */
    void setNotNullColumns(QList<int> notNullCols);

    void resetColumnsList();
    void removeFilterKeyColumn(int column);
    void addFilterKeyColumn(int column);
    bool containsFilterKeyColumn(int column);
    void setFilterKeyColumn(int column);
signals:

/*!
    \brief \~french

    \fn sortChanged
    */
    void sortChanged();

protected:

/*!
    \brief \~french

    \fn fillModel
    */
    virtual void fillModel() = 0;

/*!
    \brief \~french

    \fn filterAcceptsRow
    \param source_row
    \param source_parent
    \return bool
    */
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    SH_SqlDataModel *model;

private:

/*!
    \brief \~french

    \fn replaceSet
    \param originalSet
    \param newSet
    */
    void replaceSet(QList<int>& originalSet, QList<int> newSet);

/*!
    *\brief \~french booleanSet
    */
    QList<int> booleanSet;

/*!
    *\brief \~french passwordSet
    */
    QList<int> passwordSet;

/*!
    *\brief \~french readonlySet
    */
    QList<int> readonlySet;

/*!
    *\brief \~french notNullSet
    */
    QList<int> notNullSet;

/*!
    *\brief \~french nullSet
    */
    QList<int> nullSet;

/*!
    *\brief \~french filters
    */
    QList<int> hiddenSet;

/*!
    *\brief \~french sortIndex
    */
    int sortIndex;
};
/*}*/
#endif
