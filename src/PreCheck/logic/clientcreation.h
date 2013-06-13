#ifndef CLIENTCREATION_H
#define CLIENTCREATION_H
#include "iostatemachine.h"

class ClientCreationStateMachine : public IOStateMachine
{
    Q_OBJECT
public:
    ClientCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // CLIENTCREATION_H
