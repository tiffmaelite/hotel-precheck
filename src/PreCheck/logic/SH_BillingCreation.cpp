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
    SH_InOutStateMachine("BILLINGS_ARCHIVE",name, parent)
{
    SH_StatementState* intro = new SH_StatementState("<strong>Création d'une facturation</strong>", "intro billing creation");
    SH_NumericQuestionState* nbAdults = new SH_NumericQuestionState("Nombre d'adultes","adults billing creation", 1);
    SH_NumericQuestionState* nbChildren = new SH_NumericQuestionState("Nombre d'enfants", "children billing creation", 0);
    SH_DateQuestionState* arrivingDate = new SH_DateQuestionState("Date d'arrivée", "arriving date billing creation", true,true);
    SH_DateQuestionState* departureDate = new SH_DateQuestionState("Date de départ prévue (ultérieure à la date d'arrivée)", "departure date billing creation", false,true);
    SH_DatabaseContentQuestionState* client = new SH_DatabaseContentQuestionState("Nom du client à facturer","main client billing creation", "CLIENTS", "NAME");
    SH_ClientCreationStateMachine* clientCreation = new SH_ClientCreationStateMachine("main client creation in billing creation");
    SH_NumericQuestionState* nbRooms = new SH_NumericQuestionState("Nombre de chambres", "nb rooms billing creation", 1);
    SH_DatabaseContentQuestionState* type = new SH_DatabaseContentQuestionState("Type de facturation","billing type billing creation", "BILLINGSTYPES", "ID");
    SH_LoopingInOutStateMachine* roomsAffectation = new SH_LoopingInOutStateMachine("ROOMSOCCUPATION", "rooms affectation billing creation");
    SH_LoopingInOutStateMachine* billsCreation = new SH_LoopingInOutStateMachine("BILLS", "bills creation billing creation");
    SH_LoopingInOutStateMachine* clientList = new SH_LoopingInOutStateMachine("CLIENTS_ARCHIVE", "bills creation billing creation");
    SH_ConfirmationState* confirmPart1 = new SH_ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm part 1");
    SH_AdaptDatabaseState* saveState = new SH_AdaptDatabaseState("enregistrement de la machine "+toString());
    SH_ConfirmationState* confirmAll = new SH_ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm all");
    QFinalState* final = new QFinalState();

    connect(arrivingDate, &SH_GenericState::exited, [=]() {
        departureDate->setMinimumDate(this->getContentValue("ARRIVINGDATE").toDate().addDays(1));
    });
    connect(nbAdults, &SH_GenericState::exited, [=]() {
        clientList->setLimit(this->getContentValue("NBADULTS").toInt()-1);
    });
    connect(nbRooms, &SH_GenericState::exited, [=]() {
        roomsAffectation->setLimit(this->getContentValue("NBROOMS").toInt());
    });
    connect(type, &SH_GenericState::exited, [=]() {
        billsCreation->setLimit(this->getContentValue("NBROOMS").toInt() * (this->getContentValue("BILLINGTYPE_ID").toInt() % 3));
    });
    connect(saveState, &SH_GenericState::exited, [=]() {
        roomsAffectation->setPersistentContentValue(this->getContentValue("ID"), "BILLING_ID");
        billsCreation->setPersistentContentValue(this->getContentValue("ID"), "BILLING_ID");
    });
    connect(saveState, &SH_GenericState::entered, [=]() {
        this->setContentValue(saveState->insertUpdate(this->tableName(), this->ioContent()), "ID");
    });
    connect(billsCreation, &SH_GenericState::entered, [=]() {
        this->displayProgressBar(0);
        connect(billsCreation, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            this->displayProgressBar(billsCreation->current()/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });
    connect(roomsAffectation, &SH_GenericState::entered, [=]() {
        this->displayProgressBar(billsCreation->limit());
        connect(roomsAffectation, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            this->displayProgressBar((billsCreation->limit()+roomsAffectation->current())/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });
    connect(clientList, &SH_GenericState::entered, [=]() {
        this->displayProgressBar(billsCreation->limit()+roomsAffectation->limit());
        connect(clientList, &SH_LoopingInOutStateMachine::currentChanged, [=]() {
            this->displayProgressBar((billsCreation->limit()+roomsAffectation->limit()+clientList->current())/(billsCreation->limit()+roomsAffectation->limit()+clientList->limit()));
        });
    });

    SH_DatabaseContentQuestionState* rooms = new SH_DatabaseContentQuestionState("Numéro de chambre occupée","room billing creation", "ROOMS", "NUMBER");
    QFinalState* finalRooms = new QFinalState();
    roomsAffectation->setStatesNextTransition(rooms, finalRooms);
    roomsAffectation->addState(rooms,"ROOM_NUMBER");
    roomsAffectation->addState(finalRooms);
    roomsAffectation->setInitialState(rooms);

    SH_DatabaseContentQuestionState* supplClient = new SH_DatabaseContentQuestionState("Nom du client (adulte) supplémentaire (ou \"CONFIRMER\" pour passer à la suite de la facturation)","other client billing creation", "CLIENTS", "NAME");
    SH_ClientCreationStateMachine* supplClientCreation = new SH_ClientCreationStateMachine("other client creation in billing creation");
    connect(clientList, &SH_InOutStateMachine::confirmInput, [=]() {
        clientList->stopLooping();
        emit supplClient->goNext();
    });
    QFinalState* finalClients = new QFinalState();
    clientList->setStatesNextTransition(supplClient, finalClients);
    connect(supplClient, &SH_QuestionState::answerInvalid, [=]() {
        supplClientCreation->setContentValue(supplClient->displayableInput(), "NAME");
        clientList->setStatesNextTransition(supplClient, supplClientCreation);
        emit supplClient->goNext();
    });
    clientList->setStatesNextTransition(supplClientCreation, finalClients);
    clientList->addState(finalClients);
    clientList->addState(supplClient);
    clientList->setInitialState(supplClient);

    QFinalState* finalBills = new QFinalState();
    SH_GenericState* bills = new SH_GenericState("bill id attribution");
    connect(bills, &SH_GenericState::entered, [=]() {
        this->setContentValue(QVariant(billsCreation->current()), "BILLINGBILL_ID");
        int billingType = this->getContentValue("BILLINGTYPE_ID").toInt();
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


    this->addIOState(intro,"");
    this->addIOState(nbAdults,"NBADULTS");
    this->addIOState(nbChildren,"NBCHILDREN");
    this->addIOState(arrivingDate,"ARRIVINGDATE");
    this->addIOState(departureDate,"EXPECTEDDEPARTUREDATE");
    this->addIOState(client,"CLIENT_ID");
    this->addStateMachine(clientCreation);
    this->addIOState(nbRooms,"NBROOMS");
    this->addIOState(type,"BILLINGTYPE_ID");
    this->addIOState(confirmPart1,"");
    this->addState(saveState);
    this->addStateMachine(roomsAffectation);
    this->addStateMachine(billsCreation);
    this->addStateMachine(clientList);
    this->addIOState(confirmAll,"");
    this->addState(final);

    this->setStatesNextTransition(intro, nbAdults);
    this->setStatesNextTransition(nbAdults, nbChildren);
    this->setStatesNextTransition(nbChildren, arrivingDate);
    this->setStatesNextTransition(arrivingDate, departureDate);
    this->setStatesNextTransition(departureDate, client);
    this->setStatesNextTransition(client, nbRooms);
    connect(client, &SH_QuestionState::answerInvalid, [=]() {
        clientCreation->setContentValue(client->displayableInput(),"NAME");
        this->setStatesNextTransition(client, clientCreation);
        emit client->goNext();
    });
    this->setStatesNextTransition(clientCreation, nbRooms);
    this->setStatesNextTransition(nbRooms, type);
    this->setStatesNextTransition(type, confirmPart1);
    this->setStatesNextTransition(confirmPart1, saveState);
    this->setStatesNextTransition(saveState, roomsAffectation);
    this->setStatesNextTransition(roomsAffectation, billsCreation);
    this->setStatesNextTransition(billsCreation, clientList);
    this->setStatesNextTransition(clientList, confirmAll);
    this->setStatesNextTransition(confirmAll, final);

    this->setInitialState(intro);
}
/*}*/
