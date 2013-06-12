#include "NewClientFactory.h"
#include "models/database_manager.h"
#include <QtSql>

/*!
 \brief

 \fn NewClientFactory::NewClientFactory
 \param name
 \param parent
*/
NewClientFactory::NewClientFactory(QString name, QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 4;
    PreCheckThread::content.insert("NAME",name);
}

/*!
 \brief

 \fn NewClientFactory::cancelProcess
*/
void NewClientFactory::cancelProcess()
{
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

/*!
 \brief

 \fn NewClientFactory::run
*/
void NewClientFactory::run() {
    emit PreCheckThread::sendText(QVariant(QObject::tr("Création d'un client\n")));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Nom: %1\n").arg(PreCheckThread::content.value("NAME").toString())));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Voulez-vous entrer l'adresse du client ?\n")));
    PreCheckThread::currentStep++;
}

/*!
 \brief

 \fn NewClientFactory::receiveInput
 \param text
*/
void NewClientFactory::receiveInput(QString text) {
}

/*!
 \brief

 \fn NewClientFactory::confirmInput
*/
void NewClientFactory::confirmInput()
{
}

/*!
 \brief

 \fn NewClientFactory::validateInput
*/
void NewClientFactory::validateInput()
{
}
