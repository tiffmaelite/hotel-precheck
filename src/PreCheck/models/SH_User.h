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
    Q_PROPERTY(int ID MEMBER m_id WRITE setID NOTIFY idChanged)
    Q_PROPERTY(QString name MEMBER m_name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool receptionist MEMBER m_receptionist NOTIFY receptionistChanged)
    Q_PROPERTY(bool managerX MEMBER m_managerX NOTIFY managerXChanged)
    Q_PROPERTY(bool managerZ MEMBER m_managerZ NOTIFY managerZChanged)
    Q_PROPERTY(bool administrator MEMBER m_administrator NOTIFY rolesChanged)
    Q_PROPERTY(int roles READ roles NOTIFY rolesChanged)
    Q_PROPERTY(bool valid READ isValid NOTIFY validityChanged)

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
    *\brief \~french m_name
    */
    QString m_name;

/*!
    *\brief \~french m_receptionist
    */
    bool m_receptionist;

/*!
    *\brief \~french m_managerX
    */
    bool m_managerX;

/*!
    *\brief \~french m_managerZ
    */
    bool m_managerZ;

/*!
    *\brief \~french m_administrator
    */
    bool m_administrator;

/*!
    *\brief \~french m_id
    */
    int m_id;
};
/*}*/
#endif /* USER_H*/
