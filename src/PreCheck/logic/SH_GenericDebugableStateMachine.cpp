#include "SH_GenericDebugableStateMachine.h"
#include "SH_GenericDebugableState.h"
#include "QFinalState"
#include "QDebug"

SH_GenericStateMachine::SH_GenericStateMachine(QString name, QObject *parent) :
    QStateMachine(parent), SH_NamedObject(name)
{
    connect(this, &SH_GenericStateMachine::goNext, this, &SH_GenericStateMachine::emitGoNext);
    this->blockSignals(!m_isRunning);
}


QString SH_GenericStateMachine::toString()
{
    QObject* parent = this->parent();
    SH_GenericState* par = qobject_cast<SH_GenericState *>(parent);
    if(par) {
        return SH_NamedObject::toString()+ " [descending from "+par->toString()+"] ";
    } else {
        return SH_NamedObject::toString();
    }
}

bool SH_GenericStateMachine::isRunning()
{
    return m_isRunning;
}


void SH_GenericStateMachine::emitGoNext()
{
    if(isRunning()) {
        emit next();
    }
}


void SH_GenericStateMachine::onEntry(QEvent *event)
{
    m_isRunning = true;
    this->blockSignals(!m_isRunning);
    qDebug() << "Machine: " << machine()->objectName() << " entered " << this->name();
}

void SH_GenericStateMachine::onExit(QEvent *event)
{
    m_isRunning = false;
    this->blockSignals(!m_isRunning);
    qDebug() << "Machine: " << machine()->objectName() << " exited  " << name();
}


/*!
 \details \~french

 \fn SH_GenericStateMachine::addChildrenNextTransition

*/
void SH_GenericStateMachine::addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_GenericStateMachine* fsmPreviousState = qobject_cast<SH_GenericStateMachine*>(previousState);
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(!final) {
        if(genPreviousState) {
            qDebug() << "next transition between " << genPreviousState->toString() << " and " << nextState;
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextState);
        }
        if(fsmPreviousState) {
            qDebug() << "next transition between " << fsmPreviousState->toString() << " and " << nextState;
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextState);
        }
    }
}
