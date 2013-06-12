#include "loopingstatemachine.h"

/*!
 \brief

 \fn LoopingStateMachine::LoopingStateMachine
 \param tableName
 \param limit
 \param name
 \param parent
*/
LoopingStateMachine::LoopingStateMachine(QString tableName, int limit, QString name, QObject *parent) :
    IOStateMachine(tableName, name, parent), m_limit(limit), m_current(-1)
{

}


/*!
 \brief

 \fn LoopingStateMachine::current
 \return int
*/
int LoopingStateMachine::current() const
{
    return m_current;
}

/*!
 \brief

 \fn LoopingStateMachine::setCurrent
 \param current
*/
void LoopingStateMachine::setCurrent(int current)
{
    m_current = current;
}

/*!
 \brief

 \fn LoopingStateMachine::limit
 \return int
*/
int LoopingStateMachine::limit() const
{
    return m_limit;
}

/*!
 \brief

 \fn LoopingStateMachine::setLimit
 \param limit
*/
void LoopingStateMachine::setLimit(int limit)
{
    m_limit = limit;
}
