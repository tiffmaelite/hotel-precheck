#include <QRegularExpression>
#include "SH_ClientCreation.h"
#include "SH_DatabaseContentQuestionState.h"
#include "SH_StringQuestionState.h"
#include "SH_FileSelectionState.h"
#include "SH_RegExpQuestionState.h"
#include "SH_AddressCreation.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_ClientCreationStateMachine::ClientCreationStateMachine
*/
SH_ClientCreationStateMachine::SH_ClientCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("CLIENTS",name, parent)
{
    //SH_AddressCreationStateMachine* address = new SH_AddressCreationStateMachine("address in client creation");
    //SH_DatabaseContentQuestionState* nationality = new SH_DatabaseContentQuestionState("Veuillez entrer le code de nationalité du client", "nationality in client creation", "NATIONALITIES","CODE");
    //SH_FileSelectionState* IDscan = new SH_FileSelectionState("Veuillez sélectionner l'image scannée des papiers d'identité du client","ID image in client creation");
    SH_RegExpQuestionState* phone = new SH_RegExpQuestionState("Veuillez entrer le numéro de téléphone du client avec le préfixe international","phone client creation",QRegularExpression("[[\+|00][[1-9]]{3}\\d{8}]?"));
    SH_RegExpQuestionState* email = new SH_RegExpQuestionState("Veuillez entrer l'adresse email du client","email client creation",QRegularExpression("[[\\d\\w\._%\+\-]+@[\\d\\w\.-]+\.[\\w]+]?"));
    QFinalState* final = new QFinalState();
    this->addState(final);
    //this->addState(IDscan, "IDSCAN");
    //this->addState(nationality, "NATIONALITY_CODE");
    //this->addState(address);
    this->addState(phone, "PHONE");
    this->addState(email, "EMAIL");
    //connect(address, &SH_InOutStateMachine::exited, [=]() {setContentValue(address->getContentValue("ID"),"HOMEADDRESS_ID");});
    //this->addChildrenNextTransition(IDscan, address);
    //this->addChildrenNextTransition(address, phone);
    this->setStatesNextTransition(phone, email);
    this->setStatesNextTransition(email, final);
    //this->addChildrenNextTransition(email, nationality);
    //this->addChildrenNextTransition(nationality, final);
    //this->setInitialState(IDscan);
    this->setInitialState(phone);

    /*connect(IDscan,&QState::entered, [=]() {
    connect(this, &IOStateMachine::confirmInput, IDscan, &GenericState::next);
    });*/
}
/*}*/
