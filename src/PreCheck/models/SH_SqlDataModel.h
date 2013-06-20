#ifndef SQLDATAMODEL_H
#define SQLDATAMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include "SH_SqlDataField.h"


/*!
 \brief

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
     \brief

     \fn SH_SqlDataModel
     \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);
    /*!
     \brief

     \fn SH_rowCount
     \param parent
     \return int
    */
    int rowCount(const QModelIndex &parent) const;
    /*!
     \brief

     \fn SH_data
     \param index
     \param role
     \return QVariant
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief

     \fn SH_datas
     \param index
     \param role
     \return QVariant
    */
    QVariantMap datas() const;
    /*!
     \brief

     \fn SH_setHeaderData
     \param section
     \param orientation
     \param value
     \param role
     \return bool
    */
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    /*!
     \brief

     \fn SH_roleForField
     \param fieldIndex
     \return int
    */
    int roleForField(int fieldIndex) const { return Qt::UserRole + fieldIndex;}
    /*!
     \brief

     \fn SH_fieldFromRole
     \param role
     \return int
    */
    int fieldFromRole(int role) const { return role - Qt::UserRole; }
    /*!
     \brief

     \fn SH_tableName
     \return const QString
    */
    const QString &tableName() const;
    /*!
     \brief

     \fn SH_lastError
     \return const QString
    */
    const QString &lastError();
    /*!
     \brief

     \fn SH_filter
     \return const QString
    */
    const QString &filter() const;

    /*!
     \brief

     \fn SH_setTable
     \param tableName
    */
    void setTable(const QString &tableName);
    /*!
     \brief

     \fn SH_setFilterCondition
     \param filter
    */
    void setFilterCondition(const QString &filter);
    /*!
     \brief

     \fn SH_resetFilterCondition
    */
    void resetFilterCondition();
    /*!
     \brief

     \fn SH_setFields
     \param fieldList
    */
    void setFields(QStringList fieldList);
    /*!
     \brief

     \fn SH_resetFieldsToAll
    */
    void resetFieldsToAll();

    /*!
     \brief

     \fn SH_fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    bool fetch(QString tableName = "", QString filter = "", QString sort="", QStringList fields = QStringList());
    /*!
     \brief

     \fn SH_field
     \param i
     \return SqlDataFields
    */
    SH_SqlDataFields *field(int i) const;
    /*!
     \brief

     \fn SH_fieldsCount
     \return int
    */
    int fieldsCount() const;
    /*!
     \brief

     \fn SH_setOrderBy
     \param sort
    */
    void setOrderBy(QString sort);
    /*!This function allows mapping of role identifiers to role property names in scripting languages.
        !*/
    /*!
     \brief

     \fn SH_roleNames
     \return QHash<int, QByteArray>
    */
    virtual QHash<int, QByteArray> roleNames() const { return this->mRoles; }

    /*!
     \brief

     \fn SH_isEmpty
     \return bool
    */
    bool isEmpty() const;

    /*!
     \brief

     \fn SH_query
     \return const QString
    */
    const QString &query() const;
    /*!
     \brief

     \fn SH_fieldsList
     \return const QString
    */
    const QStringList fieldsList() const;

signals:
    /*!
     \brief

     \fn SH_fieldsChanged
    */
    void fieldsChanged();
    /*!
     \brief

     \fn SH_tableChanged
    */
    void tableChanged();
    /*!
     \brief

     \fn SH_lastErrorChanged
    */
    void lastErrorChanged();
    /*!
     \brief

     \fn SH_filterChanged
    */
    void filterChanged();
    /*!
     \brief

     \fn SH_rolesChanged
    */
    void rolesChanged();
protected:
    /*!
     \brief

     \fn SH_applyRoles
    */
    void applyRoles();
private:
    /*!
     * \brief mTable
     */
    QString mTable;
    /*!
     * \brief mFilter
     */
    QString mFilter;
    /*!
     * \brief mSort
     */
    QString mSort;
    /*!
     * \brief mDataFields
     */
    QList<SH_SqlDataFields *> mDataFields;
    /*!
     * \brief mRoles
     */
    QHash<int, QByteArray> mRoles;
    /*!
     * \brief mSqlQuery
     */
    QSqlQuery mSqlQuery;
    /*!
     * \brief mRecords
     */
    QList<QSqlRecord> mRecords;
};

#endif /* SQLDATAMODEL_H*/

