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
 * \fn SH_ApplicationCore::SH_ApplicationCore
*/
SH_ApplicationCore::SH_ApplicationCore(QObject* parent) :
    QObject(parent), m_currentFSMNotNull(false), m_currentFSM(NULL)
{
    init();
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
    if(!this->m_currentUser->isValid() || ! SH_ApplicationCore::userExists(this->m_currentUser->name())) {
        this->m_mode = CONNEXION;
    } else {
        if(
                ((mode == ADMINISTRATION) && (!this->m_currentUser->isAdministrator())) ||
                ((mode == MANAGEMENT_X) && (!this->m_currentUser->isManagerX())) ||
                ((mode == MANAGEMENT_Z) && (!this->m_currentUser->isManagerZ())) ||
                ((mode == RECEPTION) && (!this->m_currentUser->isReceptionist()))
                ) {
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
        emit userChanged(QVariant(this->m_currentUser->property("name").value<QString>()));
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
bool SH_ApplicationCore::balanceLogRoutine(QString period) {
    QChar p = period.at(0).toUpper();
    QSqlQuery result;
    if(p == 'H') {
        result= SH_DatabaseManager::getInstance()->execProcedure(QString("restarthourlybalance(%1,%2,%3,%4)").arg(QString::number(QDate::currentDate().year())).arg(QString::number(QDate::currentDate().month())).arg(QString::number(QDate::currentDate().day())).arg(QString::number(QTime::currentTime().hour())));
    } else if(p == 'D') {
        result= SH_DatabaseManager::getInstance()->execProcedure(QString("restartdailybalance(%1,%2,%3)").arg(QString::number(QDate::currentDate().year())).arg(QString::number(QDate::currentDate().month())).arg(QString::number(QDate::currentDate().day())));
    } else if(p == 'M') {
        result= SH_DatabaseManager::getInstance()->execProcedure(QString("restartmonthlybalance(%1,%2)").arg(QString::number(QDate::currentDate().year())).arg(QString::number(QDate::currentDate().month())));
    } else if(p == 'Y') {
        result= SH_DatabaseManager::getInstance()->execProcedure(QString("restartyearlybalance(%1)").arg(QString::number(QDate::currentDate().year())));
    }
    result.first();
    if(result.isValid()) {
        return result.value(1).toBool();
    }
    return false;
}

/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveInput
*/
void SH_ApplicationCore::receiveInput(QString in)
{
    if(this->m_currentFSMNotNull) {
        emit this->m_currentFSM->receiveInput(in);
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveValidation
*/
void SH_ApplicationCore::receiveValidation()
{
    if(this->m_currentFSMNotNull) {
        emit this->m_currentFSM->validateInput();
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::receiveConfirmation
*/
void SH_ApplicationCore::receiveConfirmation()
{
    if(this->m_currentFSMNotNull) {
        emit this->m_currentFSM->confirmInput();
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::replaceInput
*/
void SH_ApplicationCore::replaceInput(QString inputName)
{
    if(this->m_currentFSMNotNull) {
        emit this->m_currentFSM->replaceInput(inputName);
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::cancelReplacement
*/
void SH_ApplicationCore::cancelReplacement()
{
    if(this->m_currentFSMNotNull) {
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
    this->m_currentFSMNotNull = true;
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
    this->m_currentFSMNotNull = true;
    this->m_currentFSM->setContentValue(QString::number(this->m_currentUser->id()), "BILL_ID");
    return this->launchStateMachine();
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::stopRunningStateMachine
*/
bool SH_ApplicationCore::stopRunningStateMachine()
{
    if(this->m_currentFSMNotNull) {
        this->m_currentFSM->stop();
        bool ok = !this->m_currentFSM->isRunning();
        this->m_currentFSM = NULL;
        return ok;
    }
    return false;
}
void SH_ApplicationCore::cancelLastStep()
{
    if(this->m_currentFSMNotNull) {
        emit this->m_currentFSM->replaceInput(this->m_currentFSM->previousStateField());
    }
}
/*!
 * \details \~french
 * \fn SH_ApplicationCore::launchStateMachine
*/
bool SH_ApplicationCore::launchStateMachine()
{
    //QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::sendText, this, &SH_ApplicationCore::sendText, Qt::DirectConnection);
    //QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::resendText, this, &SH_ApplicationCore::resendText, Qt::DirectConnection);

    QObject::connect(this->m_currentFSM, SIGNAL(sendText(QString, int, int)), this, SIGNAL(sendText(QString, int, int)), Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, SIGNAL(sendTextForRow(QString, int)), this, SIGNAL(sendText(QString, int)), Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, SIGNAL(sendTextAuto(QString)), this, SIGNAL(sendText(QString)), Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, SIGNAL(resendText(QString, int, int)), this, SIGNAL(resendText(QString, int, int)), Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, SIGNAL(resendTextForRow(QString, int)), this, SIGNAL(resendText(QString, int)), Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, SIGNAL(resendTextAuto(QString)), this, SIGNAL(resendText(QString)), Qt::DirectConnection);

    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::clearAll, this, &SH_ApplicationCore::clearAll, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayCalendar, this, &SH_ApplicationCore::displayCalendar, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayChoiceList, [=](QVariantList list, int row) {this->displayChoiceList(QVariant(list),row);});
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayFileDialog, this, &SH_ApplicationCore::displayFileDialog, Qt::DirectConnection);
    QObject::connect(this->m_currentFSM, &SH_InOutStateMachine::displayProgressBar, this, &SH_ApplicationCore::displayProgressBar, Qt::DirectConnection);
    emit clearAll();
    this->m_currentFSM->start();
    return this->m_currentFSM->isRunning();
}

int SH_ApplicationCore::billOpened() {
    if(this->m_currentFSMNotNull) {
        SH_ServiceCharging* smachine = qobject_cast<SH_ServiceCharging*>(this->m_currentFSM);
        if(smachine) {
            return smachine->getContentValue("ID").toInt();
        }
    }
    return -1;
}

void SH_ApplicationCore::setSettings(QString iniFile)
{
    this->m_settingsFile = iniFile;
}

QVariant SH_ApplicationCore::readSetting(QString key, QString group)
{
    QSettings settings(this->m_settingsFile,QSettings::IniFormat);
    //SH_MessageManager::infoMessage(QString("Les clefs disponibles sont %1").arg(settings.allKeys().join(", ")));
    if(!group.isEmpty()) {
        settings.beginGroup(group);
    }
    QVariant value = settings.value(key);
    //SH_MessageManager::infoMessage(QString("Read setting for %1 in %2 : %3").arg(key).arg(group).arg(value.toString()));
    if(!group.isEmpty()) {
        settings.endGroup();
    }
    return value;
}

QString SH_ApplicationCore::readStringSetting(QString key, QString group)
{
    return readSetting(key, group).toString();
}

void SH_ApplicationCore::replaceSetting(QString key, QVariant value, QString group)
{
    writeSetting(key, value, group, true);
}

void SH_ApplicationCore::writeSetting(QString key, QVariant value, QString group, bool replace)
{
    QSettings settings(this->m_settingsFile,QSettings::IniFormat);
    if(!group.isEmpty()) {
        settings.beginGroup(group);
    }
    if(!settings.contains(key) || replace) { //not yet set or to be replaced
        settings.setValue(key,value);
        //SH_MessageManager::infoMessage(QString("Write settings %1 for %2 in %3").arg(value.toString()).arg(key).arg(group));
    }
    if(!group.isEmpty()) {
        settings.endGroup();
    }
    settings.sync();
}

/*}*/
