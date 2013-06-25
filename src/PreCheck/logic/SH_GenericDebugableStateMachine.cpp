#include "SH_GenericDebugableStateMachine.h"
#include "SH_GenericDebugableState.h"
#include "QFinalState"
#include <QDebug>
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \brief
 * \fn SH_GenericStateMachine::SH_GenericStateMachine
 * \param name
 * \param parent
*/
SH_GenericStateMachine::SH_GenericStateMachine(QString name, QObject *parent) :
    QStateMachine(parent), SH_NamedObject(name), m_currentState(NULL)
{
    this->setObjectName(name);
    connect(this, &SH_GenericStateMachine::goNext, this, &SH_GenericStateMachine::emitGoNext);
    m_errorState = new SH_GenericState("error state");
    this->addState(m_errorState);
    this->setErrorState(m_errorState);
    /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
    connect(m_errorState, &QState::entered, [=]() {
        SH_MessageManager::errorMessage("Error in machine " +this->toString() + ": " + this->errorString());
    });
    connect(m_errorState, &QState::exited, [=]() {
        m_errorState->disconnect(this);
    });
    /*});*/
}
/*!
 * \brief
 * \fn SH_GenericStateMachine::toString
 * \return QString
*/
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

/*!
 * \brief
 * \fn SH_GenericStateMachine::emitGoNext
*/
void SH_GenericStateMachine::emitGoNext()
{
    if(isRunning()) {
        emit next();
    }
}

void SH_GenericStateMachine::addState(QAbstractState *state) {
    /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
    connect(state, &QAbstractState::entered, [=]() {
        this->m_currentState = state;
    });
    connect(state, &QAbstractState::exited, [=]() {
        this->m_currentState = NULL;
        state->disconnect(this);
    });
    /*});*/
    QStateMachine::addState(state);
}

/*!
 * \brief
 * \fn SH_GenericStateMachine::onEntry
 * \param event
*/
void SH_GenericStateMachine::onEntry(QEvent *event)
{
    Q_UNUSED(event);
    SH_MessageManager::debugMessage(this->name() + " entered");
}
/*!
 * \brief
 * \fn SH_GenericStateMachine::onExit
 * \param event
*/
void SH_GenericStateMachine::onExit(QEvent *event)
{
    Q_UNUSED(event);
    SH_MessageManager::debugMessage(this->name() + " exited");
}
/*!
 * \details \~french
 * \fn SH_GenericStateMachine::addChildrenNextTransition
*/
void SH_GenericStateMachine::addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_GenericStateMachine* fsmPreviousState = qobject_cast<SH_GenericStateMachine*>(previousState);
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(!final) {
        if(genPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {
                connect(genPreviousState, &SH_GenericState::entered, [=]() {*/
            //SH_MessageManager::debugMessage(QString("next transition between %1 and %2").arg(genPreviousState->toString()).arg(nextState->objectName()));
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextState);
            /*});

                connect(genPreviousState, &SH_GenericState::exited, [=]() {
                    genPreviousState->disconnect(this);
                });
            });*/
        }
        if(fsmPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {
                connect(fsmPreviousState, &SH_GenericStateMachine::entered, [=]() {*/
            //SH_MessageManager::debugMessage(QString("next transition between %1 and %2").arg(fsmPreviousState->toString()).arg(nextState->objectName()));
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextState);
            /*});

                connect(fsmPreviousState, &SH_GenericStateMachine::exited, [=]() {
                    fsmPreviousState->disconnect(this);
                });
            });*/
        }
    }
}
/*}*/
