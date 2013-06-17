#include "addresscreation.h"

/*!
 \brief
 \fn AddressCreation::AddressCreation TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
AddressCreation::AddressCreation(QString name, QObject *parent) :
    IOStateMachine("ADDRESSES",name, parent)
{
//TODO: rue, numéro, code postal, ville, pays, destinataire
emit next();
}


