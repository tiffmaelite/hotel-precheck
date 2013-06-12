#include "statementstate.h"

/*!
 \brief

 \fn StatementState::StatementState
 \param output
 \param name
 \param parent
*/
StatementState::StatementState(QString output, QString name, QState *parent) :
    IOState(output, name, parent)
{

}

/*!
 \brief

 \fn StatementState::setInput
 \param input
*/
void StatementState::setInput(const QVariant &input)
{
    Q_UNUSED(input);
    //DO NOTHING
}

/*!
 \brief

 \fn StatementState::onEntry
 \param event
*/
void StatementState::onEntry(QEvent *event)
{
    IOState::onEntry(event);
    emit next();
}
