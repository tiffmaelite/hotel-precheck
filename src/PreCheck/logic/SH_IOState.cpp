#include "SH_IOState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_IOState::IOState
*/
SH_InOutState::SH_InOutState(QString output, QString name, QState *parent) :
    SH_GenericState(name, parent), m_output(output), m_isVisible(true), m_display(true)
{
    connect(this, &QState::entered, this, &SH_InOutState::emitSendOutput);
    connect(this, &SH_GenericState::goNext, this, &SH_InOutState::emitSendOutput);
    connect(this, &SH_InOutState::outputChanged, this, &SH_InOutState::emitSendOutput);
    connect(this, &SH_InOutState::displayChanged, this, &SH_InOutState::emitSendOutput);
    connect(this, &SH_InOutState::inputChanged, this, &SH_InOutState::emitResendInput);
    connect(this, &SH_InOutState::displayableInputChanged, this, &SH_InOutState::emitResendInput);
}

/*!
 * \details \~french
 * \fn SH_IOState::setInput
*/
void SH_InOutState::setInput(const QVariant &input)
{
    if(this->isRunning() && input != this->m_input) {
        this->m_input = input;
        emit this->inputChanged(input);
    }
}

/*!
 * \details \~french
 * \fn SH_IOState::setOutput
*/
void SH_InOutState::setOutput(const QString &output)
{
    if(this->isRunning() && output != this->m_output) {
        this->m_output = output;
        emit this->outputChanged(output);
    }
}
/*!
 * \details \~french
 * \fn SH_IOState::setVisibility
*/
void SH_InOutState::setVisibility(bool isVisible)
{
    if(this->isRunning() && isVisible!=this->m_isVisible) {
        this->m_isVisible = isVisible;
        emit visibilityChanged();
    }
}


void SH_InOutState::emitSendOutput() {
    if(this->isRunning() && this->m_display && !this->m_output.isEmpty() && this->m_isVisible) {
        emit sendOutput(QVariant(this->m_output));
    }
}

void SH_InOutState::emitResendInput() {
    if(this->isRunning() && this->m_isVisible) {
        emit resendInput(this->displayableInput());
    }
}

/*}*/
