#ifndef RESTRICTIVEAPPLICATION_H
#define RESTRICTIVEAPPLICATION_H
#include "user.h"
#include <QApplication>

/*!
 \brief

 \class RestrictiveApplication RestrictiveApplication.h "models/RestrictiveApplication.h"
*/
class RestrictiveApplication : public QObject
{
    Q_OBJECT
    Q_PROPERTY(User* currentUser READ user NOTIFY userChanged)
    Q_PROPERTY(AppMode currentMode READ mode WRITE setMode NOTIFY modeChanged)
    Q_ENUMS(AppMode)
public:
    /*!
     \brief

     \enum AppMode
    */
    enum AppMode { CONNEXION, ACCUEIL, RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };
/*!
 \brief

 \fn RestrictiveApplication
 \param parent
*/
    RestrictiveApplication(QObject* parent=0);
    /*!
     \brief

     \fn mode
     \return AppMode
    */
    AppMode mode() const;
    /*!
     \brief

     \fn user
     \return User
    */
    User* user() const;
    //Q_INVOKABLE User* currentUser() const;
    /*!
     \brief

     \fn init
    */
    void init();
    /*!
     \brief

     \fn setMode
     \param mode
    */
    void setMode(AppMode mode);

signals:
    /*!
     \brief

     \fn userChanged
     \param name
    */
    void userChanged(QVariant name);
    /*!
     \brief

     \fn modeChanged
     \param mode
    */
    void modeChanged(QVariant mode);
    /*!
     \brief

     \fn userFound
    */
    void userFound();
    /*!
     \brief

     \fn userNotFound
    */
    void userNotFound();
    /*!
     \brief

     \fn userLoggedIn
    */
    void userLoggedIn();
    /*!
     \brief

     \fn userLoggedOut
    */
    void userLoggedOut();
    /*!
     \brief

     \fn badPassword
    */
    void badPassword();

public slots:
    /*!
     \brief

     \fn userExists
     \param login
     \return bool
    */
    bool userExists(QString login);
    /*!
     \brief

     \fn setUser
     \param login
     \param pass
    */
    void setUser(QString login, QString pass);
    /*!
     \brief

     \fn userLogOut
     \return bool
    */
    bool userLogOut();

private:
    User* m_currentUser; /*!< TODO */
    AppMode m_mode; /*!< TODO */
    
};

#endif // RESTRICTIVEAPPLICATION_H
