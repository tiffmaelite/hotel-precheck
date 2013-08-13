#include <QRegularExpression>
#include "SH_ClientCreation.h"
#include "SH_DatabaseContentQuestionState.h"
#include "SH_StringQuestionState.h"
#include "SH_FileSelectionState.h"
#include "SH_RegExpQuestionState.h"
#include "SH_AddressCreation.h"
#include "SH_StatementState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_ClientCreationStateMachine::ClientCreationStateMachine
*/
SH_ClientCreationStateMachine::SH_ClientCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("CLIENTS",name, parent)
{
    SH_StatementState* introAddress = new SH_StatementState("Vous pouvez à tout moment interrompre la création de l'adresse du client en appuyant sur la touche \"CONFIRMER\"","intro address client creation");
    SH_AddressCreationStateMachine* address = new SH_AddressCreationStateMachine("address in client creation");
    SH_DatabaseContentQuestionState* nationality = new SH_DatabaseContentQuestionState("Veuillez entrer le code de nationalité du client", "nationality in client creation", "NATIONALITIES","CODE");
    //SH_FileSelectionState* IDscan = new SH_FileSelectionState("Veuillez sélectionner l'image scannée des papiers d'identité du client","ID image in client creation");


    //Note that due to C++ literal strings rules, you must escape all backslashes inside the pattern string with another backslash
    SH_RegExpQuestionState* phone = new SH_RegExpQuestionState("Veuillez entrer le numéro de téléphone du client avec le préfixe international","phone client creation",QRegularExpression(QString("[[%1|00][[1-9]]{3}\\d{8}]?").arg(QRegularExpression::escape("+"))));
    SH_RegExpQuestionState* email = new SH_RegExpQuestionState("Veuillez entrer l'adresse email du client","email client creation",QRegularExpression(QString("[[_%\\d\\w%1%2%3]+@[\\d\\w%1-]+%1[\\w]+]?").arg(QRegularExpression::escape(".")).arg(QRegularExpression::escape("+")).arg(QRegularExpression::escape("-"))));


    QFinalState* final = new QFinalState();
    this->addState(final);
    //this->addState(IDscan, "IDSCAN");
    this->addState(nationality, "NATIONALITY_ID");
    this->addState(address);
    this->addState(phone, "PHONE");
    this->addState(email, "EMAIL");
    connect(address, &SH_InOutStateMachine::entered, [=]() {
        connect(this, &SH_InOutStateMachine::confirmInput, address, &SH_InOutStateMachine::next);
    });
    connect(address, &SH_InOutStateMachine::exited, [=]() {setContentValue(address->getContentValue("ID"),"HOMEADDRESS_ID");});
    //this->setStatesNextTransition(IDscan, introAddress);
    this->setStatesNextTransition(introAddress, address);
    this->setStatesNextTransition(address, phone);
    this->setStatesNextTransition(phone, email);
    this->setStatesNextTransition(email, nationality);
    this->setStatesNextTransition(nationality, final);
    //this->setInitialState(IDscan);
    this->setInitialState(introAddress);

    /*connect(IDscan,&QState::entered, [=]() {
    connect(this, &IOStateMachine::confirmInput, IDscan, &GenericState::next);
    });*/
}
/*}*/
