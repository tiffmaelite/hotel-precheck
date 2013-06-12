#include "loopingstatemachine.h"

LoopingStateMachine::LoopingStateMachine(QString tableName, int limit, QString name, QObject *parent) :
    IOStateMachine(tableName, name, parent), m_limit(limit), m_current(-1)
{

}


int LoopingStateMachine::current() const
{
    return m_current;
}

void LoopingStateMachine::setCurrent(int current)
{
    m_current = current;
}

int LoopingStateMachine::limit() const
{
    return m_limit;
}

void LoopingStateMachine::setLimit(int limit)
{
    m_limit = limit;
}
