#include "SH_IOState.h"

/*!
 \details

 \fn SH_IOState::IOState

*/
SH_InOutState::SH_InOutState(QString output, QString name, QState *parent) :
    SH_GenericState(name, parent), m_output(output), m_isVisible(true)
{
}

/*!
 \details

 \fn SH_IOState::input

*/
QVariant SH_InOutState::input() const
{
    return m_input;
}

/*!
 \details
 \fn SH_IOState::rawInput TODO comment this

*/
QVariant SH_InOutState::rawInput() const
{
    return input();
}

/*!
 \details

 \fn SH_IOState::setInput

*/
void SH_InOutState::setInput(const QVariant &input)
{
    qDebug() << "new input " << input.toString();
    m_input = input;
    if(m_isVisible) {
        emit resendInput(m_input);
    }
}

/*!
 \details

 \fn SH_IOState::output

*/
QString SH_InOutState::output() const
{
    return m_output;
}


/*!
 \details

 \fn SH_IOState::setOutput

*/
void SH_InOutState::setOutput(const QString &output)
{
    m_output = output;
    if(m_isVisible) {
        emit sendOutput(QVariant(m_output));
    }
}

/*!
 \details
 \fn SH_IOState::setVisibility TODO comment this

*/
void SH_InOutState::setVisibility(bool isVisible)
{
    m_isVisible = isVisible;
}

/*!
 \details
 \fn SH_IOState::visibility TODO comment this

*/
bool SH_InOutState::visibility() {
    return m_isVisible;
}

void SH_InOutState::display(bool canDisplay)
{
    m_display=canDisplay;
    if(m_display && !m_output.isEmpty() && m_isVisible) {
        qDebug() << "resalut !" << QVariant(m_output);
        emit sendOutput(QVariant(m_output));
    }
}

/*!
 \details

 \fn SH_IOState::onExit

*/
void SH_InOutState::onExit(QEvent *event)
{
    SH_GenericState::onExit(event);
    if(m_isVisible) {
        emit resendInput(m_input);
    }
}
