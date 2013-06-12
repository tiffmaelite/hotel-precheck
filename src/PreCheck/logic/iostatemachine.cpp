#include "iostatemachine.h"
#include "validationstate.h"
#include "confirmationstate.h"
#include "datequestionstate.h"

IOStateMachine::IOStateMachine(QString tableName, QString name, QObject *parent) :
    QStateMachine(parent), NamedObject(name), m_tableName(tableName)
{
}

QString IOStateMachine::toString()
{
    QObject* parent = this->parent();
    GenericState* par = qobject_cast<GenericState *>(parent);
    if(par) {
        return NamedObject::toString()+ " [descending from "+par->toString()+"] ";
    } else {
        return NamedObject::toString();
    }
}

QVariantMap IOStateMachine::ioContent() const
{
    return m_ioContent;
}

void IOStateMachine::setIOcontent(const QVariantMap &ioContent)
{
    m_ioContent = ioContent;
}

QVariant IOStateMachine::getContentValue(QString field)
{
    return m_ioContent.value(field);
}

QString IOStateMachine::tableName() const
{
    return m_tableName;
}

void IOStateMachine::setTableName(const QString &tableName)
{
    m_tableName = tableName;
}


void IOStateMachine::setContentValue(QVariant content, QString field)
{
    m_ioContent.insert(field, content);
}

void IOStateMachine::addIOState(IOState *state, QString field)
{
    //à faire au moment de l'entrée dans l'état state
    connect(state, &QState::entered, [=]() {
        connect(this, &IOStateMachine::receiveInput, state, &IOState::setInput); // la réception d'une valeur entraîne son enregistrement comme entrée de l'utilisateur auprès de l'état
        connect(state, &IOState::sendOutput, [=](QVariant out) {this->sendText(out, false);});
        connect(state, &IOState::resendInput, [=](QVariant in) {this->sendText(in, true);});
    });
    ValidationState *validationState = qobject_cast<ValidationState*>(state);
    if(validationState) {
        //à faire au moment de l'entrée dans l'état state
        connect(validationState, &QState::entered, [=]() {
            connect(this, &IOStateMachine::validateInput, validationState, &ValidationState::confirmInput);
        });
    }
    ConfirmationState *confirmationState = qobject_cast<ConfirmationState*>(state);
    if(confirmationState) {
        //à faire au moment de l'entrée dans l'état state
        connect(confirmationState, &QState::entered, [=]() {
            connect(this, &IOStateMachine::validateInput, confirmationState, &ConfirmationState::confirmInput);
        });
    }
    DateQuestionState *dateState = qobject_cast<DateQuestionState*>(state);
    if(dateState) {
        //à faire au moment de l'entrée dans l'état state
        connect(dateState, &QState::entered, this, &IOStateMachine::displayCalendar);
    }
    //à faire au moment de la sortie de l'état state
    connect(state, &QState::exited, [=]() {
        if(!field.isEmpty()) {
            setContentValue(state->input(), field); //on enregistre la dernière valeur entrée par l'utilisateur conservée par l'état
            //gestion de l'historique des états pour pouvoir revenir à l'état state après l'avoir quitté
            QHistoryState* hState = new QHistoryState(state);
            setIOStateHistory(hState, field);
        }
        state->disconnect(this); //plus aucune action sur l'état ne pourra être provoquée par la machine
    });


    QAbstractState* astate = qobject_cast<QAbstractState *>(state);
    if(astate) {
        addState(astate);
    }
}

void IOStateMachine::addIOStateMachine(IOStateMachine *fsm)
{
    //à faire au moment de l'entrée dans la machine d'état fsm
    connect(fsm, &QState::entered, [=]() {
        connect(this, &IOStateMachine::receiveInput, fsm, &IOStateMachine::receiveInput);
        connect(this, &IOStateMachine::sendText, fsm, &IOStateMachine::sendText);
        connect(this, &IOStateMachine::confirmInput, fsm, &IOStateMachine::confirmInput);
        connect(this, &IOStateMachine::validateInput, fsm, &IOStateMachine::validateInput);
        connect(this, &IOStateMachine::replaceInput, fsm, &IOStateMachine::replaceInput);
        connect(this, &IOStateMachine::cancelReplacement, fsm, &IOStateMachine::cancelReplacement);
        connect(this, &IOStateMachine::displayCalendar, fsm, &IOStateMachine::displayCalendar);
    });
    //à faire au moment de la sortie de la machine d'état fsm
    connect(fsm, &QState::exited, [=]() {
        fsm->disconnect(this); //plus aucune action sur la machine d'état fille ne pourra être provoquée par la machine mère
    });

}


QMap<QString, QHistoryState *> IOStateMachine::ioStatesHistory() const
{
    return m_ioStatesHistory;
}


void IOStateMachine::setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory)
{
    m_ioStatesHistory = ioStatesHistory;
}


void IOStateMachine::setIOStateHistory(QHistoryState *state, QString field)
{
    m_ioStatesHistory.insert(field, state); //remplacement si plusieurs fois
}


QHistoryState *IOStateMachine::historyValue(QString field)
{
    return m_ioStatesHistory.value(field);
}


void IOStateMachine::addChildrenNextTransition(GenericState *previousState, GenericState *nextState)
{
    previousState->addTransition(previousState, SIGNAL(next()), nextState);
    //à faire au moment de l'entrée dans l'état previousState
    connect(previousState, &QState::entered, [=]() {
        connect(this, &IOStateMachine::replaceInput, [=](QString field) {
            //après avoir demandé à revenir sur un état précédent, on attend la fin de l'état actuel puis on retourne à l'historique de l'état désiré; celui-ci fini, on passe à l'état qui aurait du suivre celui pendant lequel on a demandé à revenir sur un état précédent
            QHistoryState* hState = historyValue(field);
            if(hState) { //si l'historique existe (on a déjà quitté l'état voulu)
                hState->parentState()->addTransition(hState->parentState(), SIGNAL(next()), nextState);
                previousState->addTransition(previousState, SIGNAL(next()), hState);
            }
        });
    });

}
