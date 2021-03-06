#ifndef SH_ExtendedProxyModel_H
#define SH_ExtendedProxyModel_H

#include <QSortFilterProxyModel>
#include "SH_SqlDataModel.h"
#include "SH_MessageManager.h"

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
    Q_PROPERTY(QString fieldsCount READ fieldsCount)// STORED false)
    Q_PROPERTY(bool empty READ isEmpty) //NOTIFY emptinessChanged)// STORED false)
    Q_PROPERTY(QString lastError READ lastError)// STORED false)
    Q_PROPERTY(int sortKeyColumn READ sortKeyColumn WRITE setSortKeyColumn NOTIFY sortChanged) //MEMBER m_sortIndex

public:
    /*!
\brief \~french

 \fn SH_ExtendedProxyModel
 \param parent
*/
    SH_ExtendedProxyModel(QObject *parent = 0);

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const {  Q_UNUSED(parent); return this->m_count; }

    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const { Q_UNUSED(parent);  return 1; }


    int sortKeyColumn() const { return this->m_sortIndex; }

    /*!
    \brief \~french

    \fn fields
    \return const QString
    */
    /*QString fields() { QStringList fields = this->model->fieldsList(); if(fields.isEmpty()){ return "*";} else { return fields.join(", ");} }*/

    /*!
    \brief \~french

    \fn lastError
    \return const QString
    */
    QString lastError() { return this->model->lastError(); }

    /*!
    \brief \~french

    \fn isEmpty
    \return const bool
    */
    bool isEmpty() {
        if(!this->m_fetched) {
            return true;
        } else {
            return this->model->isEmpty();
        }
    }

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
    Q_INVOKABLE SH_SqlDataFields *field(int i) { if(this->m_fetched && i  >= 0 && i < this->fieldsCount()) { return this->modelFields.at(i); } return new SH_SqlDataFields(); }

    /*!
    \brief \~french

    \fn fieldsCount
    \return int
    */
    Q_INVOKABLE int fieldsCount() { if(!this->m_fetched) { return 0; } else { return this->modelFields.count(); } }

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
    Q_INVOKABLE QVariant data(int row, int column = -1);

    /*!
    \brief \~french

    \fn data
    \param index
    \param role
    \return QVariant
    */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole);

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
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames();

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
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole);

    int fieldIndex(QString fieldname);
    Q_INVOKABLE QModelIndex modelIndex(int row, int column);
signals:

    /*!
    \brief \~french

    \fn sortChanged
    */
    void sortChanged();

    void emptinessChanged();

protected:
    /*!
        \brief \~french

        \fn fetch
        \return bool
        */
    virtual bool fetch() = 0;

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
    SH_SqlQueryModel *model;
    QList<SH_SqlDataFields*> modelFields;
    bool m_fetched;
    QHash<int, QByteArray> m_roles;
    QMutex m_gettingDataFromIndex;
    QMutex m_gettingData;
    QMutex m_fetching;
    int m_count;

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
    QList<int> m_booleanSet;

    /*!
    *\brief \~french passwordSet
    */
    QList<int> m_passwordSet;

    /*!
    *\brief \~french readonlySet
    */
    QList<int> m_readonlySet;

    /*!
    *\brief \~french notNullSet
    */
    QList<int> m_notNullSet;

    /*!
    *\brief \~french nullSet
    */
    QList<int> m_nullSet;

    /*!
    *\brief \~french filters
    */
    QList<int> m_hiddenSet;

    /*!
    *\brief \~french sortIndex
    */
    int m_sortIndex;

    // QSortFilterProxyModel interface
protected:
    virtual bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    virtual bool lessThan(const QModelIndex &left, const QModelIndex &right) const;

    // QAbstractItemModel interface
};
/*}*/
#endif
