#ifndef SQLDATAMODEL_H
#define SQLDATAMODEL_H
#include <QAbstractListModel>
#include <QtSql>
#include "SH_SqlDataField.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french
 \class SH_SqlDataModel SqlDataModel.h "models/SqlDataModel.h"
*/
class SH_SqlDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName NOTIFY tableNameChanged) //MEMBER m_tableName
    Q_PROPERTY(QStringList fields READ fieldsList WRITE setFields RESET resetFieldsToAll NOTIFY fieldsChanged)
    Q_PROPERTY(QString filterCondition READ filterCondition WRITE setFilterCondition RESET resetFilterCondition NOTIFY filterConditionChanged) //MEMBER m_condition
    //Q_PROPERTY(QHash roles READ roleNames WRITE setRoles NOTIFY rolesChanged) //MEMBER m_roles
    Q_PROPERTY(QString lastError READ lastError NOTIFY lastErrorChanged)

public:

    /*!
    \brief \~french
    \fn SqlDataModel
    \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);

    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString tableName() const { return m_tableName; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setTableName(const QString &table);

    /*!
    * \fn tableCondition
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString filterCondition() const { return m_condition; }
    /*!
    * \fn setTableCondition
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString condition La nouvelle liste de choix de l'état
    */
    void setFilterCondition(const QString &condition);
    void resetFilterCondition() { m_condition = ""; emit filterConditionChanged();}

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
    QVariantMap datas();

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
    \fn isEmpty
    \return bool
    */
    bool isEmpty() const;

    /*!
    \brief \~french
    \fn query
    \return const QString
    */
    const QString query() const;

    /*!
    \brief \~french
    \fn fieldsList
    \return const QString
    */
    const QStringList fieldsList() const;

    const QString lastError();
    QString getMFilter() const;
    void setMFilter(const QString &value);

    QString getMTable() const;
    void setMTable(const QString &value);

signals:

    /*!
    \brief \~french
    \fn fieldsChanged
    */
    void fieldsChanged();

    /*!
    \brief \~french
    \fn tableNameChanged
    */
    void tableNameChanged();

    /*!
    \brief \~french
    \fn lastErrorChanged
    */
    void lastErrorChanged();

    /*!
    \brief \~french
    \fn filterConditionChanged
    */
    void filterConditionChanged();


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
    *\brief \~french mTable
    */
    QString m_tableName;

    /*!
    *\brief \~french mFilter
    */
    QString m_condition;

    /*!
    *\brief \~french mSort
    */
    QString m_order;

    /*!
    *\brief \~french mDataFields
    */
    QList<SH_SqlDataFields *> m_fields;

    /*!
    *\brief \~french mRoles
    */
    QHash<int, QByteArray> m_roles;

    /*!
    *\brief \~french mSqlQuery
    */
    QSqlQuery m_query;

    /*!
    *\brief \~french mRecords
    */
    QList<QSqlRecord> m_records;
};
/*}*/
#endif /* SQLDATAMODEL_H*/
