#include "SH_AddressCreation.h"

/*!
 \details \~french Construit une instance de la classe SH_AddressCreationStateMachine
 \fn SH_AddressCreationStateMachine::SH_AddressCreationStateMachine

*/
SH_AddressCreationStateMachine::SH_AddressCreationStateMachine(QString name, QObject *parent) :
    SH_InOutStateMachine("ADDRESSES",name, parent)
{
/*TODO: rue, numéro, code postal, ville, pays, destinataire*/
emit goNext();
}


