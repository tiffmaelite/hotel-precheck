#include "clientcreation.h"
#include "databasecontentquestionstate.h"
#include "stringquestionstate.h"
#include "fileselectionstate.h"
#include "regexquestionstate.h"
#include <QRegularExpression>
#include "addresscreation.h"

/*!
 \brief
 \fn ClientCreationStateMachine::ClientCreationStateMachine TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
ClientCreationStateMachine::ClientCreationStateMachine(QString name, QObject *parent) :
    IOStateMachine("CLIENTS",name, parent)
{
    AddressCreation* address = new AddressCreation("address in client creation");
    DatabaseContentQuestionState* nationality = new DatabaseContentQuestionState("Veuillez entrer le code de nationalité du client", "nationality in client creation", "NATIONALITIES","CODE");
    FileSelectionState* IDscan = new FileSelectionState("Veuillez sélectionner l'image scannée des papiers d'identité du client","ID image in client creation");
    RegExpQuestionState* phone = new RegExpQuestionState("Veuillez entrer le numéro de téléphone du client avec le préfixe international","phone client creation",QRegularExpression("[[\+|00][[1-9]]{3}\\d{8}]?"));
    RegExpQuestionState* email = new RegExpQuestionState("Veuillez entrer l'adresse email du client","email client creation",QRegularExpression("[[\\d\\w\._%\+\-]+@[\\d\\w\.-]+\.[\\w]+]?"));
    QFinalState* final = new QFinalState();

    this->addState(final);
    this->addIOState(IDscan, "IDSCAN");
    this->addIOState(nationality, "NATIONALITY_CODE");
    this->addIOState(phone, "PHONE");
    this->addIOState(email, "EMAIL");
    connect(address, &IOStateMachine::exited, [=]() {setContentValue(address->getContentValue("ID"),"HOMEADDRESS_ID");});
    this->addChildrenNextTransition(IDscan, address);
    this->addChildrenNextTransition(address, phone);
    this->addChildrenNextTransition(phone, email);
    this->addChildrenNextTransition(email, nationality);
    this->setInitialState(IDscan);

    /*connect(IDscan,&QState::entered, [=]() {
        connect(this, &IOStateMachine::confirmInput, IDscan, &GenericState::next);
    });*/
}
