#include "NewBookingFactory.h"
#include "models/database_manager.h"
#include <QtSql>

NewBookingFactory::NewBookingFactory(QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;

}

void NewBookingFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

void NewBookingFactory::run() {

    PreCheckThread::currentStep++;
}

void NewBookingFactory::receiveInput(QString text) {
}

void NewBookingFactory::confirmInput()
{
}

void NewBookingFactory::validateInput()
{
}
