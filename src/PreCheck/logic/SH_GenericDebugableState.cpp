#include "SH_GenericDebugableState.h"
#include "SH_IOStateMachine.h"
#include "SH_MessageManager.h"
#include <QSignalTransition>

/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_GenericState::GenericState
*/
SH_GenericState::SH_GenericState(QString name, QState *parent) :
    QState(parent), SH_NamedObject(name), m_isRunning(false)
{
    this->setObjectName(name);
    connect(this, &SH_GenericState::goNext, this, &SH_GenericState::emitGoNext);
    this->blockSignals(!this->m_isRunning);
}

/*!
 * \details \~french
 * \fn SH_GenericState::toString
*/
QString SH_GenericState::toString()
{
    QStateMachine* machine = this->machine();
    SH_GenericState* mach = qobject_cast<SH_GenericState *>(machine);
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
 * \details \~french
 * \fn SH_GenericState::onTransitionTriggered
*/
void SH_GenericState::onTransitionTriggered()
{
    QAbstractTransition* tr = qobject_cast<QAbstractTransition*>(sender());
    if (tr == 00) return;
    QSignalTransition *str = qobject_cast<QSignalTransition*>(tr);
    QString signal = "";
    if(str) {
        signal = QString(str->signal());
    }
    SH_GenericState* sourceState = qobject_cast<SH_GenericState*>(tr->sourceState());
    SH_GenericState* targetState = qobject_cast<SH_GenericState*>(tr->targetState());
    SH_MessageManager::debugMessage(QString("transition triggered in %1 from %2 to %3 thanks to event %4").arg(machine()->objectName()).arg(sourceState->objectName()).arg(targetState->objectName()).arg(signal));
}
/*!
 * \details \~french
 * \fn SH_GenericState::onEntry
*/
void SH_GenericState::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    foreach (QAbstractTransition* tr, transitions()) {
        connect(tr, SIGNAL(triggered()), this, SLOT(onTransitionTriggered()));
    }
    this->m_isRunning = true;
    this->blockSignals(!this->m_isRunning);
    SH_MessageManager::debugMessage(QString("Machine: %1, entered state %2").arg(machine()->objectName()).arg(objectName()));
}
/*!
 * \details \~french
 * \fn SH_GenericState::onExit
*/
void SH_GenericState::onExit(QEvent *event)
{
    Q_UNUSED(event);
    this->m_isRunning = false;
    this->blockSignals(!this->m_isRunning);
    SH_MessageManager::debugMessage(QString("Machine: %1, exited state %2").arg(machine()->objectName()).arg(objectName()));
}
bool SH_GenericState::isRunning()
{
    return this->m_isRunning;
}
/*}*/
