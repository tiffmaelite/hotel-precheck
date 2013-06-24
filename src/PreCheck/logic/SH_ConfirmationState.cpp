#include "SH_ConfirmationState.h"


/*!
 \details \~french

 \fn SH_ConfirmationState::ConfirmationState

*/
SH_ConfirmationState::SH_ConfirmationState(QString output, QString name, QState *parent) :
    SH_StatementState(output, name, parent)
{

}

/*!
 \details \~french

 \fn SH_ConfirmationState::confirmInput
*/
void SH_ConfirmationState::confirmInput()
{
    qDebug() << "confirmatiooooon !";
    emit goNext();
}
