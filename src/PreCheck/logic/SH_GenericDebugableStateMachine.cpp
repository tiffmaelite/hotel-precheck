#include "SH_GenericDebugableStateMachine.h"
#include "SH_GenericDebugableState.h"
#include "QFinalState"
#include <QSignalTransition>
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
    connect(this, &SH_GenericStateMachine::entered, this, &SH_GenericStateMachine::start);
    this->m_errorState = new SH_GenericState("error state");
    this->addState(this->m_errorState);
    this->setErrorState(this->m_errorState);
    /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
    connect(this->m_errorState, &QState::entered, [=]() {
        SH_MessageManager::errorMessage("Error in machine " +this->toString() + ": " + this->errorString());
    });
    connect(this->m_errorState, &QState::exited, [=]() {
        this->m_errorState->disconnect(this);
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
    if(this->isRunning()) {
        emit next();
    }
}

QAbstractState *SH_GenericStateMachine::currentState()
{
    return this->m_currentState;
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
    SH_MessageManager::debugMessage(this->objectName() + " entered");
}
/*!
 * \brief
 * \fn SH_GenericStateMachine::onExit
 * \param event
*/
void SH_GenericStateMachine::onExit(QEvent *event)
{
    Q_UNUSED(event);
    SH_MessageManager::debugMessage(this->objectName() + " exited");
}
/*!
 * \details \~french
 * \fn SH_GenericStateMachine::addChildrenNextTransition
*/
void SH_GenericStateMachine::setStatesNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    QState* pState = qobject_cast<QState*>(previousState);
    if(pState) {
        QList<QAbstractTransition*> transitions = pState->transitions();
        foreach(QAbstractTransition* tran, transitions) {
            QSignalTransition* signalTransition = qobject_cast<QSignalTransition*>(tran);
            if(signalTransition) {
                //SH_MessageManager::infoMessage(QString(signalTransition->signal()));
                if(signalTransition->signal().contains("next()")) {
                    pState->removeTransition(signalTransition);
                }
            }
        }

        SH_GenericStateMachine* fsmPreviousState = qobject_cast<SH_GenericStateMachine*>(previousState);
        SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
        if(genPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {
                connect(genPreviousState, &SH_GenericState::entered, [=]() {*/
            //SH_MessageManager::debugMessage(QString("next transition between %1 and %2").arg(genPreviousState->toString()).arg(nextState->objectName()));
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextState);
            /*});*/

            connect(genPreviousState, &SH_GenericState::exited, [=]() {
                genPreviousState->disconnect(this);
            });
            /*});*/
        }
        if(fsmPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {
                connect(fsmPreviousState, &SH_GenericStateMachine::entered, [=]() {*/
            //SH_MessageManager::debugMessage(QString("next transition between %1 and %2").arg(fsmPreviousState->toString()).arg(nextState->objectName()));
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextState);
            /*});*/
            connect(fsmPreviousState, &SH_GenericStateMachine::exited, [=]() {
                fsmPreviousState->disconnect(this);
            });
            /*});*/
        }
    }
}
/*}*/
