#include "SH_ConfirmationState.h"


/*!
 \brief

 \fn ConfirmationState::ConfirmationState
 \param output
 \param name
 \param parent
*/
SH_ConfirmationState::SH_ConfirmationState(QString output, QString name, QState *parent) :
    SH_StatementState(output, name, parent)
{
    qDebug() << "confirmatiooooon !";
}

/*!
 \brief

 \fn ConfirmationState::confirmInput
*/
void SH_ConfirmationState::confirmInput()
{
    emit next();
}
