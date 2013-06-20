#include "SH_StatementState.h"

/*!
 \details

 \fn SH_StatementState::StatementState

*/
SH_StatementState::SH_StatementState(QString output, QString name, QState *parent) :
    SH_InOutState(output, name, parent)
{
    qDebug() << "salut ! "<< output;
}

/*!
 \details

 \fn SH_StatementState::setInput

*/
void SH_StatementState::setInput(const QVariant &input)
{
    Q_UNUSED(input);
    /*DO NOTHING*/
}

/*!
 \details

 \fn SH_StatementState::onEntry

*/
void SH_StatementState::onEntry(QEvent *event)
{
    SH_GenericState::onEntry(event);
    display(true);
    emit next();
}
