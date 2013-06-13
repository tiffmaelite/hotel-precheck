#ifndef BILLINGCREATIONSTATEMACHINE_H
#define BILLINGCREATIONSTATEMACHINE_H
#include "iostatemachine.h"

class BillingCreationStateMachine : public IOStateMachine
{
    Q_OBJECT
public:
    BillingCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // BILLINGCREATIONSTATEMACHINE_H
