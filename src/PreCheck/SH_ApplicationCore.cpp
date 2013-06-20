#include "SH_ApplicationCore.h"
#include <QDebug>
#include "SH_DatabaseManager.h"
#include "logic/SH_ServiceCharging.h"
#include "logic/SH_BillingCreation.h"


/*!
 \brief

 \fn RestrictiveApplication::RestrictiveApplication
 \param parent
*/

SH_ApplicationCore::SH_ApplicationCore(QObject* parent) :
    QObject(parent)
{
    init();
}

/*!
 \brief

 \fn RestrictiveApplication::mode
 \return RestrictiveApplication::AppMode
*/
SH_ApplicationCore::AppMode SH_ApplicationCore::mode() const
{
    return m_mode;
}

/*!
 \brief

 \fn RestrictiveApplication::init
*/
void SH_ApplicationCore::init() {
    this->m_currentUser = new SH_User();
}

/*!
 \brief

 \fn RestrictiveApplication::setMode
 \param mode
*/
void SH_ApplicationCore::setMode(SH_ApplicationCore::AppMode mode)
{
    if(!this->m_currentUser || ! SH_User::exists(QVariant(this->m_currentUser->name())).toBool()) {
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
SH_User *SH_ApplicationCore::user() const
{
    return this->m_currentUser;
}

/*!
 \brief

 \fn RestrictiveApplication::userLogOut
 \return bool
*/
bool SH_ApplicationCore::userLogOut()
{
    this->m_currentUser = new SH_User();
    return !this->m_currentUser->isValid();
}

/*!
 \brief

 \fn RestrictiveApplication::setUser
 \param login
 \param pass
 \return bool
*/
bool SH_ApplicationCore::setUser(QString login, QString pass)
{
    this->m_currentUser = SH_User::logIn(login,pass);
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
bool SH_ApplicationCore::userExists(QString login)
{
    return SH_User::exists(login).toBool();
}


/*!
 \brief
 \fn RestrictiveApplication::balanceLogRoutine TODO comment this
 \return bool TODO comment this
*/
bool SH_ApplicationCore::balanceLogRoutine() {
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
void SH_ApplicationCore::receiveInput(QString in)
{
    qDebug() << "input received "<<in;
    emit this->m_currentFSM->receiveInput(in);

}

/*!
 \brief
 \fn RestrictiveApplication::receiveValidation TODO comment this
*/
void SH_ApplicationCore::receiveValidation()
{

    emit this->m_currentFSM->validateInput();

}

/*!
 \brief
 \fn RestrictiveApplication::receiveConfirmation TODO comment this
*/
void SH_ApplicationCore::receiveConfirmation()
{

    emit this->m_currentFSM->confirmInput();

}

/*!
 \brief
 \fn RestrictiveApplication::replaceInput TODO comment this
 \param inputName TODO comment this
*/
void SH_ApplicationCore::replaceInput(QString inputName)
{

    emit this->m_currentFSM->replaceInput(inputName);

}

/*!
 \brief
 \fn RestrictiveApplication::cancelReplacement TODO comment this
*/
void SH_ApplicationCore::cancelReplacement()
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
bool SH_ApplicationCore::launchBillingsThread()
{
    qDebug() << "Hallo !";
    /*if(this->m_currentFSM) {
        return false;
    }*/
    qDebug() << "Hallo !";
    this->m_currentFSM= new SH_BillingCreationStateMachine("création facturation");
    this->m_currentFSM->start();
    qDebug() << this->m_currentFSM->toString() << " " << this->m_currentFSM->initialState();
    return this->connectRunningThread();

}

/*!
 \brief

 \fn RestrictiveApplication::launchBookingsThread
 \return bool
*/
bool SH_ApplicationCore::launchBookingsThread()
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
bool SH_ApplicationCore::launchBillThread()
{
    /*if(this->m_currentFSM) {
        return false;
    }*/
    this->m_currentFSM= new SH_ServiceCharging("facturation prestation");
    this->m_currentFSM->setContentValue(QVariant(this->m_currentUser->id()), "BILL_ID");
    this->m_currentFSM->start();
    return this->connectRunningThread();
}

/*!
 \brief

 \fn RestrictiveApplication::cancelRunningThread
 \return bool
*/
bool SH_ApplicationCore::cancelRunningThread()
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
bool SH_ApplicationCore::connectRunningThread()
{
    /*if(!this->m_currentFSM) {
        return false;
    }*/
    qDebug() << "coucou";
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::sendText, this, &SH_ApplicationCore::sendText, Qt::DirectConnection);
        QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::clearAll, this, &SH_ApplicationCore::clearAll, Qt::DirectConnection);
        QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::resendText, this, &SH_ApplicationCore::resendText, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayCalendar, this, &SH_ApplicationCore::displayCalendar, Qt::DirectConnection);
    return this->m_currentFSM->isRunning();
}
