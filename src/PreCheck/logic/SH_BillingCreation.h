#ifndef BILLINGCREATIONSTATEMACHINE_H
#define BILLINGCREATIONSTATEMACHINE_H
#include "SH_IOStateMachine.h"

class SH_BillingCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
    SH_BillingCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // BILLINGCREATIONSTATEMACHINE_H
