#include "SH_BillingCreation.h"
#include "SH_StatementState.h"
#include "SH_NumericQuestionState.h"
#include "SH_DateQuestionState.h"
#include "SH_DatabaseContentQuestionState.h"
#include "SH_ConfirmationState.h"
#include "SH_LoopingIOStateMachine.h"
#include "SH_AdaptDatabaseState.h"
#include "SH_ClientCreation.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * * \details \~french SH_BillingCreationStateMachine::SH_BillingCreationStateMachine
 */
SH_BillingCreationStateMachine::SH_BillingCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("BILLINGS",name, parent)
{
    SH_MessageManager::debugMessage("facturation");
    SH_StatementState* intro = new SH_StatementState("<h2>Création d'une facturation</h2>", "intro billing creation");
    SH_NumericQuestionState* nbAdults = new SH_NumericQuestionState("Veuillez entrer le nombre d'adultes","adults billing creation", 0);
    SH_NumericQuestionState* nbChildren = new SH_NumericQuestionState("Veuillez entrer le nombre d'enfants", "children billing creation", 0);
    SH_DateQuestionState* arrivingDate = new SH_DateQuestionState("Veuillez entrer la date d'arrivée", "arriving date billing creation", true,true);
    SH_DateQuestionState* departureDate = new SH_DateQuestionState("Veuillez entrer la date de départ prévue (ultérieure à la date d'arrivée)", "departure date billing creation", false,true);
    SH_DatabaseContentQuestionState* client = new SH_DatabaseContentQuestionState("Veuillez entrer le nom du client à facturer","main client billing creation", "CLIENTS", "NAME");
    SH_ClientCreationStateMachine* clientCreation = new SH_ClientCreationStateMachine("main client creation in billing creation");
    SH_NumericQuestionState* nbRooms = new SH_NumericQuestionState("Veuillez entrer le nombre de chambres", "nb rooms billing creation", 1);
    SH_DatabaseContentQuestionState* type = new SH_DatabaseContentQuestionState("Veuillez choisir le type de facturation","billing type billing creation", "BILLINGSTYPES", "ID");
    SH_LoopingInOutStateMachine* roomsAffectation = new SH_LoopingInOutStateMachine("ROOMSOCCUPATION", "rooms affectation billing creation");
    SH_LoopingInOutStateMachine* billsCreation = new SH_LoopingInOutStateMachine("BILLS", "bills creation billing creation");
    SH_LoopingInOutStateMachine* clientList = new SH_LoopingInOutStateMachine("CLIENTS", "bills creation billing creation");
    SH_ConfirmationState* confirmPart1 = new SH_ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm part 1");
    SH_AdaptDatabaseState* saveState = new SH_AdaptDatabaseState("enregistrement de la machine "+toString());
    SH_ConfirmationState* confirmAll = new SH_ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm all");
    QFinalState* final = new QFinalState();

    SH_MessageManager::debugMessage("facturation : states created");

    connect(arrivingDate, &SH_GenericState::exited, [=]() {
        departureDate->setMinimumDate(getContentValue("ARRIVINGDATE").toDate().addDays(1));
    });
    connect(nbAdults, &SH_GenericState::exited, [=]() {
        clientList->setLimit(getContentValue("NBADULTS").toInt()-1);
    });
    connect(nbRooms, &SH_GenericState::exited, [=]() {
        roomsAffectation->setLimit(getContentValue("NBROOMS").toInt());
    });
    connect(type, &SH_GenericState::exited, [=]() {
        billsCreation->setLimit(getContentValue("NBROOMS").toInt() * (getContentValue("BILLINGTYPE_ID").toInt() % 3));
    });
    connect(saveState, &SH_GenericState::exited, [=]() {
        roomsAffectation->setPersistentContentValue(getContentValue("ID"), "BILLING_ID");
        billsCreation->setPersistentContentValue(getContentValue("ID"), "BILLING_ID");
    });
    connect(confirmPart1, &SH_GenericState::exited, [=]() {
        setContentValue(saveState->insertUpdate(this->m_tableName, this->m_ioContent), "ID");
    });
    connect(billsCreation, &SH_GenericState::entered, [=]() {
        displayProgressBar(0);
        connect(billsCreation, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            displayProgressBar(billsCreation->current()/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });
    connect(roomsAffectation, &SH_GenericState::entered, [=]() {
        displayProgressBar(billsCreation->limit());
        connect(roomsAffectation, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            displayProgressBar((billsCreation->limit()+roomsAffectation->current())/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });
    connect(clientList, &SH_GenericState::entered, [=]() {
        displayProgressBar(billsCreation->limit()+roomsAffectation->limit());
        connect(clientList, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            displayProgressBar((billsCreation->limit()+roomsAffectation->limit()+clientList->current())/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });

    SH_MessageManager::debugMessage("facturation : main connexions finished");

    SH_DatabaseContentQuestionState* rooms = new SH_DatabaseContentQuestionState("Veuillez entrer un numéro de chambre","room billing creation", "ROOMS", "NUMBER");
    QFinalState* finalRooms = new QFinalState();
    roomsAffectation->setStatesNextTransition(rooms, finalRooms);
    roomsAffectation->addState(rooms,"ROOM_NUMBER");
    roomsAffectation->addState(finalRooms);
    roomsAffectation->setInitialState(rooms);

    SH_MessageManager::debugMessage("facturation : rooms affectation states created");

    SH_DatabaseContentQuestionState* supplClient = new SH_DatabaseContentQuestionState("Veuillez entrer le nom du client (adulte) supplémentaire ou appuyer sur la touche \"CONFIRMER\" pour passer à la suite de la facturation","other client billing creation", "CLIENTS", "NAME");
    SH_ClientCreationStateMachine* supplClientCreation = new SH_ClientCreationStateMachine("other client creation in billing creation");
    connect(clientList, &SH_InOutStateMachine::confirmInput, [=]() {
        clientList->stopLooping();
        emit supplClient->goNext();
    });
    QFinalState* finalClients = new QFinalState();
    clientList->setStatesNextTransition(supplClient, finalClients);
    connect(supplClient, &SH_QuestionState::answerInvalid, [=]() {
        supplClientCreation->setContentValue(supplClient->givenAnswer(), "NAME");
        clientList->setStatesNextTransition(supplClient, supplClientCreation);
        emit supplClient->goNext();
    });
    clientList->setStatesNextTransition(supplClientCreation, finalClients);
    clientList->addState(finalClients);
    clientList->addState(supplClient);
    clientList->setInitialState(supplClient);

    SH_MessageManager::debugMessage("facturation : clients list states created");

    QFinalState* finalBills = new QFinalState();
    SH_GenericState* bills = new SH_GenericState("bill id attribution");
    connect(bills, &SH_GenericState::entered, [=]() {
        this->setContentValue(QVariant(billsCreation->current()), "BILLINGBILL_ID");
        int billingType = getContentValue("BILLINGTYPE_ID").toInt();
        int billType;
        if(billingType <= 2) {
            billType = 1+billingType;
            /*nb facture par chambre*/
        } else {
            billType = (billsCreation->current() % (1+(billingType % 3)));
        }
        this->setContentValue(QVariant(billType), "BILLTYPE_ID");
        emit bills->goNext();
    });
    billsCreation->setStatesNextTransition(bills, finalBills);
    billsCreation->addState(finalBills);
    billsCreation->addState(bills);
    billsCreation->setInitialState(bills);

    SH_MessageManager::debugMessage("facturation : bills creation states created");

    this->addState(intro,"");
    this->addState(nbAdults,"NBADULTS");
    this->addState(nbChildren,"NBCHILDREN");
    this->addState(arrivingDate,"ARRIVINGDATE");
    this->addState(departureDate,"EXPECTEDDEPARTUREDATE");
    this->addState(client,"CLIENT_ID");
    this->addState(nbRooms,"NBROOMS");
    this->addState(type,"BILLINGTYPE_ID");
    this->addState(confirmPart1,"");
    this->addState(confirmAll,"");
    this->addState(billsCreation);
    this->addState(roomsAffectation);
    this->addState(clientList);
    this->addState(saveState);
    this->addState(final);

    this->setStatesNextTransition(intro, nbAdults);
    this->setStatesNextTransition(nbAdults, nbChildren);
    this->setStatesNextTransition(nbChildren, arrivingDate);
    this->setStatesNextTransition(arrivingDate, departureDate);
    this->setStatesNextTransition(departureDate, client);
    this->setStatesNextTransition(client, nbRooms);
    connect(client, &SH_QuestionState::answerInvalid, [=]() {
        clientCreation->setContentValue(client->givenAnswer(),"NAME");
        this->setStatesNextTransition(client, clientCreation);
        emit client->goNext();
    });
    this->setStatesNextTransition(clientCreation, nbRooms);
    this->setStatesNextTransition(nbRooms, type);
    this->setStatesNextTransition(confirmPart1, saveState);
    this->setStatesNextTransition(type, confirmPart1);
    this->setStatesNextTransition(saveState, roomsAffectation);
    this->setStatesNextTransition(roomsAffectation, billsCreation);
    this->setStatesNextTransition(billsCreation, clientList);
    this->setStatesNextTransition(clientList, confirmAll);
    this->setStatesNextTransition(confirmAll, final);

    this->setInitialState(intro);
    SH_MessageManager::debugMessage("coucouuuuu !");
}
/*}*/
