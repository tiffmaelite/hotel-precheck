#include "servicecharging.h"

ServiceCharging::ServiceCharging(QString name, QObject *parent) :
    LoopingIOStateMachine("CHARGEDSERVICES",name, 0, parent)
{
}
