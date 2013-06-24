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

     \fn SqlDataModel
     \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);
    /*!
    \brief \~french 

     \fn rowCount
     \param parent
     \return int
    */
    int rowCount(const QModelIndex &parent) const;
    /*!
    \brief \~french 

     \fn data
     \param index
     \param role
     \return QVariant
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
    \brief \~french 

     \fn datas
     \param index
     \param role
     \return QVariant
    */
    QVariantMap datas() const;
    /*!
    \brief \~french 

     \fn setHeaderData
     \param section
     \param orientation
     \param value
     \param role
     \return bool
    */
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    /*!
    \brief \~french 

     \fn roleForField
     \param fieldIndex
     \return int
    */
    int roleForField(int fieldIndex) const { return Qt::UserRole + fieldIndex;}
    /*!
    \brief \~french 

     \fn fieldFromRole
     \param role
     \return int
    */
    int fieldFromRole(int role) const { return role - Qt::UserRole; }
    /*!
    \brief \~french 

     \fn tableName
     \return const QString
    */
    const QString &tableName() const;
    /*!
    \brief \~french 

     \fn lastError
     \return const QString
    */
    const QString &lastError();
    /*!
    \brief \~french 

     \fn filter
     \return const QString
    */
    const QString &filter() const;

    /*!
    \brief \~french 

     \fn setTable
     \param tableName
    */
    void setTable(const QString &tableName);
    /*!
    \brief \~french 

     \fn setFilterCondition
     \param filter
    */
    void setFilterCondition(const QString &filter);
    /*!
    \brief \~french 

     \fn resetFilterCondition
    */
    void resetFilterCondition();
    /*!
    \brief \~french 

     \fn setFields
     \param fieldList
    */
    void setFields(QStringList fieldList);
    /*!
    \brief \~french 

     \fn resetFieldsToAll
    */
    void resetFieldsToAll();

    /*!
    \brief \~french 

     \fn fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    bool fetch(QString tableName = "", QString filter = "", QString sort="", QStringList fields = QStringList());
    /*!
    \brief \~french 

     \fn field
     \param i
     \return SqlDataFields
    */
    SH_SqlDataFields *field(int i) const;
    /*!
    \brief \~french 

     \fn fieldsCount
     \return int
    */
    int fieldsCount() const;
    /*!
    \brief \~french 

     \fn setOrderBy
     \param sort
    */
    void setOrderBy(QString sort);
    /*!This function allows mapping of role identifiers to role property names in scripting languages.
        !*/
    /*!
    \brief \~french 

     \fn roleNames
     \return QHash<int, QByteArray>
    */
    virtual QHash<int, QByteArray> roleNames() const { return this->mRoles; }

    /*!
    \brief \~french 

     \fn isEmpty
     \return bool
    */
    bool isEmpty() const;

    /*!
    \brief \~french 

     \fn query
     \return const QString
    */
    const QString &query() const;
    /*!
    \brief \~french 

     \fn fieldsList
     \return const QString
    */
    const QStringList fieldsList() const;

signals:
    /*!
    \brief \~french 

     \fn fieldsChanged
    */
    void fieldsChanged();
    /*!
    \brief \~french 

     \fn tableChanged
    */
    void tableChanged();
    /*!
    \brief \~french 

     \fn lastErrorChanged
    */
    void lastErrorChanged();
    /*!
    \brief \~french 

     \fn filterChanged
    */
    void filterChanged();
    /*!
    \brief \~french 

     \fn rolesChanged
    */
    void rolesChanged();
protected:
    /*!
    \brief \~french 

     \fn applyRoles
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

