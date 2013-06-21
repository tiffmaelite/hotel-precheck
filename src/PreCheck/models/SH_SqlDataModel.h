#ifndef SQLDATAMODEL_H
#define SQLDATAMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include "SH_SqlDataField.h"


/*!
\brief \~french 

 \class SH_SqlDataModel SqlDataModel.h "models/SqlDataModel.h"
*/
class SH_SqlDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString table READ tableName WRITE setTable NOTIFY tableChanged)
    Q_PROPERTY(QString filter READ filter WRITE setFilterCondition NOTIFY filterChanged)
    Q_PROPERTY(QString lastError READ lastError NOTIFY lastErrorChanged)

public:
    /*!
    \brief \~french 

     \fn SH_SqlDataModel
     \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);
    /*!
    \brief \~french 

     \fn SH_rowCount
     \param parent
     \return int
    */
    int rowCount(const QModelIndex &parent) const;
    /*!
    \brief \~french 

     \fn SH_data
     \param index
     \param role
     \return QVariant
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
    \brief \~french 

     \fn SH_datas
     \param index
     \param role
     \return QVariant
    */
    QVariantMap datas() const;
    /*!
    \brief \~french 

     \fn SH_setHeaderData
     \param section
     \param orientation
     \param value
     \param role
     \return bool
    */
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    /*!
    \brief \~french 

     \fn SH_roleForField
     \param fieldIndex
     \return int
    */
    int roleForField(int fieldIndex) const { return Qt::UserRole + fieldIndex;}
    /*!
    \brief \~french 

     \fn SH_fieldFromRole
     \param role
     \return int
    */
    int fieldFromRole(int role) const { return role - Qt::UserRole; }
    /*!
    \brief \~french 

     \fn SH_tableName
     \return const QString
    */
    const QString &tableName() const;
    /*!
    \brief \~french 

     \fn SH_lastError
     \return const QString
    */
    const QString &lastError();
    /*!
    \brief \~french 

     \fn SH_filter
     \return const QString
    */
    const QString &filter() const;

    /*!
    \brief \~french 

     \fn SH_setTable
     \param tableName
    */
    void setTable(const QString &tableName);
    /*!
    \brief \~french 

     \fn SH_setFilterCondition
     \param filter
    */
    void setFilterCondition(const QString &filter);
    /*!
    \brief \~french 

     \fn SH_resetFilterCondition
    */
    void resetFilterCondition();
    /*!
    \brief \~french 

     \fn SH_setFields
     \param fieldList
    */
    void setFields(QStringList fieldList);
    /*!
    \brief \~french 

     \fn SH_resetFieldsToAll
    */
    void resetFieldsToAll();

    /*!
    \brief \~french 

     \fn SH_fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    bool fetch(QString tableName = "", QString filter = "", QString sort="", QStringList fields = QStringList());
    /*!
    \brief \~french 

     \fn SH_field
     \param i
     \return SqlDataFields
    */
    SH_SqlDataFields *field(int i) const;
    /*!
    \brief \~french 

     \fn SH_fieldsCount
     \return int
    */
    int fieldsCount() const;
    /*!
    \brief \~french 

     \fn SH_setOrderBy
     \param sort
    */
    void setOrderBy(QString sort);
    /*!This function allows mapping of role identifiers to role property names in scripting languages.
        !*/
    /*!
    \brief \~french 

     \fn SH_roleNames
     \return QHash<int, QByteArray>
    */
    virtual QHash<int, QByteArray> roleNames() const { return this->mRoles; }

    /*!
    \brief \~french 

     \fn SH_isEmpty
     \return bool
    */
    bool isEmpty() const;

    /*!
    \brief \~french 

     \fn SH_query
     \return const QString
    */
    const QString &query() const;
    /*!
    \brief \~french 

     \fn SH_fieldsList
     \return const QString
    */
    const QStringList fieldsList() const;

signals:
    /*!
    \brief \~french 

     \fn SH_fieldsChanged
    */
    void fieldsChanged();
    /*!
    \brief \~french 

     \fn SH_tableChanged
    */
    void tableChanged();
    /*!
    \brief \~french 

     \fn SH_lastErrorChanged
    */
    void lastErrorChanged();
    /*!
    \brief \~french 

     \fn SH_filterChanged
    */
    void filterChanged();
    /*!
    \brief \~french 

     \fn SH_rolesChanged
    */
    void rolesChanged();
protected:
    /*!
    \brief \~french 

     \fn SH_applyRoles
    */
    void applyRoles();
private:
    /*!
     *\brief \~french  mTable
     */
    QString mTable;
    /*!
     *\brief \~french  mFilter
     */
    QString mFilter;
    /*!
     *\brief \~french  mSort
     */
    QString mSort;
    /*!
     *\brief \~french  mDataFields
     */
    QList<SH_SqlDataFields *> mDataFields;
    /*!
     *\brief \~french  mRoles
     */
    QHash<int, QByteArray> mRoles;
    /*!
     *\brief \~french  mSqlQuery
     */
    QSqlQuery mSqlQuery;
    /*!
     *\brief \~french  mRecords
     */
    QList<QSqlRecord> mRecords;
};

#endif /* SQLDATAMODEL_H*/

