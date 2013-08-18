#ifndef SH_SQLQUERYMODEL_H
#define SH_SQLQUERYMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include "SH_SqlDataField.h"
#include "SH_MessageManager.h"

class SH_SqlQueryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QStringList fields READ fieldsList WRITE setFields RESET resetFieldsToAll NOTIFY fieldsChanged)
    Q_PROPERTY(QString filterCondition READ filterCondition WRITE setFilterCondition RESET resetFilterCondition NOTIFY filterConditionChanged) //MEMBER m_condition
    //Q_PROPERTY(QHash roles READ roleNames WRITE setRoles NOTIFY rolesChanged) //MEMBER m_roles
    Q_PROPERTY(QString lastError READ lastError NOTIFY lastErrorChanged)

public:
    explicit SH_SqlQueryModel(QObject *parent = 0);

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QMap<int, QVariant> itemData(const QModelIndex &index) const;
    bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    /*!
    * \fn tableCondition
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString filterCondition() const { return this->m_condition; }
    /*!
    * \fn setTableCondition
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString condition La nouvelle liste de choix de l'état
    */
    void setFilterCondition(const QString &condition);
    void resetFilterCondition() { this->m_condition = ""; emit filterConditionChanged();}

    Q_INVOKABLE QHash<int, QByteArray> roleNames() const {/* foreach(QByteArray roleName, this->m_roles) { SH_MessageManager::debugMessage(QString("Le rôle %L1 d'origine est %2").arg(this->m_roles.key(roleName)).arg(QString(roleName))); }*/ return this->m_roles; }

    /*!
    \brief \~french
    \fn rowCount
    \param parent
    \return int
    */
    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const;

    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const { Q_UNUSED(parent);  return 1; }

    /*!
    \brief \~french
    \fn data
    \param index
    \param role
    \return QVariant
    */
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;

    /*!
    \brief \~french
    \fn datas
    \param index
    \param role
    \return QVariant
    */
    Q_INVOKABLE QVariantMap datas();

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

    bool fetch();

    /*!
    \brief \~french
    \fn fetch
    \return bool
    */
    virtual void fetchQuery() = 0;

    /*!
    \brief \~french
    \fn field
    \param i
    \return SqlDataFields
    */
    SH_SqlDataFields *field(int i);

    /*!
    \brief \~french
    \fn fieldsCount
    \return int
    */
    int fieldsCount();

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
    bool isEmpty();

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

signals:

    /*!
    \brief \~french
    \fn fieldsChanged
    */
    void fieldsChanged();

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

    /*!
    *\brief \~french mSqlQuery
    */
    QSqlQuery m_query;

    /*!
    *\brief \~french mSort
    */
    QString m_order;

protected slots:
    void resetInternalData();

private:
    /*!
    *\brief \~french mFilter
    */
    QString m_condition;

    /*!
    *\brief \~french mDataFields
    */
    QList<SH_SqlDataFields *> m_fields;

    /*!
    *\brief \~french mRoles
    */
    QHash<int, QByteArray> m_roles;


    /*!
    *\brief \~french mRecords
    */
    QList<QSqlRecord> m_records;

    bool m_new;

    QMutex* m_fetching;
};

#endif // SH_SQLQUERYMODEL_H
