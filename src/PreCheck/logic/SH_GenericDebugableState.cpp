#include "SH_GenericDebugableState.h"
#include "SH_IOStateMachine.h"

/*!
 \details \~french

 \fn SH_GenericState::GenericState

*/
SH_GenericState::SH_GenericState(QString name, QState *parent) :
    QState(parent), SH_NamedObject(name), m_isRunning(false)
{
    connect(this, &SH_GenericState::goNext, this, &SH_GenericState::emitGoNext);
    this->blockSignals(!m_isRunning);
}

/*!
 \details \~french
 \fn SH_GenericState::toString

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

void SH_GenericState::emitGoNext()
{
    if(this->isRunning()) {
        emit next();
    }
}



/*!
 \details \~french
 \fn SH_GenericState::onTransitionTriggered
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
 \details \~french
 \fn SH_GenericState::onEntry

*/
void SH_GenericState::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    m_isRunning = true;
    this->blockSignals(!m_isRunning);
    qDebug() << "Machine: " << machine()->objectName() << " entered " << name();
}

/*!
 \details \~french
 \fn SH_GenericState::onExit

*/
void SH_GenericState::onExit(QEvent *event)
{
    Q_UNUSED(event);
    m_isRunning = false;
    this->blockSignals(!m_isRunning);
    qDebug() << "Machine: " << machine()->objectName() << " exited  " << name();
}

bool SH_GenericState::isRunning()
{
    return m_isRunning;
}

/*!
 \details \~french
 \fn SH_GenericState::onMachineStarted
*/
void SH_GenericState::onMachineStarted()
{
    foreach (QAbstractTransition* tr, transitions())
        connect(tr, SIGNAL(triggered()), this, SLOT(onTransitionTriggered()));
}
