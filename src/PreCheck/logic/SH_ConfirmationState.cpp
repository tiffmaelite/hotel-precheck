#include "SH_ConfirmationState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_ConfirmationState::ConfirmationState
*/
SH_ConfirmationState::SH_ConfirmationState(QString output, QString name, QState *parent) :
    SH_StatementState(output, name, parent)
{
}
/*!
 * \details \~french
 * \fn SH_ConfirmationState::confirmInput
*/
void SH_ConfirmationState::confirmInput()
{
    if(this->isRunning()) {
        SH_MessageManager::debugMessage("confirmatiooooon !");
        emit goNext();
    }
}
/*}*/
