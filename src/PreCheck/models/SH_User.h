#ifndef USER_H
#define USER_H
#include <QSqlRecord>
#include <QSqlDriver>
#include <QtCore>



/*!
 \brief

 \class SH_User
\headerfile user.h "models/user.h"
*/
class SH_User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(bool receptionist READ isReceptionist NOTIFY rolesChanged)
    Q_PROPERTY(bool managerX READ isManagerX NOTIFY rolesChanged)
    Q_PROPERTY(bool managerZ READ isManagerZ NOTIFY rolesChanged)
    Q_PROPERTY(bool administrator READ isAdministrator NOTIFY rolesChanged)
    Q_PROPERTY(int roles READ roles NOTIFY rolesChanged)
    Q_PROPERTY(bool valid READ isValid NOTIFY validityChanged)

public:
    /*!
 \brief

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
     \brief

     \fn SH_name
     \return QString
    */
    QString name() const;
    /*!
     \brief

     \fn SH_id
     \return int
    */
    int id() const { return this->m_id; }
    /*!
     \brief

     \fn SH_isReceptionist
     \return bool
    */
    bool isReceptionist() const;
    /*!
     \brief

     \fn SH_isManagerX
     \return bool
    */
    bool isManagerX() const { return this->m_managerX; }
    /*!
     \brief

     \fn SH_isManagerZ
     \return bool
    */
    bool isManagerZ() const { return this->m_managerZ; }
    /*!
     \brief

     \fn SH_isAdministrator
     \return bool
    */
    bool isAdministrator() const { return this->m_administrator; }
    /*!
     \brief

     \fn SH_roles
     \return int
    */
    int roles() const;
    /*!
     \brief

     \fn SH_isValid
     \return bool
    */
    bool isValid() const;

    /*!
     \brief

     \fn SH_logIn
     \param login
     \param pass
     \return User
    */
    static SH_User *logIn(QString login, QString pass);
    /*!
     \brief

     \fn SH_traineeExists
     \param login
     \return bool
    */
    static bool traineeExists(QString login);
    /*!
     \brief

     \fn SH_userExists
     \param login
     \return bool
    */
    static bool userExists(QString login);

public slots:
    /*!
     \brief

     \fn SH_exists
     \param login
     \return QVariant
    */
    static QVariant exists(QVariant login) {return QVariant(SH_User::userExists(login.toString()) || SH_User::traineeExists(login.toString()));}
signals:
    /*!
     \brief

     \fn SH_nameChanged
    */
    void nameChanged();
    /*!
     \brief

     \fn SH_rolesChanged
    */
    void rolesChanged();
    /*!
     \brief

     \fn SH_validityChanged
    */
    void validityChanged();

private:
    /*!
     \brief

     \fn SH_setName
     \param name
    */
    void setName(QString name);
    /*!
     \brief

     \fn SH_setID
     \param id
    */
    void setID(int id);

    /*!
     * \brief m_name
     */
    QString m_name;
    /*!
     * \brief m_receptionist
     */
    bool m_receptionist;
    /*!
     * \brief m_managerX
     */
    bool m_managerX;
    /*!
     * \brief m_managerZ
     */
    bool m_managerZ;
    /*!
     * \brief m_administrator
     */
    bool m_administrator;
    /*!
     * \brief m_id
     */
    int m_id;
};

#endif /* USER_H*/
