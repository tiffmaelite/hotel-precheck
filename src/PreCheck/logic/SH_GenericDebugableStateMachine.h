#ifndef SH_GENERICDEBUGABLESTATEMACHINE_H
#define SH_GENERICDEBUGABLESTATEMACHINE_H
#include <QStateMachine>
#include "SH_NamedObject.h"
/*namespace SimplHotel
{*/class SH_GenericStateMachine : public QStateMachine,SH_NamedObject
{
    Q_OBJECT
public:
    SH_GenericStateMachine(QString name="",QObject *parent = 0);

/*!
    * \brief \~french
    * \fn toString
    * \return QString
    */
    QString toString();

/*!
    * \brief
    * \fn addChildrenNextTransition
    * \param previousState
    * \param nextState
    */
    virtual void setStatesNextTransition(QAbstractState *previousState, QAbstractState *nextState);

    virtual void addState(QAbstractState *state);

protected slots:

/*!
    * \brief
    * \fn goNext
    */
    void emitGoNext();
signals:

/*!
    * \brief \~french
    * \fn next
    */
    void next();

/*!
    * \brief \~french
    * \fn goNext
    */
    void goNext();
protected:

/*!
    * \brief \~french
    * \fn onEntry
    * \param event
    */
    void onEntry(QEvent *event);

/*!
    * \brief \~french
    * \fn onExit
    * \param event
    */
    void onExit(QEvent *event);
private:

/*!
    * \brief \~french
    * \var m_errorState
    */
    QState* m_errorState;
    QAbstractState* m_currentState;
};
/*}*/
#endif // SH_GENERICDEBUGABLESTATEMACHINE_H
