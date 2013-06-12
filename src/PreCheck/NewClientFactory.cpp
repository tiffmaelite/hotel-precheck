#include "NewClientFactory.h"
#include "models/database_manager.h"
#include <QtSql>

NewClientFactory::NewClientFactory(QString name, QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;
    PreCheckThread::content.insert("NAME",name);
}

void NewClientFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

void NewClientFactory::run() {
    emit PreCheckThread::sendText(QVariant(QObject::tr("Création d'un client\n")));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Nom: %1\n").arg(PreCheckThread::content.value("NAME").toString())));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Voulez-vous entrer l'adresse du client ?\n")));
    PreCheckThread::currentStep++;
}

void NewClientFactory::receiveInput(QString text) {
}

void NewClientFactory::confirmInput()
{
}

void NewClientFactory::validateInput()
{
}
