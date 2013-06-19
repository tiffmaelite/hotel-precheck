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

/*!
 \brief
 \fn GenericState::onTransitionTriggered TODO comment this
*/
void GenericState::onTransitionTriggered()
{
    QAbstractTransition* tr = qobject_cast<QAbstractTransition*>(sender());
    if (tr == 00) return;

    GenericState* sourceState = qobject_cast<GenericState*>(tr->sourceState());
    GenericState* targetState = qobject_cast<GenericState*>(tr->targetState());

    QString log;
    QTextStream logStream(&log);
    logStream << machine()->objectName() << " transition from ";
    if (sourceState) logStream << sourceState->name();
    else logStream << tr->sourceState();
    logStream << " to ";
    if (targetState) logStream << targetState->name();
    else logStream << tr->targetState();
    logStream.flush();
    qDebug() << "Machine: " << log;
}


/*!
 \brief
 \fn GenericState::onEntry TODO comment this
 \param event TODO comment this
*/
void GenericState::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "Machine: " << machine()->objectName() << " entered " << name();
}

/*!
 \brief
 \fn GenericState::onExit TODO comment this
 \param event TODO comment this
*/
void GenericState::onExit(QEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "Machine: " << machine()->objectName() << " exited  " << name();
}

/*!
 \brief
 \fn GenericState::onMachineStarted TODO comment this
*/
void GenericState::onMachineStarted()
{
    foreach (QAbstractTransition* tr, transitions())
           connect(tr, SIGNAL(triggered()), this, SLOT(onTransitionTriggered()));
}
