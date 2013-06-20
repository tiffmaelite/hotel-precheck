#ifndef USER_H
#define USER_H
#include <QSqlRecord>
#include <QSqlDriver>
#include <QtCore>



/*!
 \brief

 \class User user.h "models/user.h"
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

 \fn User
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

     \fn name
     \return QString
    */
    QString name() const;
    /*!
     \brief

     \fn id
     \return int
    */
    int id() const { return this->m_id; }
    /*!
     \brief

     \fn isReceptionist
     \return bool
    */
    bool isReceptionist() const;
    /*!
     \brief

     \fn isManagerX
     \return bool
    */
    bool isManagerX() const { return this->m_managerX; }
    /*!
     \brief

     \fn isManagerZ
     \return bool
    */
    bool isManagerZ() const { return this->m_managerZ; }
    /*!
     \brief

     \fn isAdministrator
     \return bool
    */
    bool isAdministrator() const { return this->m_administrator; }
    /*!
     \brief

     \fn roles
     \return int
    */
    int roles() const;
    /*!
     \brief

     \fn isValid
     \return bool
    */
    bool isValid() const;

    /*!
     \brief

     \fn logIn
     \param login
     \param pass
     \return User
    */
    static SH_User *logIn(QString login, QString pass);
    /*!
     \brief

     \fn traineeExists
     \param login
     \return bool
    */
    static bool traineeExists(QString login);
    /*!
     \brief

     \fn userExists
     \param login
     \return bool
    */
    static bool userExists(QString login);

public slots:
    /*!
     \brief

     \fn exists
     \param login
     \return QVariant
    */
    static QVariant exists(QVariant login) {return QVariant(SH_User::userExists(login.toString()) || SH_User::traineeExists(login.toString()));}
signals:
    /*!
     \brief

     \fn nameChanged
    */
    void nameChanged();
    /*!
     \brief

     \fn rolesChanged
    */
    void rolesChanged();
    /*!
     \brief

     \fn validityChanged
    */
    void validityChanged();

private:
    /*!
     \brief

     \fn setName
     \param name
    */
    void setName(QString name);
    /*!
     \brief

     \fn setID
     \param id
    */
    void setID(int id);

    QString m_name; /*!< TODO */
    bool m_receptionist; /*!< TODO */
    bool m_managerX; /*!< TODO */
    bool m_managerZ; /*!< TODO */
    bool m_administrator; /*!< TODO */
    int m_id; /*!< TODO */
};

#endif // USER_H
