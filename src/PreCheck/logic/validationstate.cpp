#include "validationstate.h"



/*!
 \brief

 \fn ValidationState::ValidationState
 \param output
 \param name
 \param parent
*/
ValidationState::ValidationState(QString output, QString name, QState *parent) :
    ConfirmationState(output, name, parent)
{

}
