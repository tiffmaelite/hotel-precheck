#include "SH_LoopingIOStateMachine.h"
#include "SH_AdaptDatabaseState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_LoopingStateMachine::LoopingStateMachine
*/
SH_LoopingInOutStateMachine::SH_LoopingInOutStateMachine(QString tableName, QString name, int limit, QObject *parent) :
    SH_InOutStateMachine(tableName, name, parent), m_limit(limit), m_current(-1)
{
}
/*!
 * \details \~french
 * \fn SH_LoopingStateMachine::current
*/
int SH_LoopingInOutStateMachine::current() const
{
    return m_current;
}
/*!
 * \details \~french
 * \fn SH_LoopingStateMachine::setCurrent
*/
void SH_LoopingInOutStateMachine::setCurrent(int current)
{
    m_current = current;
}
void SH_LoopingInOutStateMachine::setPersistentContentValue(QVariant value, QString field)
{
    m_persistentContent.insert(field, value);
}
/*!
 * \details \~french
 * \fn SH_LoopingStateMachine::limit
*/
int SH_LoopingInOutStateMachine::limit() const
{
    return m_limit;
}
/*!
 * \details \~french
 * \fn SH_LoopingStateMachine::setLimit
*/
void SH_LoopingInOutStateMachine::setLimit(int limit)
{
    m_limit = limit;
    emit limitChanged();
}
/*!
 * \details \~french
 * \fn SH_LoopingIOStateMachine::stopLooping
*/
void SH_LoopingInOutStateMachine::stopLooping() {
    if(m_limit == 0) {
        m_limit = m_current + 1;
    } else {
        m_current = m_limit - 1;
    }
}
/*!
 * \details \~french
 * \fn SH_IOStateMachine::addChildrenNextTransition
*/
void SH_LoopingInOutStateMachine::setStatesNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    SH_InOutStateMachine* fsmPreviousState = qobject_cast<SH_InOutStateMachine*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(final) {

        /*à faire au moment de l'entrée dans l'état previousState*/
        connect(previousState, &QAbstractState::entered, [=]() {
            m_current++;
            m_contents.append(m_ioContent);
            m_ioContent.clear();
            m_ioContent = m_persistentContent;
            if(m_limit == 0 || m_current < m_limit) {
                if(genPreviousState) {
                    connect(genPreviousState, &QAbstractState::entered, [=]() {
                        genPreviousState->addTransition(genPreviousState, SIGNAL(next()), initialState());
                    });
                }
                if(fsmPreviousState) {
                    connect(fsmPreviousState, &QAbstractState::entered, [=]() {
                        fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), initialState());
                    });
                }
            } else {
                SH_AdaptDatabaseState* nextSaveState = new SH_AdaptDatabaseState("enregistrement 0 de la machine "+toString());
                if(genPreviousState) {
                    genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextSaveState);
                }
                if(fsmPreviousState) {
                    fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextSaveState);
                }
                if(genPreviousState || fsmPreviousState) {
                    for(int i = 1; i < m_limit; i++) {
                        SH_AdaptDatabaseState* saveState = nextSaveState;
                        nextSaveState = new SH_AdaptDatabaseState(QString("enregistrement %1 de la machine %2").arg(QString::number(i)).arg(toString()));
                        saveState->addTransition(saveState, SIGNAL(next()),nextSaveState);
                        connect(saveState, &QAbstractState::exited, [=]() {
                            connect(nextSaveState, &QAbstractState::entered, [=]() {
                                setContentValue(nextSaveState->insertUpdate(m_tableName, m_contents[i]), "ID");
                            });
                        });
                    }
                    nextSaveState->addTransition(nextSaveState, SIGNAL(next()),final);
                }
            }
        });
    }
    if(genPreviousState) {

        /*à faire au moment de l'entrée dans l'état previousState*/
        connect(genPreviousState, &QAbstractState::entered, [=]() {
            connect(this, &SH_InOutStateMachine::replaceInput, [=](QString field) {

                /*après avoir demandé à revenir sur un état précédent, on attend la fin de l'état actuel puis on retourne à l'historique de l'état désiré; celui-ci fini, on passe à l'état qui aurait du suivre celui pendant lequel on a demandé à revenir sur un état précédent*/
                QHistoryState* hState = historyValue(field);
                if(hState) {
                    /*si l'historique existe (on a déjà quitté l'état voulu)*/
                    hState->parentState()->addTransition(hState->parentState(), SIGNAL(next()), nextState);
                    genPreviousState->addTransition(genPreviousState, SIGNAL(next()), hState);
                }
            });
        });
    }
    SH_InOutStateMachine::addChildrenReplaceTransition(previousState, nextState);
    SH_GenericStateMachine::setStatesNextTransition(previousState, nextState);
}
/*}*/
