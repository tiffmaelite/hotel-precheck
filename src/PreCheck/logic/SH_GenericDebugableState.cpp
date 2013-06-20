#include "SH_GenericDebugableState.h"
#include "SH_IOStateMachine.h"

/*!
 \brief

 \fn GenericState::GenericState
 \param name
 \param parent
*/
SH_GenericState::SH_GenericState(QString name, QState *parent) :
    QState(parent), SH_NamedObject(name)
{
}

/*!
 \brief

 \fn GenericState::toString
 \return QString
*/
QString SH_GenericState::toString()
{
    QStateMachine* machine = this->machine();
    SH_InOutStateMachine* mach = qobject_cast<SH_InOutStateMachine *>(machine);
    if(mach) {
        return SH_NamedObject::toString()+ " [in "+mach->toString()+"] ";
    } else {
        return SH_NamedObject::toString();
    }
}

/*!
 \brief
 \fn GenericState::onTransitionTriggered TODO comment this
*/
void SH_GenericState::onTransitionTriggered()
{
    QAbstractTransition* tr = qobject_cast<QAbstractTransition*>(sender());
    if (tr == 00) return;

    SH_GenericState* sourceState = qobject_cast<SH_GenericState*>(tr->sourceState());
    SH_GenericState* targetState = qobject_cast<SH_GenericState*>(tr->targetState());

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
void SH_GenericState::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "Machine: " << machine()->objectName() << " entered " << name();
}

/*!
 \brief
 \fn GenericState::onExit TODO comment this
 \param event TODO comment this
*/
void SH_GenericState::onExit(QEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "Machine: " << machine()->objectName() << " exited  " << name();
}

/*!
 \brief
 \fn GenericState::onMachineStarted TODO comment this
*/
void SH_GenericState::onMachineStarted()
{
    foreach (QAbstractTransition* tr, transitions())
           connect(tr, SIGNAL(triggered()), this, SLOT(onTransitionTriggered()));
}
