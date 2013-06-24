#include "SH_ServiceCharging.h"
#include "SH_ValidationState.h"
#include "SH_DatabaseContentQuestionState.h"
#include "SH_StringQuestionState.h"
#include "SH_DecimalQuestionState.h"
#include "SH_DatabaseManager.h"
#include <QtSql>

/*!
 * \details \~french SH_ServiceCharging::SH_ServiceCharging
 */
SH_ServiceCharging::SH_ServiceCharging(QString name, QObject *parent) :
    SH_LoopingInOutStateMachine("CHARGEDSERVICES",name, 0, parent), m_priceMin(0.0)
{
    SH_DatabaseContentQuestionState* service = new SH_DatabaseContentQuestionState("Veuillez sélectionner une prestation ou appuyer sur la touche \"VALIDER\" pour cesser d'ajouter des prestations", "choose service in service charging","SERVICES","CODE");
    SH_InOutState*serviceId = new SH_InOutState("","service id in service charging");
    serviceId->setVisibility(false);
    SH_StringQuestionState* serviceName = new SH_StringQuestionState("Veuillez entrer ce qui sera affiché sur la facture", "service name in service charging",1);
    SH_DecimalQuestionState* price = new SH_DecimalQuestionState("", "price in service charging",-Q_INFINITY,Q_INFINITY);
    SH_DecimalQuestionState* quantity = new SH_DecimalQuestionState("", "quantity in service charging",1);
    SH_DatabaseContentQuestionState* vat = new SH_DatabaseContentQuestionState("", "vat in service charging","TAXES","PERCENTAGE","ENABLED='1'");
    QFinalState* final = new QFinalState();


    connect(service, &SH_QuestionState::answerInvalid, [=]() {
        int in = service->rawInput().toInt();
        if(in == -1 || in == 0) {
            emit service->goNext();
        }
    });
    connect(service, &SH_QuestionState::answerValid, [=]() {
        if(service->rawInput().toInt() > -1) {
            QString name;
            QStringList list;
            list.append("PRINTEDNAME");
            list.append("PRICEMIN");
            list.append("PRICEMAX");
            list.append("VAT_PERCENTAGE");
            list.append("ID");
            QSqlQuery result = SH_DatabaseManager::getInstance()->execSelectQuery("SERVICESINFOS", list, QString("CODE=%1").arg(service->rawInput().toString()));
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
        connect(this, &SH_InOutStateMachine::receiveInput, [=](QString in) {
            QString newInput;
            if(in.right(in.length() - 1).toInt() != 0) {
                newInput = in.right(in.length() - 1);
            }
            emit receiveInput(newInput);
        });
    });
    connect(price, &QState::entered, [=]() {
        connect(this, &SH_InOutStateMachine::confirmInput, [=]() {
            price->setInput(m_priceMin);
        });
    });
    connect(vat, &QState::entered, [=]() {
        connect(this, &SH_InOutStateMachine::confirmInput, [=]() {
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
    connect(this, &SH_InOutStateMachine::validateInput, this, &SH_LoopingInOutStateMachine::stopLooping);
}
