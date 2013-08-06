#include "SH_IOStateMachine.h"
#include "SH_ValidationState.h"
#include "SH_ConfirmationState.h"
#include "SH_FileSelectionState.h"
#include "SH_DateQuestionState.h"
#include "SH_AdaptDatabaseState.h"
#include "SH_DatabaseContentQuestionState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_InOutStateMachine::SH_InOutStateMachine
*/
SH_InOutStateMachine::SH_InOutStateMachine(QString tableName, QString name, QObject *parent) :
    SH_GenericStateMachine(name, parent), m_tableName(tableName)
{
}

/*!
 * \details \~french
 * \fn SH_InOutStateMachine::getContentValue
*/
QVariant SH_InOutStateMachine::getContentValue(QString field)
{
    return this->m_ioContent.value(field);
}

/*!
 * \details \~french
 * \fn SH_InOutStateMachine::setContentValue
*/
void SH_InOutStateMachine::setContentValue(QVariant content, QString field)
{
    this->m_ioContent.insert(field, content);
}

void SH_InOutStateMachine::addState(QAbstractState *state)
{
    SH_MessageManager::debugMessage("chalut");
    SH_GenericStateMachine::addState(state);
}

void SH_InOutStateMachine::addState(SH_InOutState *state, QString field)
{
    SH_MessageManager::debugMessage("salioute state");
    SH_InOutStateMachine::addIOState(state, field);
}

/*!
 * \details \~french
 * \fn SH_InOutStateMachine::addState
*/
void SH_InOutStateMachine::addIOState(SH_InOutState *astate, QString field)
{
    SH_InOutState* state = qobject_cast<SH_InOutState *>(astate);
    if(state) {
        /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
        /*à faire au moment de l'entrée dans l'état state*/
        /*connect(state, &QAbstractState::entered, [=]() {*/
        /* la réception d'une valeur entraîne son enregistrement comme entrée de l'utilisateur auprès de l'état*/
        connect(state, &SH_InOutState::sendOutput, [=](QVariant out) { if(out.isValid()) {
                SH_MessageManager::infoMessage(out.toString(),"reçu de l'état");
                emit this->sendText(out.toString(), false);
            }});
        connect(this, &SH_InOutStateMachine::receiveInput, state, &SH_InOutState::setInput, Qt::QueuedConnection);
        connect(state, &SH_InOutState::resendInput, [=](QVariant in) {  if(in.isValid()) {
                SH_MessageManager::infoMessage(in.toString(),"envoyé par l'état");
                emit this->resendText(in.toString(), true);
            }});
        SH_MessageManager::debugMessage("salioute");
        SH_ValidationState *validationState = qobject_cast<SH_ValidationState*>(astate);
        if(validationState) {
            connect(this, &SH_InOutStateMachine::validateInput, validationState, &SH_ValidationState::confirmInput, Qt::QueuedConnection);
        }

        SH_ConfirmationState *confirmationState = qobject_cast<SH_ConfirmationState*>(astate);
        if(confirmationState) {
            connect(this, &SH_InOutStateMachine::validateInput, confirmationState, &SH_ConfirmationState::confirmInput, Qt::QueuedConnection);
        }

        SH_DateQuestionState *dateState = qobject_cast<SH_DateQuestionState*>(astate);
        if(dateState) {
            emit this->displayCalendar();
        }

        SH_DatabaseContentQuestionState *choiceState = qobject_cast<SH_DatabaseContentQuestionState*>(astate);
        if(choiceState) {
            connect(this, &SH_InOutStateMachine::displayChoiceList, choiceState, &SH_DatabaseContentQuestionState::displayChoiceList, Qt::QueuedConnection);
        }

        SH_FileSelectionState *fileState = qobject_cast<SH_FileSelectionState*>(astate);
        if(fileState) {
            emit this->displayFileDialog();
        }
        SH_MessageManager::debugMessage("salioute bis");
        /*});*/
        connect(state, &QAbstractState::exited, [=]() {
            if(!field.isEmpty()) {
                setContentValue(state->rawInput(), field);

                /*gestion de l'historique des états pour pouvoir revenir à l'état state après l'avoir quitté*/
                QHistoryState* hState = new QHistoryState(state);
                setIOStateHistory(hState, field);
            }
            /*plus aucune action sur l'état ne pourra être provoquée par la machine*/
            state->disconnect(this);
        });
        /*});*/
    }
    SH_MessageManager::debugMessage("salioute bis bis");
    QAbstractState* abstate = qobject_cast<QAbstractState *>(astate);
    if(abstate) {
        SH_InOutStateMachine::addState(abstate);
    }
}

/*!
 * \details \~french
 * \fn SH_InOutStateMachine::addState
*/
void SH_InOutStateMachine::addState(SH_InOutStateMachine *fsm, QString table)
{
    SH_InOutStateMachine::addStateMachine(fsm, table);
}

void SH_InOutStateMachine::addStateMachine(SH_InOutStateMachine *astate, QString table) {
    SH_MessageManager::debugMessage("salioute machine");
    SH_InOutStateMachine* fsm = qobject_cast<SH_InOutStateMachine *>(astate);
    if(fsm) {
        if(!table.isEmpty()) {
            fsm->setTableName(table);
        }
        /*connect(this, &SH_InOutStateMachine::entered, [=]() {*/
        /*à faire au moment de l'entrée dans la machine d'état fsm*/
        /*connect(fsm, &SH_InOutStateMachine::entered, [=]() {*/
        connect(this, &SH_InOutStateMachine::receiveInput, fsm, &SH_InOutStateMachine::receiveInput,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::sendText, fsm, &SH_InOutStateMachine::sendText,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::resendText, fsm, &SH_InOutStateMachine::resendText,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::confirmInput, fsm, &SH_InOutStateMachine::confirmInput,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::validateInput, fsm, &SH_InOutStateMachine::validateInput,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::replaceInput, fsm, &SH_InOutStateMachine::replaceInput,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::cancelReplacement, fsm, &SH_InOutStateMachine::cancelReplacement,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::displayCalendar, fsm, &SH_InOutStateMachine::displayCalendar,Qt::QueuedConnection);
        connect(this, &SH_InOutStateMachine::displayChoiceList, fsm, &SH_InOutStateMachine::displayChoiceList,Qt::QueuedConnection);
        /* });*/

        /*à faire au moment de la sortie de la machine d'état fsm*/
        /*connect(fsm, &SH_InOutStateMachine::exited, [=]() {*/
        /*plus aucune action sur la machine d'état fille ne pourra être provoquée par la machine mère*/
        /*fsm->disconnect(this);*/
        /*});*/
        /*});*/
    }
    QAbstractState* abstate = qobject_cast<QAbstractState *>(astate);
    if(abstate) {
        SH_InOutStateMachine::addState(abstate);
    }
}

/*!
 * \details \~french
 * \fn SH_InOutStateMachine::setIOStateHistory
*/
void SH_InOutStateMachine::setIOStateHistory(QHistoryState *state, QString field)
{
    /*remplacement si plusieurs fois, ajout sinon*/
    this->m_ioStatesHistory.insert(field, state);
}
/*!
 * \details \~french
 * \fn SH_InOutStateMachine::historyValue
*/
QHistoryState *SH_InOutStateMachine::historyValue(QString field)
{
    return this->m_ioStatesHistory.value(field);
}
/*!
 * \details \~french
 * \fn SH_InOutStateMachine::addChildrenReplaceTransition
*/
void SH_InOutStateMachine::addChildrenReplaceTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    if(genPreviousState) {
        /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
        /*à faire au moment de l'entrée dans l'état previousState*/
        /*connect(genPreviousState, &QAbstractState::entered, [=]() {*/
        connect(this, &SH_InOutStateMachine::replaceInput, [=](QString field) {
            /*après avoir demandé à revenir sur un état précédent, on attend la fin de l'état actuel puis on retourne à l'historique de l'état désiré; celui-ci fini, on passe à l'état qui aurait du suivre celui pendant lequel on a demandé à revenir sur un état précédent*/
            QHistoryState* hState = historyValue(field);
            if(hState) {
                /*si l'historique existe (on a déjà quitté l'état voulu)*/
                hState->parentState()->addTransition(hState->parentState(), SIGNAL(next()), nextState);
                genPreviousState->addTransition(genPreviousState, SIGNAL(next()), hState);
            }
        });
        /*});*/
        /*});*/
    }
}
/*!
 * \details \~french
 * \fn SH_InOutStateMachine::addChildrenNextTransition
*/
void SH_InOutStateMachine::setStatesNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_GenericStateMachine* fsmPreviousState = qobject_cast<SH_GenericStateMachine*>(previousState);
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(final) {
        SH_AdaptDatabaseState* saveState = new SH_AdaptDatabaseState("enregistrement de la machine "+toString());
        if(genPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
            connect(genPreviousState, &QAbstractState::exited, [=]() {
                emit this->sendText("Merci !");
                setContentValue(saveState->insertUpdate(this->m_tableName, this->m_ioContent), "ID");
            });
            /*});*/
        }
        if(fsmPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
            connect(genPreviousState, &QAbstractState::exited, [=]() {
                emit this->sendText("Merci !");
                setContentValue(saveState->insertUpdate(this->m_tableName, this->m_ioContent), "ID");
            });
            /*});*/
        }
        if(genPreviousState || fsmPreviousState) {
            /*connect(this, &SH_GenericStateMachine::entered, [=]() {*/
            connect(saveState, &QAbstractState::exited, [=]() {
                emit this->clearAll();
            });
            /*});*/
        }
        SH_GenericStateMachine::setStatesNextTransition(previousState, saveState);
        SH_GenericStateMachine::setStatesNextTransition(saveState, final);
    } else {
        SH_GenericStateMachine::setStatesNextTransition(previousState, nextState);
    }
}
/*}*/
