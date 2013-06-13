#include "servicecharging.h"
#include "validationstate.h"
#include "databasecontentquestionstate.h"
#include "stringquestionstate.h"
#include "decimalquestionstate.h"
#include "models/database_manager.h"
#include <QtSql>

ServiceCharging::ServiceCharging(QString name, QObject *parent) :
    LoopingIOStateMachine("CHARGEDSERVICES",name, 0, parent), m_priceMin(0.0)
{
    DatabaseContentQuestionState* service = new DatabaseContentQuestionState("Veuillez sélectionner une prestation ou appuyer sur la touche \"VALIDER\" pour cesser d'ajouter des prestations", "choose service in service charging","SERVICES","CODE");
    IOState*serviceId = new IOState("","service id in service charging");
    serviceId->setVisibility(false);
    StringQuestionState* serviceName = new StringQuestionState("Veuillez entrer ce qui sera affiché sur la facture", "service name in service charging",1);
    DecimalQuestionState* price = new DecimalQuestionState("", "price in service charging",-Q_INFINITY,Q_INFINITY);
    DecimalQuestionState* quantity = new DecimalQuestionState("", "quantity in service charging",1);
    DatabaseContentQuestionState* vat = new DatabaseContentQuestionState("", "vat in service charging","TAXES","PERCENTAGE","ENABLED='1'");
    QFinalState* final = new QFinalState();


    connect(service, &QuestionState::answerInvalid, [=]() {
        int in = service->rawInput().toInt();
        if(in == -1 || in == 0) {
            emit service->next();
        }
    });
    connect(service, &QuestionState::answerValid, [=]() {
        if(service->rawInput().toInt() > -1) {
            QString name;
            QStringList list;
            list.append("PRINTEDNAME");
            list.append("PRICEMIN");
            list.append("PRICEMAX");
            list.append("VAT_PERCENTAGE");
            list.append("ID");
            QSqlQuery result = AppDatabase::getInstance()->execSelectQuery("SERVICESINFOS", list, QString("CODE=%1").arg(service->rawInput().toString()));
            result.next();
            QSqlRecord record = result.record();
            name= record.value(0).toString();
            m_priceMin =record.value(1).toDouble();
            m_vat =record.value(3).toDouble();
            serviceId->setInput(record.value(4).toInt());
            serviceName->setInput(name);
            price->setOutput(QString("Le prix proposé pour cette prestation est : %1. Son prix minimum est %1 et son prix maximum %2.\nVeuillez entrer un nouveau prix ou appuyer sur la touche \"CONFIRMER\"").arg(record.value(1).toString()).arg(record.value(2).toString()));
            vat->setOutput(QString("Cette prestation est associée à une TVA de %1\%.\nVeuillez entrer une autre TVA à appliquer ou appuyer sur la touche \"CONFIRMER\"").arg(record.value(3).toString()));
            serviceName->setVisibility(false);
        }
    });
    connect(quantity, &QState::entered, [=]() {
        connect(this, &IOStateMachine::receiveInput, [=](QString in) {
            QString newInput;
            if(in.right(in.length() - 1).toInt() != 0) {
                newInput = in.right(in.length() - 1);
            }
            emit receiveInput(newInput);
        });
    });
    connect(price, &QState::entered, [=]() {
        connect(this, &IOStateMachine::confirmInput, [=]() {
            price->setInput(m_priceMin);
        });
    });
    connect(vat, &QState::entered, [=]() {
        connect(this, &IOStateMachine::confirmInput, [=]() {
            vat->setInput(m_vat);
        });
    });


    this->addState(final);
    this->addIOState(service, "");
    this->addIOState(serviceId, "SERVICE_ID");
    this->addIOState(serviceName, "PRINTEDNAME");
    this->addIOState(price, "CHARGEDUNITPRICE");
    this->addIOState(quantity, "QUANTITY");
    this->addIOState(vat, "CHARGEDVAT");
    this->addChildrenNextTransition(service, serviceId);
    this->addChildrenNextTransition(serviceId, serviceName);
    this->addChildrenNextTransition(serviceName, quantity);
    this->addChildrenNextTransition(quantity, price);
    this->addChildrenNextTransition(price, vat);
    this->addChildrenNextTransition(vat, final);
    this->setInitialState(service);
    connect(this, &IOStateMachine::validateInput, this, &LoopingIOStateMachine::stopLooping);
}
