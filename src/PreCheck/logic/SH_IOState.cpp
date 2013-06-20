#include "SH_IOState.h"

/*!
 \brief

 \fn IOState::IOState
 \param output
 \param name
 \param parent
*/
SH_InOutState::SH_InOutState(QString output, QString name, QState *parent) :
    SH_GenericState(name, parent), m_output(output), m_isVisible(true)
{
}

/*!
 \brief

 \fn IOState::input
 \return QVariant
*/
QVariant SH_InOutState::input() const
{
    return m_input;
}

/*!
 \brief
 \fn IOState::rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant SH_InOutState::rawInput() const
{
    return input();
}

/*!
 \brief

 \fn IOState::setInput
 \param input
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
 \brief

 \fn IOState::output
 \return QString
*/
QString SH_InOutState::output() const
{
    return m_output;
}


/*!
 \brief

 \fn IOState::setOutput
 \param output
*/
void SH_InOutState::setOutput(const QString &output)
{
    m_output = output;
    if(m_isVisible) {
        emit sendOutput(QVariant(m_output));
    }
}

/*!
 \brief
 \fn IOState::setVisibility TODO comment this
 \param isVisible TODO comment this
*/
void SH_InOutState::setVisibility(bool isVisible)
{
    m_isVisible = isVisible;
}

/*!
 \brief
 \fn IOState::visibility TODO comment this
 \return bool TODO comment this
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
 \brief

 \fn IOState::onExit
 \param event
*/
void SH_InOutState::onExit(QEvent *event)
{
    SH_GenericState::onExit(event);
    if(m_isVisible) {
        emit resendInput(m_input);
    }
}
