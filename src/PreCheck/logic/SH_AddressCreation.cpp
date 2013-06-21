#include "SH_AddressCreation.h"

/*!
 \details \~french
 \fn SH_AddressCreation::AddressCreation TODO comment this

*/
SH_AddressCreationStateMachine::SH_AddressCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("ADDRESSES",name, parent)
{
/*TODO: rue, numéro, code postal, ville, pays, destinataire*/
emit next();
}


