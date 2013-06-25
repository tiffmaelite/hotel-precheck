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
 * \fn SH_IOState::input
*/
QVariant SH_InOutState::input() const
{
    return m_input;
}
/*!
 * \details \~french
 * \fn SH_IOState::rawInput
*/
QVariant SH_InOutState::rawInput() const
{
    return input();
}
/*!
 * \details \~french
 * \fn SH_IOState::setInput
*/
void SH_InOutState::setInput(const QVariant &input)
{
    if(isRunning() && input != this->input()) {
        //SH_MessageManager::infoMessage("new input " + input.toString());
        m_input = input;
        emitResendInput();
    }
}
/*!
 * \details \~french
 * \fn SH_IOState::output
*/
QString SH_InOutState::output() const
{
    return m_output;
}
/*!
 * \details \~french
 * \fn SH_IOState::setOutput
*/
void SH_InOutState::setOutput(const QString &output)
{
    if(isRunning() && output != this->output()) {
        m_output = output;
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
        m_isVisible = isVisible;
    }
}
/*!
 * \details \~french
 * \fn SH_IOState::visibility
*/
bool SH_InOutState::visibility() {
    return m_isVisible;
}

void SH_InOutState::display(bool canDisplay)
{
        m_display=canDisplay;
        emitSendOutput();
}

void SH_InOutState::emitSendOutput() {
    if(isRunning() && m_display && !m_output.isEmpty() && m_isVisible) {
        emit sendOutput(QVariant(m_output));
    }
}

void SH_InOutState::emitResendInput() {
    if(isRunning() && m_isVisible) {
        emit resendInput(m_input);
    }
}

/*}*/
