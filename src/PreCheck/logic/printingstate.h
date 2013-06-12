#ifndef PRINTINGSTATE_H
#define PRINTINGSTATE_H
#include "genericstate.h"

class PrintingState : public GenericState
{
    Q_OBJECT
public:
    PrintingState(QString name, QState *parent = 0);

signals:
    void printStarted();
    void printFinished();

public slots:

};

#endif // PRINTINGSTATE_H
