#include "SH_AddressCreation.h"

/*!
 \brief
 \fn AddressCreation::AddressCreation TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
SH_AddressCreationStateMachine::SH_AddressCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("ADDRESSES",name, parent)
{
//TODO: rue, numéro, code postal, ville, pays, destinataire
emit next();
}


