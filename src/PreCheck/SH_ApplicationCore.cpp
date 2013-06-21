#include "SH_ApplicationCore.h"
#include <QDebug>
#include "SH_DatabaseManager.h"
#include "logic/SH_ServiceCharging.h"
#include "logic/SH_BillingCreation.h"


/*!
 \details \~french

 \fn SH_ApplicationCore::RestrictiveApplication
*/

SH_ApplicationCore::SH_ApplicationCore(QObject* parent) :
    QObject(parent)
{
    init();
}

/*!
 \details \~french

 \fn SH_ApplicationCore::mode
*/
SH_ApplicationCore::AppMode SH_ApplicationCore::mode() const
{
    return m_mode;
}

/*!
 \details \~french

 \fn SH_ApplicationCore::init
*/
void SH_ApplicationCore::init() {
    this->m_currentUser = new SH_User();
}

/*!
 \details \~french

 \fn SH_ApplicationCore::setMode
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
 \details \~french

 \fn SH_ApplicationCore::user
*/
SH_User *SH_ApplicationCore::user() const
{
    return this->m_currentUser;
}

/*!
 \details \~french

 \fn SH_ApplicationCore::userLogOut
*/
bool SH_ApplicationCore::userLogOut()
{
    this->m_currentUser = new SH_User();
    return !this->m_currentUser->isValid();
}

/*!
 \details \~french

 \fn SH_ApplicationCore::setUser
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
 \details \~french

 \fn SH_ApplicationCore::userExists
*/
bool SH_ApplicationCore::userExists(QString login)
{
    return SH_User::exists(login).toBool();
}


/*!
 \details \~french
 \fn SH_ApplicationCore::balanceLogRoutine TODO comment this
*/
bool SH_ApplicationCore::balanceLogRoutine() {
    /*AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(H)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(D)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(W)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(M)");
    AppDatabase::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(Y)");*/
}


/*!
 \details \~french
 \fn SH_ApplicationCore::receiveInput TODO comment this
*/
void SH_ApplicationCore::receiveInput(QString in)
{
    qDebug() << "input received "<<in;
    emit this->m_currentFSM->receiveInput(in);

}

/*!
 \details \~french
 \fn SH_ApplicationCore::receiveValidation TODO comment this
*/
void SH_ApplicationCore::receiveValidation()
{

    emit this->m_currentFSM->validateInput();

}

/*!
 \details \~french
 \fn SH_ApplicationCore::receiveConfirmation TODO comment this
*/
void SH_ApplicationCore::receiveConfirmation()
{

    emit this->m_currentFSM->confirmInput();

}

/*!
 \details \~french
 \fn SH_ApplicationCore::replaceInput TODO comment this
*/
void SH_ApplicationCore::replaceInput(QString inputName)
{

    emit this->m_currentFSM->replaceInput(inputName);

}

/*!
 \details \~french
 \fn SH_ApplicationCore::cancelReplacement TODO comment this
*/
void SH_ApplicationCore::cancelReplacement()
{
    if(this->m_currentFSM) {
        emit this->m_currentFSM->cancelReplacement();
    }
}


/*!
 \details \~french

 \fn SH_ApplicationCore::launchBillingsThread
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
 \details \~french

 \fn SH_ApplicationCore::launchBookingsThread
*/
bool SH_ApplicationCore::launchBookingsThread()
{
    /*if(this->m_currentFSM) {
        return false;
    }*/
    /*this->m_currentFSM= new BookingCreationStateMachine("création facturation");*/
    /*this->m_currentFSM->start();*/
    return this->connectRunningThread();
}

/*!
 \details \~french

 \fn SH_ApplicationCore::launchBillThread
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
 \details \~french

 \fn SH_ApplicationCore::cancelRunningThread
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
 \details \~french

 \fn SH_ApplicationCore::connectRunningThread
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