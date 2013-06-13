#include "iostatemachine.h"
#include "validationstate.h"
#include "confirmationstate.h"
#include "datequestionstate.h"
#include "adaptdatabase.h"

/*!
 \brief

 \fn IOStateMachine::IOStateMachine
 \param tableName
 \param name
 \param parent
*/
IOStateMachine::IOStateMachine(QString tableName, QString name, QObject *parent) :
    QStateMachine(parent), NamedObject(name), m_tableName(tableName)
{
}

/*!
 \brief

 \fn IOStateMachine::toString
 \return QString
*/
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

/*!
 \brief

 \fn IOStateMachine::ioContent
 \return QVariantMap
*/
QVariantMap IOStateMachine::ioContent() const
{
    return m_ioContent;
}

/*!
 \brief

 \fn IOStateMachine::setIOcontent
 \param ioContent
*/
void IOStateMachine::setIOcontent(const QVariantMap &ioContent)
{
    m_ioContent = ioContent;
}

/*!
 \brief

 \fn IOStateMachine::getContentValue
 \param field
 \return QVariant
*/
QVariant IOStateMachine::getContentValue(QString field)
{
    return m_ioContent.value(field);
}

/*!
 \brief

 \fn IOStateMachine::tableName
 \return QString
*/
QString IOStateMachine::tableName() const
{
    return m_tableName;
}

/*!
 \brief

 \fn IOStateMachine::setTableName
 \param tableName
*/
void IOStateMachine::setTableName(const QString &tableName)
{
    m_tableName = tableName;
}


/*!
 \brief

 \fn IOStateMachine::setContentValue
 \param content
 \param field
*/
void IOStateMachine::setContentValue(QVariant content, QString field)
{
    m_ioContent.insert(field, content);
}

/*!
 \brief

 \fn IOStateMachine::addIOState
 \param state
 \param field
*/
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
            setContentValue(state->rawInput(), field);
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

/*!
 \brief

 \fn IOStateMachine::addIOStateMachine
 \param fsm
*/
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


/*!
 \brief

 \fn IOStateMachine::ioStatesHistory
 \return QMap<QString, QHistoryState *>
*/
QMap<QString, QHistoryState *> IOStateMachine::ioStatesHistory() const
{
    return m_ioStatesHistory;
}


/*!
 \brief

 \fn IOStateMachine::setIOStatesHistory
 \param QMap<QString
 \param ioStatesHistory
*/
void IOStateMachine::setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory)
{
    m_ioStatesHistory = ioStatesHistory;
}


/*!
 \brief

 \fn IOStateMachine::setIOStateHistory
 \param state
 \param field
*/
void IOStateMachine::setIOStateHistory(QHistoryState *state, QString field)
{
    m_ioStatesHistory.insert(field, state); //remplacement si plusieurs fois
}


/*!
 \brief

 \fn IOStateMachine::historyValue
 \param field
 \return QHistoryState
*/
QHistoryState *IOStateMachine::historyValue(QString field)
{
    return m_ioStatesHistory.value(field);
}


/*!
 \brief

 \fn IOStateMachine::addChildrenNextTransition
 \param previousState
 \param nextState
*/
void IOStateMachine::addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState)
{
    IOStateMachine* fsmPreviousState = qobject_cast<IOStateMachine*>(previousState);
    GenericState* genPreviousState = qobject_cast<GenericState*>(previousState);
    QFinalState* final = qobject_cast<QFinalState*>(nextState);
    if(final) {
        adaptDatabase* saveState = new adaptDatabase("enregistrement de la machine "+toString());
        if(genPreviousState) {
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), saveState);
        }
        if(fsmPreviousState) {
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), saveState);
        }
        if(genPreviousState || fsmPreviousState) {
            connect(previousState, &QAbstractState::exited, [=]() {
                connect(saveState, &QAbstractState::entered, [=]() {
                    setContentValue(saveState->insertUpdate(m_tableName, m_ioContent), "ID");
                });
            });
            saveState->addTransition(saveState, SIGNAL(next()),final);
        }
    } else {
        if(genPreviousState) {
            genPreviousState->addTransition(genPreviousState, SIGNAL(next()), nextState);
        }
        if(fsmPreviousState) {
            fsmPreviousState->addTransition(fsmPreviousState, SIGNAL(next()), nextState);
        }
    }
    if(genPreviousState) {
        //à faire au moment de l'entrée dans l'état previousState
        connect(genPreviousState, &QAbstractState::entered, [=]() {
            connect(this, &IOStateMachine::replaceInput, [=](QString field) {
                //après avoir demandé à revenir sur un état précédent, on attend la fin de l'état actuel puis on retourne à l'historique de l'état désiré; celui-ci fini, on passe à l'état qui aurait du suivre celui pendant lequel on a demandé à revenir sur un état précédent
                QHistoryState* hState = historyValue(field);
                if(hState) { //si l'historique existe (on a déjà quitté l'état voulu)
                    hState->parentState()->addTransition(hState->parentState(), SIGNAL(next()), nextState);
                    genPreviousState->addTransition(genPreviousState, SIGNAL(next()), hState);
                }
            });
        });
    }
}
