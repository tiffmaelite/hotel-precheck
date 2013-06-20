#include "SH_StatementState.h"

/*!
 \brief

 \fn StatementState::StatementState
 \param output
 \param name
 \param parent
*/
SH_StatementState::SH_StatementState(QString output, QString name, QState *parent) :
    SH_InOutState(output, name, parent)
{
    qDebug() << "salut ! "<< output;
}

/*!
 \brief

 \fn StatementState::setInput
 \param input
*/
void SH_StatementState::setInput(const QVariant &input)
{
    Q_UNUSED(input);
    //DO NOTHING
}

/*!
 \brief

 \fn StatementState::onEntry
 \param event
*/
void SH_StatementState::onEntry(QEvent *event)
{
    SH_GenericState::onEntry(event);
    display(true);
    emit next();
}
