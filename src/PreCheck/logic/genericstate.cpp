#include "genericstate.h"
#include "iostatemachine.h"

GenericState::GenericState(QString name, QState *parent) :
    QState(parent), NamedObject(name)
{
}

QString GenericState::toString()
{
    QStateMachine* machine = this->machine();
    IOStateMachine* mach = qobject_cast<IOStateMachine *>(machine);
    if(mach) {
        return NamedObject::toString()+ " [in "+mach->toString()+"] ";
    } else {
        return NamedObject::toString();
    }
}
