#include "BookingFactory.h"
#include "models/database_manager.h"
#include <QtSql>

BookingFactory::BookingFactory(QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;

}

void BookingFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

void BookingFactory::run() {

    PreCheckThread::currentStep++;
}

void BookingFactory::receiveInput(QString text) {
}

void BookingFactory::confirmInput()
{
}

void BookingFactory::validateInput()
{
}

