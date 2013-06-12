#include "confirmationstate.h"


/*!
 \brief

 \fn ConfirmationState::ConfirmationState
 \param output
 \param name
 \param parent
*/
ConfirmationState::ConfirmationState(QString output, QString name, QState *parent) :
    StatementState(output, name, parent)
{

}

/*!
 \brief

 \fn ConfirmationState::confirmInput
*/
void ConfirmationState::confirmInput()
{
    emit next();
}
