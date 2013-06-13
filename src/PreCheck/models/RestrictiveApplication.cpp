#include "RestrictiveApplication.h"
#include <QDebug>
#include "models/database_manager.h"

/*!
 \brief

 \fn RestrictiveApplication::RestrictiveApplication
 \param parent
*/

RestrictiveApplication::RestrictiveApplication(QObject* parent) :
    QObject(parent)
{
    init();
}

/*!
 \brief

 \fn RestrictiveApplication::mode
 \return RestrictiveApplication::AppMode
*/
RestrictiveApplication::AppMode RestrictiveApplication::mode() const
{
    return m_mode;
}

/*!
 \brief

 \fn RestrictiveApplication::init
*/
void RestrictiveApplication::init() {
    this->m_currentUser = new User();
}

/*!
 \brief

 \fn RestrictiveApplication::setMode
 \param mode
*/
void RestrictiveApplication::setMode(RestrictiveApplication::AppMode mode)
{
    if(!this->m_currentUser || ! User::exists(QVariant(this->m_currentUser->name())).toBool()) {
        this->m_mode = CONNEXION;
    } else {
        if(((mode == ADMINISTRATION) && (!this->m_currentUser->isAdministrator())) ||
                ((mode == MANAGEMENT_X) && (!this->m_currentUser->isManagerX())) ||
                ((mode == MANAGEMENT_Z) && (!this->m_currentUser->isManagerZ())) ||
                ((mode == RECEPTION) && (!this->m_currentUser->isReceptionist()))) {
            this->m_mode = ACCUEIL;
        } else {
            this->m_mode = mode;
        }
    }
}

/*!
 \brief

 \fn RestrictiveApplication::user
 \return User
*/
User *RestrictiveApplication::user() const
{
    return this->m_currentUser;
}

/*!
 \brief

 \fn RestrictiveApplication::userLogOut
 \return bool
*/
bool RestrictiveApplication::userLogOut()
{
    this->m_currentUser = new User();
    if(!this->m_currentUser->isValid()) {
        emit userLoggedOut();
    }
}

/*!
 \brief

 \fn RestrictiveApplication::setUser
 \param login
 \param pass
*/
void RestrictiveApplication::setUser(QString login, QString pass)
{
    this->m_currentUser = User::logIn(login,pass);
    if(!this->m_currentUser->isValid()) {
        emit badPassword();
    } else {
        emit userLoggedIn();
        emit userChanged(QVariant(this->m_currentUser->name()));
    }
}


/*!
 \brief

 \fn RestrictiveApplication::userExists
 \param login
 \return bool
*/
bool RestrictiveApplication::userExists(QString login)
{
    bool ok = User::exists(login).toBool();
    if(ok) {
        emit userFound();
    } else {
        emit userNotFound();
    }
    return ok;
}


/*!
 \brief
 \fn RestrictiveApplication::balanceLogRoutine TODO comment this
 \return bool TODO comment this
*/
bool RestrictiveApplication::balanceLogRoutine() {
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(H)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(D)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(W)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(M)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(Y)");
}
