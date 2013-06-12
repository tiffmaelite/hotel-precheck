#include "RestrictiveApplication.h"
#include <QDebug>

RestrictiveApplication::RestrictiveApplication(QObject* parent) :
    QObject(parent)
{
    init();
}

RestrictiveApplication::AppMode RestrictiveApplication::mode() const
{
    return m_mode;
}

void RestrictiveApplication::init() {
    this->m_currentUser = new User();
}

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

User *RestrictiveApplication::user() const
{
    return this->m_currentUser;
}

bool RestrictiveApplication::userLogOut()
{
    this->m_currentUser = new User();
    if(!this->m_currentUser->isValid()) {
        emit userLoggedOut();
    }
}

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
