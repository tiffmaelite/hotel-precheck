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
    SH_InOutStateMachine("CLIENTS_ARCHIVE",name, parent)
{
    SH_StatementState* introAddress = new SH_StatementState("Vous pouvez à tout moment interrompre la création de l'adresse du client en appuyant sur la touche \"CONFIRMER\"","intro address client creation");
    SH_AddressCreationStateMachine* address = new SH_AddressCreationStateMachine("address in client creation");
    SH_DatabaseContentQuestionState* nationality = new SH_DatabaseContentQuestionState("Code de nationalité du client", "nationality in client creation", "NATIONALITIES_ARCHIVE","CODE");
    SH_FileSelectionState* IDscan = new SH_FileSelectionState("Veuillez sélectionner l'image scannée des papiers d'identité du client","ID image in client creation");


    //Note that due to C++ literal strings rules, you must escape all backslashes inside the pattern string with another backslash; and due to QRegularExpression particularities, you must use espace function to escape typical regular expression characters that should not be interepreted
    // ^\+(9[976]\d|8[987530]\d|6[987]\d|5[90]\d|42\d|3[875]\d|2[98654321]\d|9[8543210]|8[6421]|6[6543210]|5[87654321]|4[987654310]|3[9643210]|2[70]|7|1)\W*\d\W*\d\W*\d\W*\d\W*\d\W*\d\W*\d\W*\d\W*(\d{1,2})$ from http://stackoverflow.com/questions/2113908/what-regular-expression-will-match-valid-international-phone-numbers
    // ^\+(?:[0-9] ?){6,14}[0-9]$ from http://blog.stevenlevithan.com/archives/validate-phone-number#r4-3

    SH_RegExpQuestionState* phone = new SH_RegExpQuestionState("Numéro de téléphone du client avec le préfixe international +","phone client creation",QRegularExpression(QString("^(\\+[1-9]\\d{4,14})?$")));

    SH_RegExpQuestionState* email = new SH_RegExpQuestionState("Adresse email du client","email client creation",QRegularExpression(QString("^([\\-!#$%&'\\*\\+/=\\?^\\w\\d{|}~](\\.?[\\-!#$%&'\\*\\+/=\\?^\\w{|}~])*@[A-Za-z0-9](\\-?\\w)*(\\.[A-Za-z0-9](\\-?\\w)*)+)?$"))); // from http://thedailywtf.com/Articles/Validating_Email_Addresses.aspx

    QFinalState* final = new QFinalState();

    //this->addState(IDscan, "IDSCAN");
    this->setContentValue(QVariant(QVariant::String), "IDSCAN");
    this->addIOState(introAddress);
    //this->addStateMachine(address);
    this->setContentValue(QVariant(QVariant::Int), "HOMEADDRESS_ID");
    this->addIOState(phone, "PHONE");
    this->setContentValue(QVariant(QVariant::String), "PHONE");
    this->addIOState(email, "EMAIL");
    this->setContentValue(QVariant(QVariant::String), "EMAIL");
    this->addIOState(nationality, "NATIONALITY_ID");
    this->setContentValue(QVariant(QVariant::Int), "NATIONALITY_ID");
    this->addState(final);
    /*connect(address, &SH_InOutStateMachine::entered, [=]() {
        connect(this, &SH_InOutStateMachine::confirmInput, address, &SH_InOutStateMachine::next);
    });*/
    connect(address, &SH_InOutStateMachine::exited, [=]() { this->setContentValue(address->getContentValue("ID"),"HOMEADDRESS_ID"); });
    //this->setStatesNextTransition(IDscan, introAddress);
    //this->setStatesNextTransition(introAddress, address);
    this->setStatesNextTransition(introAddress, phone);
    //this->setStatesNextTransition(address, phone);
    this->setStatesNextTransition(phone, email);
    this->setStatesNextTransition(email, nationality);
    this->setStatesNextTransition(nationality, final);
    //this->setInitialState(IDscan);
    this->setInitialState(introAddress);

    connect(IDscan,&SH_FileSelectionState::entered, [=]() {
        connect(this, &SH_InOutStateMachine::confirmInput, IDscan, &SH_FileSelectionState::next);
    });
}
/*}*/
