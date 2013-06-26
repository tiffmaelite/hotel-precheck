#include "SH_ApplicationCore.h"
#include <QDebug>
#include "SH_MessageManager.h"
#include "SH_DatabaseManager.h"
#include "logic/SH_ServiceCharging.h"
#include "logic/SH_BillingCreation.h"
#include "models/SH_Trainee.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_ApplicationCore::RestrictiveApplication
*/
SH_ApplicationCore::SH_ApplicationCore(QObject* parent) :
    QObject(parent), m_currentFSMNotNull(false), m_currentFSM(NULL)
{
    init();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::mode
*/
SH_ApplicationCore::AppMode SH_ApplicationCore::mode() const
{
    return m_mode;
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::init
*/
void SH_ApplicationCore::init() {
    this->m_currentUser = new SH_User();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::setMode
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
 * \details \~french
 * \fn SH_ApplicationCore::user
*/
SH_User *SH_ApplicationCore::user() const
{
    return this->m_currentUser;
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::userLogOut
*/
bool SH_ApplicationCore::userLogOut()
{
    this->m_currentUser = new SH_User();
    return !this->m_currentUser->isValid();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::setUser
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

bool SH_ApplicationCore::saveUser(QString login, QString pass, bool isTrainee, bool isReceptionist, bool isManX, bool isManZ, bool isAdmin)
{
    if(!isTrainee) {
        SH_User* newUser = new SH_User(login, 0, isReceptionist, isManX, isManZ,isAdmin);
        return newUser->save(pass);
    } else {
        SH_Trainee* newTrainee = new SH_Trainee(login);
        return newTrainee->save(pass);
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::userExists
*/
bool SH_ApplicationCore::userExists(QString login)
{
    return SH_User::exists(login).toBool();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::balanceLogRoutine
*/
bool SH_ApplicationCore::balanceLogRoutine() {

    /*SH_DatabaseManager::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(H)");
    SH_DatabaseManager::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(D)");
    SH_DatabaseManager::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(W)");
    SH_DatabaseManager::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(M)");
    SH_DatabaseManager::getInstance()->getDbConnection().exec("execute procedure logPeriodicBalance(Y)");*/
    return true;
}

qreal SH_ApplicationCore::todayBalance() {
    QSqlQuery result = SH_DatabaseManager::getInstance()->execSelectQuery("DAYLYBALCOUNT", QStringList("BALANCE"), "TIMESTAMP = (SELECT MAX(TIMESTAMP) FROM YEARLYLOGBALCOUNT)");
    result.next();
    return result.value("BALANCE").toReal();
}

qreal SH_ApplicationCore::totalBalance() {
    QSqlQuery result =  SH_DatabaseManager::getInstance()->execSelectQuery("YEARLYLOGBALCOUNT", QStringList("BALANCE"), "TIMESTAMP = (SELECT MAX(TIMESTAMP) FROM YEARLYLOGBALCOUNT)");
    result.next();
    return result.value("BALANCE").toReal();
}

/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveInput
*/
void SH_ApplicationCore::receiveInput(QString in)
{
    if(m_currentFSMNotNull) {
        SH_MessageManager::infoMessage("input received "+in);
        emit this->m_currentFSM->receiveInput(in);
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveValidation
*/
void SH_ApplicationCore::receiveValidation()
{
    if(m_currentFSMNotNull) {
        emit this->m_currentFSM->validateInput();
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveConfirmation
*/
void SH_ApplicationCore::receiveConfirmation()
{
    if(m_currentFSMNotNull) {
        emit this->m_currentFSM->confirmInput();
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::replaceInput
*/
void SH_ApplicationCore::replaceInput(QString inputName)
{
    if(m_currentFSMNotNull) {
        emit this->m_currentFSM->replaceInput(inputName);
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::cancelReplacement
*/
void SH_ApplicationCore::cancelReplacement()
{
    if(m_currentFSMNotNull) {
        emit this->m_currentFSM->cancelReplacement();
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::launchBillingCreation
*/
bool SH_ApplicationCore::launchBillingCreation()
{
    this->m_currentFSM= new SH_BillingCreationStateMachine("création facturation");
    m_currentFSMNotNull = true;
    return this->launchStateMachine();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::launchBookingCreation
*/
bool SH_ApplicationCore::launchBookingCreation()
{
    /*this->m_currentFSM= new BookingCreationStateMachine("création facturation");
    this->m_currentFSMNotNull = true;*/
    return this->launchStateMachine();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::launchServiceCharging
*/
bool SH_ApplicationCore::launchServiceCharging()
{
    this->m_currentFSM= new SH_ServiceCharging("facturation prestation");
    m_currentFSMNotNull = true;
    this->m_currentFSM->setContentValue(QVariant(this->m_currentUser->id()), "BILL_ID");
    return this->launchStateMachine();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::stopRunningStateMachine
*/
bool SH_ApplicationCore::stopRunningStateMachine()
{
    if(m_currentFSMNotNull) {
        this->m_currentFSM->stop();
        bool ok = !this->m_currentFSM->isRunning();
        this->m_currentFSM = NULL;
        return ok;
    }
    return false;
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::launchStateMachine
*/
bool SH_ApplicationCore::launchStateMachine()
{
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::sendText, this, &SH_ApplicationCore::sendText, Qt::DirectConnection);
    /*QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::sendText, [=](QString text, bool editable) { SH_MessageManager::infoMessage(text,"reçu de la machine"); emit this->sendText(text, editable);});*/
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::clearAll, this, &SH_ApplicationCore::clearAll, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::resendText, this, &SH_ApplicationCore::resendText, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayCalendar, this, &SH_ApplicationCore::displayCalendar, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayChoiceList, [=](QVariantList list) {this->displayChoiceList(QVariant(list));});
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayFileDialog, this, &SH_ApplicationCore::displayFileDialog, Qt::DirectConnection);
    emit clearAll();
    this->m_currentFSM->start();
    return this->m_currentFSM->isRunning();
}

int SH_ApplicationCore::billOpened() {
    if(m_currentFSMNotNull) {
        SH_ServiceCharging* smachine = qobject_cast<SH_ServiceCharging*>(this->m_currentFSM);
        if(smachine) {
            return smachine->getContentValue("ID").toInt();
        }
    }
    return -1;
}

void SH_ApplicationCore::setSettings(QSettings::Scope scope, QString devName, QString appName)
{
    QSettings m_settings(scope, devName, appName);
}

QVariant SH_ApplicationCore::readSetting(QString key, QString group)
{
    if(group != "") {
        m_settings.beginGroup(group);
    }
    QVariant value = m_settings.value(key);
    if(group != "") {
        m_settings.endGroup();
    }
    return value;
}

void SH_ApplicationCore::writeSetting(QString key, QVariant value, QString group)
{
    if(group != "") {
        m_settings.beginGroup(group);
    }
    m_settings.setValue(key,value);
    if(group != "") {
        m_settings.endGroup();
    }
}

/*}*/
