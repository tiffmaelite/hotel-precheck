#include "SH_AddressCreation.h"
#include "SH_StringQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french Construit une instance de la classe SH_AddressCreationStateMachine
 * \fn SH_AddressCreationStateMachine::SH_AddressCreationStateMachine
*/
SH_AddressCreationStateMachine::SH_AddressCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("ADDRESSES",name, parent)
{
    SH_StringQuestionState* destinataire = new SH_StringQuestionState("Nom (destinataire pour courrier)", "address dest");
    SH_StringQuestionState* street = new SH_StringQuestionState("Nom de rue", "address street name");
    SH_StringQuestionState* number = new SH_StringQuestionState("Numéro dans la rue", "address street num");
    SH_StringQuestionState* city = new SH_StringQuestionState("Ville", "address city");
    SH_StringQuestionState* zipcode = new SH_StringQuestionState("Code postal", "address zip");
    SH_StringQuestionState* state = new SH_StringQuestionState("État/Province", "address state");
    SH_StringQuestionState* country = new SH_StringQuestionState("Pays", "address country");
    QFinalState* final = new QFinalState();
    this->addIOState(destinataire,"NAME");
    this->addIOState(street,"STREET");
    this->addIOState(number,"NUMBER");
    this->addIOState(city,"CITY");
    this->addIOState(zipcode,"ZIPCODE");
    this->addIOState(state,"STATE");
    this->addIOState(country,"COUNTRY");
    this->addState(final);
    this->setStatesNextTransition(destinataire, street);
    this->setStatesNextTransition(street, number);
    this->setStatesNextTransition(number, city);
    this->setStatesNextTransition(city, zipcode);
    //this->setStatesNextTransition(zipcode, state);
    this->setStatesNextTransition(zipcode, country);
    //this->setStatesNextTransition(state, country);
    this->setStatesNextTransition(country, final);
    this->setInitialState(destinataire);

    connect(this, &SH_InOutStateMachine::entered, [=]() {
        SH_MessageManager::infoMessage("coucou addresses !");
    });
}
/*}*/
