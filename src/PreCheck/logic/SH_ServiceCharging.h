#ifndef SERVICECHARGING_H
#define SERVICECHARGING_H
#include "SH_LoopingIOStateMachine.h"

class SH_ServiceCharging : public Sh_LoopingInOutStateMachine
{
    Q_OBJECT
public:
    SH_ServiceCharging(QString name, QObject *parent = 0);

signals:

public slots:

private:
    qreal m_priceMin;
    qreal m_vat;

};

#endif // SERVICECHARGING_H
