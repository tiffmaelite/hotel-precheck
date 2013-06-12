#include "confirmationstate.h"


ConfirmationState::ConfirmationState(QString output, QString name, QState *parent) :
    StatementState(output, name, parent)
{

}

void ConfirmationState::confirmInput()
{
    emit next();
}
