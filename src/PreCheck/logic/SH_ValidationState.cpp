#include "SH_ValidationState.h"



/*!
 \brief

 \fn ValidationState::ValidationState
 \param output
 \param name
 \param parent
*/
SH_ValidationState::SH_ValidationState(QString output, QString name, QState *parent) :
    SH_ConfirmationState(output, name, parent)
{

}
