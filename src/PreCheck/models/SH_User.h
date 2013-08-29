#ifndef USER_H
#define USER_H
#include <QSqlRecord>
#include <QSqlDriver>
#include <QtCore>

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_User
\headerfile user.h "models/user.h"
*/
class SH_User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id) //MEMBER m_id
    Q_PROPERTY(QString name READ name) //MEMBER m_name
    Q_PROPERTY(bool receptionist READ isReceptionist WRITE setReceptionist NOTIFY receptionistChanged) //MEMBER m_receptionist
    Q_PROPERTY(bool managerX READ isManagerX WRITE setManagerX NOTIFY managerXChanged) //MEMBER m_managerX
    Q_PROPERTY(bool managerZ READ isManagerZ WRITE setManagerZ NOTIFY managerZChanged) //MEMBER m_managerZ
    Q_PROPERTY(bool administrator READ isAdministrator WRITE setAdministrator NOTIFY administratorChanged) //MEMBER m_administrator
    Q_PROPERTY(int roles READ roles NOTIFY rolesChanged)
    Q_PROPERTY(bool valid READ isValid)

public:

    /*!
\brief \~french

 \fn SH_User
 \param name
 \param id
 \param isReceptionist
 \param isManagerX
 \param isManagerZ
 \param isAdministrator
 \param parent
*/
    SH_User(QString name = "", int id = 0, bool isReceptionist = false, bool isManagerX = false, bool isManagerZ = false, bool isAdministrator = false, QObject *parent = 0);


    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString name() const { return this->m_name; }
    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    int id() const { return this->m_id; }
    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    bool isReceptionist() const { return this->m_receptionist; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setReceptionist(bool rec){ this->m_receptionist = rec; emit receptionistChanged();}
    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    bool isManagerX() const { return this->m_managerX; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setManagerX(bool manX){ this->m_managerX = manX; emit managerXChanged();}
    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    bool isManagerZ() const { return this->m_managerZ; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setManagerZ(bool manZ){ this->m_managerZ = manZ; emit managerZChanged();}
    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    bool isAdministrator() const { return this->m_administrator; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setAdministrator(bool admin){ this->m_administrator = admin; emit administratorChanged();}



    /*!
    \brief \~french

    \fn roles
    \return int
    */
    int roles() const;

    /*!
    \brief \~french

    \fn isValid
    \return bool
    */
    bool isValid() const;


    /*!
    \brief \~french

    \fn logIn
    \param login
    \param pass
    \return User
    */
    static SH_User *logIn(QString login, QString pass);

    /*!
    \brief \~french

    \fn traineeExists
    \param login
    \return bool
    */
    static bool traineeExists(QString login);

    /*!
    \brief \~french

    \fn userExists
    \param login
    \return bool
    */
    static bool userExists(QString login);

    bool setNewPassword(QString newPass);
    virtual bool save(QString password);
public slots:

    /*!
    \brief \~french

    \fn exists
    \param login
    \return QVariant
    */
    static QVariant exists(QVariant login) {return QVariant(SH_User::userExists(login.toString()) || SH_User::traineeExists(login.toString()));}
signals:

    /*!
    \brief \~french

    \fn nameChanged
    */
    void nameChanged();

    /*!
    \brief \~french

    \fn rolesChanged
    */
    void rolesChanged();

    /*!
    \brief \~french

    \fn validityChanged
    */
    void validityChanged();

    void receptionistChanged();

    void managerXChanged();

    void managerZChanged();

    void administratorChanged();

private:

    /*!
    \brief \~french

    \fn setName
    \param name
    */
    void setName(QString name);

    /*!
    \brief \~french

    \fn setID
    \param id
    */
    void setID(int id);

    /*!
        *\brief \~french this->m_id
        */
    int m_id;

    /*!
    *\brief \~french this->m_name
    */
    QString m_name;

    /*!
    *\brief \~french this->m_receptionist
    */
    bool m_receptionist;

    /*!
    *\brief \~french this->m_managerX
    */
    bool m_managerX;

    /*!
    *\brief \~french this->m_managerZ
    */
    bool m_managerZ;

    /*!
    *\brief \~french this->m_administrator
    */
    bool m_administrator;
};
/*}*/
#endif /* USER_H*/
