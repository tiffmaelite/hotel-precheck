#include "billingcreation.h"
#include "statementstate.h"
#include "numericquestionstate.h"
#include "datequestionstate.h"
#include "databasecontentquestionstate.h"
#include "confirmationstate.h"
#include "loopingstatemachine.h"
#include "adaptdatabasestate.h"
#include "clientcreation.h"

BillingCreationStateMachine::BillingCreationStateMachine(QString name, QObject *parent) :
    IOStateMachine("BILLINGS",name, parent)
{
    qDebug() << "facturation";

    StatementState* intro = new StatementState("Création d'une facturation", "intro billing creation");
    NumericQuestionState* nbAdults = new NumericQuestionState("Veuillez entrer le nombre d'adultes","adults billing creation", 0);
    NumericQuestionState* nbChildren = new NumericQuestionState("Veuillez entrer le nombre d'enfants", "children billing creation", 0);
    DateQuestionState* arrivingDate = new DateQuestionState("Veuillez entrer la date d'arrivée", "arriving date billing creation", true,true);
    DateQuestionState* departureDate = new DateQuestionState("Veuillez entrer la date de départ prévue", "departure date billing creation", false,true);
    DatabaseContentQuestionState* client = new DatabaseContentQuestionState("Veuillez entrer le nom du client à facturer","main client billing creation", "CLIENTS", "NAME");
    ClientCreationStateMachine* clientCreation = new ClientCreationStateMachine("main client creation in billing creation");
    NumericQuestionState* nbRooms = new NumericQuestionState("Veuillez entrer le nombre de chambres", "nb rooms billing creation", 1);
    //DatabaseContentQuestionState* type = new DatabaseContentQuestionState("Veuillez choisir le type de facturation","billing type billing creation", "BILLINGSTYPES", "CODE");
        DatabaseContentQuestionState* type = new DatabaseContentQuestionState("Veuillez choisir le type de facturation","billing type billing creation", "BILLINGSTYPES", "ID");
    LoopingIOStateMachine* roomsAffectation = new LoopingIOStateMachine("ROOMSOCCUPATION", "rooms affectation billing creation");
    LoopingIOStateMachine* billsCreation = new LoopingIOStateMachine("BILLS", "bills creation billing creation");
    LoopingIOStateMachine* clientList = new LoopingIOStateMachine("CLIENTS", "bills creation billing creation");
    ConfirmationState* confirmPart1 = new ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm part 1");
    adaptDatabase* saveState = new adaptDatabase("enregistrement de la machine "+toString());
    ConfirmationState* confirmAll = new ConfirmationState("Veuillez appuyer sur la touche \"CONFIRMER\" pour passer à l'étape suivante", "confirm all");
    QFinalState* final = new QFinalState();



    connect(nbAdults, &GenericState::exited, [=]() {
        clientList->setLimit(getContentValue("NBADULTS").toInt()-1);
    });

    connect(nbRooms, &GenericState::exited, [=]() {
        roomsAffectation->setLimit(getContentValue("NBROOMS").toInt());
    });

    connect(type, &GenericState::exited, [=]() {
        billsCreation->setLimit(getContentValue("NBROOMS").toInt() * (getContentValue("BILLINGTYPE_ID").toInt() % 3));
    });

    connect(saveState, &GenericState::exited, [=]() {
        roomsAffectation->setPersistentContentValue(getContentValue("ID"), "BILLING_ID");
        billsCreation->setPersistentContentValue(getContentValue("ID"), "BILLING_ID");
    });





    DatabaseContentQuestionState* rooms = new DatabaseContentQuestionState("Veuillez entrer un numéro de chambre","room billing creation", "ROOMS", "NUMBER");
    QFinalState* finalRooms = new QFinalState();
    roomsAffectation->addChildrenNextTransition(rooms, finalRooms);
    roomsAffectation->addIOState(rooms,"ROOM_NUMBER");
    roomsAffectation->addState(finalRooms);
    roomsAffectation->setInitialState(rooms);



    DatabaseContentQuestionState* supplClient = new DatabaseContentQuestionState("Veuillez entrer le nom du client (adulte) supplémentaire ou appuyer sur la touche \"CONFIRMER\" pour passer à la suite de la facturation","other client billing creation", "CLIENTS", "NAME");
    ClientCreationStateMachine* supplClientCreation = new ClientCreationStateMachine("other client creation in billing creation");
    connect(clientList, &IOStateMachine::confirmInput, [=]() {
        clientList->stopLooping();
        supplClient->next();
    });
    QFinalState* finalClients = new QFinalState();
    clientList->addChildrenNextTransition(supplClient, finalClients);
    connect(supplClient, &QuestionState::answerInvalid, [=]() {
        supplClientCreation->setContentValue(supplClient->givenAnswer(), "NAME");
        supplClient->addTransition(supplClient, SIGNAL(next()), supplClientCreation);
        emit supplClient->next();
    });
    clientList->addChildrenNextTransition(supplClientCreation, finalClients);
    clientList->addState(finalClients);
    clientList->addState(supplClient);
    clientList->setInitialState(supplClient);




    QFinalState* finalBills = new QFinalState();
    GenericState* bills = new GenericState("bill id attribution");
    connect(bills, &GenericState::entered, [=]() {
        this->setContentValue(QVariant(billsCreation->current()), "BILLINGBILL_ID");
        int billingType = getContentValue("BILLINGTYPE_ID").toInt();
        int billType;
        if(billingType <= 2) {
            billType = 1+billingType; //nb facture par chambre
        } else {
            billType = (billsCreation->current() % (1+(billingType % 3)));
        }

        this->setContentValue(QVariant(billType), "BILLTYPE_ID");
        emit bills->next();
    });
    billsCreation->addChildrenNextTransition(bills, finalBills);
    billsCreation->addState(finalBills);
    billsCreation->addState(bills);
    billsCreation->setInitialState(bills);




    this->addChildrenNextTransition(intro, nbAdults);
    this->addChildrenNextTransition(nbAdults, nbChildren);
    this->addChildrenNextTransition(nbChildren, arrivingDate);
    this->addChildrenNextTransition(arrivingDate, departureDate);
    this->addChildrenNextTransition(departureDate, client);
    this->addChildrenNextTransition(client, nbRooms);
    connect(client, &QuestionState::answerInvalid, [=]() {
        clientCreation->setContentValue(client->givenAnswer(),"NAME");
        client->addTransition(client, SIGNAL(next()), clientCreation);
        emit client->next();
    });
    this->addChildrenNextTransition(clientCreation, nbRooms);
    this->addChildrenNextTransition(nbRooms, type);
    this->addChildrenNextTransition(type, final);
    //this->addChildrenNextTransition(type, confirmPart1);
    confirmPart1->addTransition(confirmPart1, SIGNAL(next()), confirmPart1);
    connect(confirmPart1, &GenericState::exited, [=]() {
        connect(saveState, &GenericState::entered, [=]() {
            setContentValue(saveState->insertUpdate(m_tableName, m_ioContent), "ID");
        });
    });
    saveState->addTransition(saveState, SIGNAL(next()),confirmAll);
    //saveState->addTransition(saveState, SIGNAL(next()),roomsAffectation);
    //this->addChildrenNextTransition(roomsAffectation, billsCreation);
    //this->addChildrenNextTransition(billsCreation, clientList);
    //this->addChildrenNextTransition(clientList, confirmAll);
    this->addChildrenNextTransition(confirmAll, final);

    this->addIOState(intro,"");
    this->addIOState(nbAdults,"NBADULTS");
    this->addIOState(nbChildren,"NBCHILDREN");
    this->addIOState(arrivingDate,"ARRIVINGDATE");
    this->addIOState(departureDate,"EXPECTEDDEPARTUREDATE");
    this->addIOState(client,"CLIENT_ID");
    this->addIOState(nbRooms,"NBROOMS");
    this->addIOState(type,"BILLINGTYPE_ID");
    this->addIOState(confirmPart1,"");
    this->addIOState(confirmAll,"");
    //this->addIOStateMachine(billsCreation);
    //this->addIOStateMachine(roomsAffectation);
    //this->addIOStateMachine(clientList);
    this->addState(final);

    this->setInitialState(intro);
}
