#include "BillingFactory.h"
#include "models/database_manager.h"
#include <QtSql>

BillingFactory::BillingFactory(QObject *parent) : PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;

}

/*!
 \brief

 \fn BillingFactory::cancelProcess
*/
void BillingFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

/*!
 \brief

 \fn BillingFactory::run
*/
void BillingFactory::run() {

    PreCheckThread::currentStep++;
}

/*!
 \brief

 \fn BillingFactory::receiveInput
 \param text
*/
void BillingFactory::receiveInput(QString text) {
}

/*!
 \brief

 \fn BillingFactory::confirmInput
*/
void BillingFactory::confirmInput()
{
}

/*!
 \brief

 \fn BillingFactory::validateInput
*/
void BillingFactory::validateInput()
{
}



