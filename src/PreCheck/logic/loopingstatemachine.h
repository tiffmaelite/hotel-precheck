#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "iostatemachine.h"

class LoopingStateMachine : public IOStateMachine
{
    Q_OBJECT
public:
    LoopingStateMachine(QString tableName, int limit, QString name, QObject *parent = 0);

    int current() const;
    void setCurrent(int current);

    int limit() const;
    void setLimit(int limit);

signals:

public slots:

private:
    int m_limit;
    int m_current;

};

#endif // LOOPINGSTATEMACHINE_H
