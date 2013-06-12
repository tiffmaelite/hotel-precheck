#include "NewBookingFactory.h"
#include "models/database_manager.h"
#include <QtSql>

/*!
 \brief

 \fn NewBookingFactory::NewBookingFactory
 \param parent
*/
NewBookingFactory::NewBookingFactory(QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;

}

/*!
 \brief

 \fn NewBookingFactory::cancelProcess
*/
void NewBookingFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

/*!
 \brief

 \fn NewBookingFactory::run
*/
void NewBookingFactory::run() {

    PreCheckThread::currentStep++;
}

/*!
 \brief

 \fn NewBookingFactory::receiveInput
 \param text
*/
void NewBookingFactory::receiveInput(QString text) {
}

/*!
 \brief

 \fn NewBookingFactory::confirmInput
*/
void NewBookingFactory::confirmInput()
{
}

/*!
 \brief

 \fn NewBookingFactory::validateInput
*/
void NewBookingFactory::validateInput()
{
}
