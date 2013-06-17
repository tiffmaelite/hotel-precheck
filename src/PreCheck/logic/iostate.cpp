#include "iostate.h"

/*!
 \brief

 \fn IOState::IOState
 \param output
 \param name
 \param parent
*/
IOState::IOState(QString output, QString name, QState *parent) :
    GenericState(name, parent), m_output(output), m_isVisible(true)
{
}

/*!
 \brief

 \fn IOState::input
 \return QVariant
*/
QVariant IOState::input() const
{
    return m_input;
}

/*!
 \brief
 \fn IOState::rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant IOState::rawInput() const
{
    return input();
}

/*!
 \brief

 \fn IOState::setInput
 \param input
*/
void IOState::setInput(const QVariant &input)
{
    qDebug() << "new input " << input.toString();
    m_input = input;
    if(m_isVisible) {
        emit resendInput(m_input);
    }
    emit next();
}

/*!
 \brief

 \fn IOState::output
 \return QString
*/
QString IOState::output() const
{
    return m_output;
}


/*!
 \brief

 \fn IOState::setOutput
 \param output
*/
void IOState::setOutput(const QString &output)
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
void IOState::setVisibility(bool isVisible)
{
    m_isVisible = isVisible;
}

/*!
 \brief
 \fn IOState::visibility TODO comment this
 \return bool TODO comment this
*/
bool IOState::visibility() {
    return m_isVisible;
}

void IOState::display(bool canDisplay)
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
void IOState::onExit(QEvent *event)
{
    GenericState::onExit(event);
    if(m_isVisible) {
        emit resendInput(m_input);
    }
}
