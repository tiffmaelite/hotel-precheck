#include "genericstate.h"
#include "iostatemachine.h"

/*!
 \brief

 \fn GenericState::GenericState
 \param name
 \param parent
*/
GenericState::GenericState(QString name, QState *parent) :
    QState(parent), NamedObject(name)
{
}

/*!
 \brief

 \fn GenericState::toString
 \return QString
*/
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
