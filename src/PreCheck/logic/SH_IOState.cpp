#include "SH_IOState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_IOState::IOState
*/
SH_InOutState::SH_InOutState(QString output, QString name, QState *parent) :
    SH_GenericState(name, parent), m_output(output), m_isVisible(true),m_display(true)
{
    connect(this, &QState::entered, this, &SH_InOutState::emitSendOutput);
    connect(this, &SH_GenericState::goNext, this, &SH_InOutState::emitResendInput);
}

/*!
 * \details \~french
 * \fn SH_IOState::setInput
*/
void SH_InOutState::setInput(const QVariant &input)
{
    if(isRunning() && input != this->input()) {
        //SH_MessageManager::infoMessage("new input " + input.toString());
        this->m_input = input;
        emitResendInput();
    }
}

/*!
 * \details \~french
 * \fn SH_IOState::setOutput
*/
void SH_InOutState::setOutput(const QString &output)
{
    if(isRunning() && output != this->output()) {
        this->m_output = output;
        emitSendOutput();
    }
}
/*!
 * \details \~french
 * \fn SH_IOState::setVisibility
*/
void SH_InOutState::setVisibility(bool isVisible)
{
    if(isRunning() && isVisible!=this->visibility()) {
        this->m_isVisible = isVisible;
        emit visibilityChanged();
    }
}


void SH_InOutState::emitSendOutput() {
    if(isRunning() && this->m_display && !m_output.isEmpty() && this->m_isVisible) {
        emit sendOutput(QVariant(this->m_output));
    }
}

void SH_InOutState::emitResendInput() {
    if(isRunning() && this->m_isVisible) {
        emit resendInput(this->m_input);
    }
}

/*}*/
