#include "BookingFactory.h"
#include "models/database_manager.h"
#include <QtSql>

/*!
 \brief

 \fn BookingFactory::BookingFactory
 \param parent
*/
BookingFactory::BookingFactory(QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;

}

/*!
 \brief

 \fn BookingFactory::cancelProcess
*/
void BookingFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

/*!
 \brief

 \fn BookingFactory::run
*/
void BookingFactory::run() {

    PreCheckThread::currentStep++;
}

/*!
 \brief

 \fn BookingFactory::receiveInput
 \param text
*/
void BookingFactory::receiveInput(QString text) {
}

/*!
 \brief

 \fn BookingFactory::confirmInput
*/
void BookingFactory::confirmInput()
{
}

/*!
 \brief

 \fn BookingFactory::validateInput
*/
void BookingFactory::validateInput()
{
}

