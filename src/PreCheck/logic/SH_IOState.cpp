#include "SH_IOState.h"

/*!
 \details \~french

 \fn SH_IOState::IOState

*/
SH_InOutState::SH_InOutState(QString output, QString name, QState *parent) :
    SH_GenericState(name, parent), m_output(output), m_isVisible(true)
{
}

/*!
 \details \~french

 \fn SH_IOState::input

*/
QVariant SH_InOutState::input() const
{
    return m_input;
}

/*!
 \details \~french
 \fn SH_IOState::rawInput

*/
QVariant SH_InOutState::rawInput() const
{
    return input();
}

/*!
 \details \~french

 \fn SH_IOState::setInput

*/
void SH_InOutState::setInput(const QVariant &input)
{
    if(isRunning()) {
        qDebug() << "new input " << input.toString();
        m_input = input;
        if(m_isVisible) {
            emit resendInput(m_input);
        }
    }
}

/*!
 \details \~french

 \fn SH_IOState::output

*/
QString SH_InOutState::output() const
{
    return m_output;
}


/*!
 \details \~french

 \fn SH_IOState::setOutput

*/
void SH_InOutState::setOutput(const QString &output)
{
    if(isRunning()) {
        m_output = output;
        if(m_isVisible) {
            emit sendOutput(QVariant(m_output));
        }
    }
}

/*!
 \details \~french
 \fn SH_IOState::setVisibility

*/
void SH_InOutState::setVisibility(bool isVisible)
{
    if(isRunning()) {
        m_isVisible = isVisible;
    }
}

/*!
 \details \~french
 \fn SH_IOState::visibility

*/
bool SH_InOutState::visibility() {
    return m_isVisible;
}

void SH_InOutState::display(bool canDisplay)
{
    if(isRunning()) {
        m_display=canDisplay;
        if(m_display && !m_output.isEmpty() && m_isVisible) {
            qDebug() << "resalut !" << QVariant(m_output);
            emit sendOutput(QVariant(m_output));
        }
    }
}

/*!
 \details \~french

 \fn SH_IOState::onExit

*/
void SH_InOutState::onExit(QEvent *event)
{
    if(m_isVisible) {
        emit resendInput(m_input);
    }
    SH_GenericState::onExit(event);
}
