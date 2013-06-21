#include "SH_IOStateMachine.h"
#include "SH_ValidationState.h"
#include "SH_ConfirmationState.h"
#include "SH_FileSelectionState.h"
#include "SH_DateQuestionState.h"
#include "SH_AdaptDatabaseState.h"

/*!
 \details \~french

 \fn SH_IOStateMachine::IOStateMachine

*/
SH_InOutStateMachine::SH_InOutStateMachine(QString tableName, QString name, QObject *parent) :
    QStateMachine(parent), SH_NamedObject(name), m_tableName(tableName)
{
    qDebug() << "nouvelle IOStateMachine";
}

/*!
 \details \~french

 \fn SH_IOStateMachine::toString

*/
QString SH_InOutStateMachine::toString()
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
 \details \~french

 \fn SH_IOStateMachine::ioContent

*/
QVariantMap SH_InOutStateMachine::ioContent() const
{
    return m_ioContent;
}

/*!
 \details \~french

 \fn SH_IOStateMachine::setIOcontent

*/
void SH_InOutStateMachine::setIOcontent(const QVariantMap &ioContent)
{
    m_ioContent = ioContent;
}

/*!
 \details \~french

 \fn SH_IOStateMachine::getContentValue

*/
QVariant SH_InOutStateMachine::getContentValue(QString field)
{
    return m_ioContent.value(field);
}

/*!
 \details \~french

 \fn SH_IOStateMachine::tableName

*/
QString SH_InOutStateMachine::tableName() const
{
    return m_tableName;
}

/*!
 \details \~french

 \fn SH_IOStateMachine::setTableName

*/
void SH_InOutStateMachine::setTableName(const QString &tableName)
{
    m_tableName = tableName;
}


/*!
 \details \~french

 \fn SH_IOStateMachine::setContentValue

*/
void SH_InOutStateMachine::setContentValue(QVariant content, QString field)
{
    m_ioContent.insert(field, content);
}

/*!
 \details \~french

 \fn SH_IOStateMachine::addIOState

*/
void SH_InOutStateMachine::addIOState(SH_InOutState *state, QString field)
{
    /*à faire au moment de l'entrée dans l'état state*/
    connect(state, &QState::entered, [=]() {
        qDebug() << "entered !";
        state->display(true);
        connect(this, &SH_InOutStateMachine::receiveInput, state, &SH_InOutState::setInput); /* la réception d'une valeur entraîne son enregistrement comme entrée de l'utilisateur auprès de l'état*/
        connect(this, &SH_InOutStateMachine::receiveInput, [=](QString in){ qDebug() << "hello world !"; state->setInput(in);}); /* la réception d'une valeur entraîne son enregistrement comme entrée de l'utilisateur auprès de l'état*/
        connect(state, &SH_InOutState::sendOutput, [=](QVariant out) {qDebug() << "connected !"; emit this->sendText(out.toString(), false);});
        connect(state, &SH_InOutState::resendInput, [=](QVariant in) {emit this->resendText(in.toString(), true);});
        if(state->visibility()) {
            state->sendOutput(QVariant(state->output()));
        } else {
            qDebug() << "invisible";
        }
    });
    SH_ValidationState *validationState = qobject_cast<SH_ValidationState*>(state);
    if(validationState) {
        /*à faire au moment de l'entrée dans l'état state*/
        connect(validationState, &QState::entered, [=]() {
            connect(this, &SH_InOutStateMachine::validateInput, validationState, &SH_ValidationState::confirmInput);
        });
    }
    SH_ConfirmationState *confirmationState = qobject_cast<SH_ConfirmationState*>(state);
    if(confirmationState) {
        /*à faire au moment de l'entrée dans l'état state*/
        connect(confirmationState, &QState::entered, [=]() {
            connect(this, &SH_InOutStateMachine::validateInput, confirmationState, &SH_ConfirmationState::confirmInput);
        });
    }
    SH_DateQuestionState *dateState = qobject_cast<SH_DateQuestionState*>(state);
    if(dateState) {
        /*à faire au moment de l'entrée dans l'état state*/
        connect(dateState, &QState::entered, this, &SH_InOutStateMachine::displayCalendar);
    }
    SH_FileSelectionState *fileState = qobject_cast<SH_FileSelectionState*>(state);
    if(fileState) {
        /*à faire au moment de l'entrée dans l'état state*/
        connect(fileState, &QState::entered, this, &SH_InOutStateMachine::displayFileDialog);
    }
    /*à faire au moment de la sortie de l'état state*/
    connect(state, &QState::exited, [=]() {
        qDebug() << "exited !";
        if(!field.isEmpty()) {
            setContentValue(state->rawInput(), field);
            /*gestion de l'historique des états pour pouvoir revenir à l'état state après l'avoir quitté*/
            QHistoryState* hState = new QHistoryState(state);
            setIOStateHistory(hState, field);
        }
        state->disconnect(this); /*plus aucune action sur l'état ne pourra être provoquée par la machine*/
    });


    QAbstractState* astate = qobject_cast<QAbstractState *>(state);
    if(astate) {
        addState(astate);
    }
}

/*!
 \details \~french

 \fn SH_IOStateMachine::addIOStateMachine

*/
void SH_InOutStateMachine::addIOStateMachine(SH_InOutStateMachine *fsm)
{
    /*à faire au moment de l'entrée dans la machine d'état fsm*/
    connect(fsm, &QState::entered, [=]() {
        connect(this, &SH_InOutStateMachine::receiveInput, fsm, &SH_InOutStateMachine::receiveInput);
        connect(this, &SH_InOutStateMachine::sendText, fsm, &SH_InOutStateMachine::sendText);
        connect(this, &SH_InOutStateMachine::resendText, fsm, &SH_InOutStateMachine::resendText);
        connect(this, &SH_InOutStateMachine::confirmInput, fsm, &SH_InOutStateMachine::confirmInput);
        connect(this, &SH_InOutStateMachine::validateInput, fsm, &SH_InOutStateMachine::validateInput);
        connect(this, &SH_InOutStateMachine::replaceInput, fsm, &SH_InOutStateMachine::replaceInput);
        connect(this, &SH_InOutStateMachine::cancelReplacement, fsm, &SH_InOutStateMachine::cancelReplacement);
        connect(this, &SH_InOutStateMachine::displayCalendar, fsm, &SH_InOutStateMachine::displayCalendar);
    });
    /*à faire au moment de la sortie de la machine d'état fsm*/
    connect(fsm, &QState::exited, [=]() {
        fsm->disconnect(this); /*plus aucune action sur la machine d'état fille ne pourra être provoquée par la machine mère*/
    });

}


/*!
 \details \~french

 \fn SH_IOStateMachine::ioStatesHistory

*/
QMap<QString, QHistoryState *> SH_InOutStateMachine::ioStatesHistory() const
{
    return m_ioStatesHistory;
}


/*!
 \details \~french

 \fn SH_IOStateMachine::setIOStatesHistory

*/
void SH_InOutStateMachine::setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory)
{
    m_ioStatesHistory = ioStatesHistory;
}


/*!
 \details \~french

 \fn SH_IOStateMachine::setIOStateHistory

*/
void SH_InOutStateMachine::setIOStateHistory(QHistoryState *state, QString field)
{
    m_ioStatesHistory.insert(field, state); /*remplacement si plusieurs fois*/
}


/*!
 \details \~french

 \fn SH_IOStateMachine::historyValue

*/
QHistoryState *SH_InOutStateMachine::historyValue(QString field)
{
    return m_ioStatesHistory.value(field);
}


/*!
 \details \~french

 \fn SH_IOStateMachine::addChildrenNextTransition

*/
void SH_InOutStateMachine::addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    SH_InOutStateMachine* fsmPreviousState = qobject_cast<SH_InOutStateMachine*>(previousState);
    SH_GenericState* genPreviousState = qobject_cast<SH_GenericState*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(final) {
        SH_AdaptDatabaseState* saveState = new SH_AdaptDatabaseState("enregistrement de la machine "+toString());
        if(genPreviousState) {
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), saveState);
        }
        if(fsmPreviousState) {
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), saveState);
        }
        if(genPreviousState || fsmPreviousState) {
            connect(previousState, &QAbstractState::exited, [=]() {
                connect(saveState, &QAbstractState::entered, [=]() {
                    emit this->sendText("Merci !");
                    setContentValue(saveState->insertUpdate(m_tableName, m_ioContent), "ID");
                    emit this->clearAll();
                });
            });
            saveState->addTransition(saveState, SIGNAL(next()),final);
        }
    } else {
        if(genPreviousState) {
            qDebug() << "next transition between " << genPreviousState->toString() << " and " << nextState;
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextState);
        }
        if(fsmPreviousState) {
            qDebug() << "next transition between " << fsmPreviousState->toString() << " and " << nextState;
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextState);
        }
    }
    if(genPreviousState) {
        /*à faire au moment de l'entrée dans l'état previousState*/
        connect(genPreviousState, &QAbstractState::entered, [=]() {
            connect(this, &SH_InOutStateMachine::replaceInput, [=](QString field) {
                /*après avoir demandé à revenir sur un état précédent, on attend la fin de l'état actuel puis on retourne à l'historique de l'état désiré; celui-ci fini, on passe à l'état qui aurait du suivre celui pendant lequel on a demandé à revenir sur un état précédent*/
                QHistoryState* hState = historyValue(field);
                if(hState) { /*si l'historique existe (on a déjà quitté l'état voulu)*/
                    hState->parentState()->addTransition(hState->parentState(), SIGNAL(next()), nextState);
                    genPreviousState->addTransition(genPreviousState, SIGNAL(next()), hState);
                }
            });
        });
    }
}
