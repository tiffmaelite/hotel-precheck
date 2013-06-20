#ifndef SQLDATAMODEL_H
#define SQLDATAMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include "SH_SqlDataField.h"


/*!
 \brief

 \class SqlDataModel SqlDataModel.h "models/SqlDataModel.h"
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

     \fn SqlDataModel
     \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);
    /*!
     \brief

     \fn rowCount
     \param parent
     \return int
    */
    int rowCount(const QModelIndex &parent) const;
    /*!
     \brief

     \fn data
     \param index
     \param role
     \return QVariant
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief

     \fn datas
     \param index
     \param role
     \return QVariant
    */
    QVariantMap datas() const;
    /*!
     \brief

     \fn setHeaderData
     \param section
     \param orientation
     \param value
     \param role
     \return bool
    */
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    /*!
     \brief

     \fn roleForField
     \param fieldIndex
     \return int
    */
    int roleForField(int fieldIndex) const { return Qt::UserRole + fieldIndex;}
    /*!
     \brief

     \fn fieldFromRole
     \param role
     \return int
    */
    int fieldFromRole(int role) const { return role - Qt::UserRole; }
    /*!
     \brief

     \fn tableName
     \return const QString
    */
    const QString &tableName() const;
    /*!
     \brief

     \fn lastError
     \return const QString
    */
    const QString &lastError();
    /*!
     \brief

     \fn filter
     \return const QString
    */
    const QString &filter() const;

    /*!
     \brief

     \fn setTable
     \param tableName
    */
    void setTable(const QString &tableName);
    /*!
     \brief

     \fn setFilterCondition
     \param filter
    */
    void setFilterCondition(const QString &filter);
    /*!
     \brief

     \fn resetFilterCondition
    */
    void resetFilterCondition();
    /*!
     \brief

     \fn setFields
     \param fieldList
    */
    void setFields(QStringList fieldList);
    /*!
     \brief

     \fn resetFieldsToAll
    */
    void resetFieldsToAll();

    /*!
     \brief

     \fn fetch
     \param tableName
     \param filter
     \param sort
     \param fields
     \return bool
    */
    bool fetch(QString tableName = "", QString filter = "", QString sort="", QStringList fields = QStringList());
    /*!
     \brief

     \fn field
     \param i
     \return SqlDataFields
    */
    SH_SqlDataFields *field(int i) const;
    /*!
     \brief

     \fn fieldsCount
     \return int
    */
    int fieldsCount() const;
    /*!
     \brief

     \fn setOrderBy
     \param sort
    */
    void setOrderBy(QString sort);
    /*!This function allows mapping of role identifiers to role property names in scripting languages.
        !*/
    /*!
     \brief

     \fn roleNames
     \return QHash<int, QByteArray>
    */
    virtual QHash<int, QByteArray> roleNames() const { return this->mRoles; }

    /*!
     \brief

     \fn isEmpty
     \return bool
    */
    bool isEmpty() const;

    /*!
     \brief

     \fn query
     \return const QString
    */
    const QString &query() const;
    /*!
     \brief

     \fn fieldsList
     \return const QString
    */
    const QStringList fieldsList() const;

signals:
    /*!
     \brief

     \fn fieldsChanged
    */
    void fieldsChanged();
    /*!
     \brief

     \fn tableChanged
    */
    void tableChanged();
    /*!
     \brief

     \fn lastErrorChanged
    */
    void lastErrorChanged();
    /*!
     \brief

     \fn filterChanged
    */
    void filterChanged();
    /*!
     \brief

     \fn rolesChanged
    */
    void rolesChanged();
protected:
    /*!
     \brief

     \fn applyRoles
    */
    void applyRoles();
private:
    QString mTable; /*!< TODO */
    QString mFilter; /*!< TODO */
    QString mSort; /*!< TODO */
    QList<SH_SqlDataFields *> mDataFields; /*!< TODO */
    QHash<int, QByteArray> mRoles; /*!< TODO */
    QSqlQuery mSqlQuery; /*!< TODO */
    QList<QSqlRecord> mRecords; /*!< TODO */
};

#endif // SQLDATAMODEL_H

