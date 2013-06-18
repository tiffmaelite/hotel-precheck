#include "RestrictiveApplication.h"
#include <QDebug>
#include "models/database_manager.h"
#include "logic/servicecharging.h"
#include "logic/billingcreation.h"


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
    return !this->m_currentUser->isValid();
}

/*!
 \brief

 \fn RestrictiveApplication::setUser
 \param login
 \param pass
 \return bool
*/
bool RestrictiveApplication::setUser(QString login, QString pass)
{
    this->m_currentUser = User::logIn(login,pass);
    if(this->m_currentUser->isValid()) {
        emit userChanged(QVariant(this->m_currentUser->name()));
        return true;
    }
    return false;
}


/*!
 \brief

 \fn RestrictiveApplication::userExists
 \param login
 \return bool
*/
bool RestrictiveApplication::userExists(QString login)
{
    return User::exists(login).toBool();
}


/*!
 \brief
 \fn RestrictiveApplication::balanceLogRoutine TODO comment this
 \return bool TODO comment this
*/
bool RestrictiveApplication::balanceLogRoutine() {
    /*AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(H)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(D)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(W)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(M)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(Y)");*/
}


/*!
 \brief
 \fn RestrictiveApplication::receiveInput TODO comment this
 \param in TODO comment this
*/
void RestrictiveApplication::receiveInput(QString in)
{
    qDebug() << "input received "<<in;
    emit this->m_currentFSM->receiveInput(in);

}

/*!
 \brief
 \fn RestrictiveApplication::receiveValidation TODO comment this
*/
void RestrictiveApplication::receiveValidation()
{

    emit this->m_currentFSM->validateInput();

}

/*!
 \brief
 \fn RestrictiveApplication::receiveConfirmation TODO comment this
*/
void RestrictiveApplication::receiveConfirmation()
{

    emit this->m_currentFSM->confirmInput();

}

/*!
 \brief
 \fn RestrictiveApplication::replaceInput TODO comment this
 \param inputName TODO comment this
*/
void RestrictiveApplication::replaceInput(QString inputName)
{

    emit this->m_currentFSM->replaceInput(inputName);

}

/*!
 \brief
 \fn RestrictiveApplication::cancelReplacement TODO comment this
*/
void RestrictiveApplication::cancelReplacement()
{
    if(this->m_currentFSM) {
        emit this->m_currentFSM->cancelReplacement();
    }
}


/*!
 \brief

 \fn RestrictiveApplication::launchBillingsThread
 \return bool
*/
bool RestrictiveApplication::launchBillingsThread()
{
    qDebug() << "Hallo !";
    /*if(this->m_currentFSM) {
        return false;
    }*/
    qDebug() << "Hallo !";
    this->m_currentFSM= new BillingCreationStateMachine("création facturation");
    this->m_currentFSM->start();
    qDebug() << this->m_currentFSM->toString() << " " << this->m_currentFSM->initialState();
    return this->connectRunningThread();

}

/*!
 \brief

 \fn RestrictiveApplication::launchBookingsThread
 \return bool
*/
bool RestrictiveApplication::launchBookingsThread()
{
    /*if(this->m_currentFSM) {
        return false;
    }*/
    //this->m_currentFSM= new BookingCreationStateMachine("création facturation");
    //this->m_currentFSM->start();
    return this->connectRunningThread();
}

/*!
 \brief

 \fn RestrictiveApplication::launchBillThread
 \return bool
*/
bool RestrictiveApplication::launchBillThread()
{
    /*if(this->m_currentFSM) {
        return false;
    }*/
    this->m_currentFSM= new ServiceCharging("facturation prestation");
    this->m_currentFSM->setContentValue(QVariant(this->m_currentUser->id()), "BILL_ID");
    this->m_currentFSM->start();
    return this->connectRunningThread();
}

/*!
 \brief

 \fn RestrictiveApplication::cancelRunningThread
 \return bool
*/
bool RestrictiveApplication::cancelRunningThread()
{
    /*if(!this->m_currentFSM) {
        return true;
    }*/
    this->m_currentFSM->stop();
    bool ok = !this->m_currentFSM->isRunning();
    this->m_currentFSM = NULL;
    return ok;
}


/*!
 \brief

 \fn RestrictiveApplication::connectRunningThread
 \return bool
*/
bool RestrictiveApplication::connectRunningThread()
{
    /*if(!this->m_currentFSM) {
        return false;
    }*/
    qDebug() << "coucou";
    QObject::connect(this->m_currentFSM, &IOStateMachine::sendText, this, &RestrictiveApplication::sendText, Qt::DirectConnection);
        QObject::connect(this->m_currentFSM, &IOStateMachine::clearAll, this, &RestrictiveApplication::clearAll, Qt::DirectConnection);
        QObject::connect(this->m_currentFSM, &IOStateMachine::resendText, this, &RestrictiveApplication::resendText, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &IOStateMachine::displayCalendar, this, &RestrictiveApplication::displayCalendar, Qt::DirectConnection);
    return this->m_currentFSM->isRunning();
}
