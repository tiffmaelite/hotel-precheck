#ifndef SERVICECHARGING_H
#define SERVICECHARGING_H
#include "loopingstatemachine.h"

class ServiceCharging : public LoopingIOStateMachine
{
    Q_OBJECT
public:
    ServiceCharging(QString name, QObject *parent = 0);

signals:

public slots:

private:
    qreal m_priceMin;
    qreal m_vat;

};

#endif // SERVICECHARGING_H
