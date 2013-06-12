#include "statementstate.h"

StatementState::StatementState(QString output, QString name, QState *parent) :
    IOState(output, name, parent)
{

}

void StatementState::setInput(const QVariant &input)
{
    Q_UNUSED(input);
    //DO NOTHING
}

void StatementState::onEntry(QEvent *event)
{
    IOState::onEntry(event);
    emit next();
}
