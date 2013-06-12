#include "iostate.h"

IOState::IOState(QString output, QString name, QState *parent) :
    GenericState(name, parent), m_output(output)
{
}

QVariant IOState::input() const
{
    return m_input;
}

void IOState::setInput(const QVariant &input)
{
    m_input = input;
    emit resendInput(m_input);
}

QString IOState::output() const
{
    return m_output;
}

void IOState::onEntry(QEvent *event)
{
    GenericState::onEntry(event);
    if(!m_output.isEmpty()) {
        emit sendOutput(QVariant(m_output));
    }
}

void IOState::setOutput(const QString &output)
{
    m_output = output;
    emit sendOutput(QVariant(m_output));
}

void IOState::onExit(QEvent *event)
{
    GenericState::onExit(event);
    emit resendInput(m_input);
}
