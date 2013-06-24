#ifndef SH_GENERICDEBUGABLESTATEMACHINE_H
#define SH_GENERICDEBUGABLESTATEMACHINE_H

#include <QStateMachine>
#include "SH_NamedObject.h"

class SH_GenericStateMachine : public QStateMachine,SH_NamedObject
{
    Q_OBJECT
public:
    SH_GenericStateMachine(QString name="",QObject *parent = 0);

    /*!
    \brief \~french
     \fn toString
     \return QString
    */
    QString toString();

    /*!
     \brief \~french
     \fn isRunning
     \return bool
    */
    bool isRunning();

    virtual void addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState);

protected slots:
    /*!
     \brief

     \fn goNext
    */
    void emitGoNext();

signals:
    /*!
    \brief \~french
     \fn next
    */
    void next();

    /*!
    \brief \~french
     \fn goNext
    */
    void goNext();

protected:
    /*!
    \brief \~french
     \fn onEntry
     \param event
    */
    void onEntry(QEvent *event);

    /*!
    \brief \~french
     \fn onExit
     \param event
    */
    void onExit(QEvent *event);

private:
    /*!
     \brief \~french
     \var m_isRunning
    */
    bool m_isRunning;

};

#endif // SH_GENERICDEBUGABLESTATEMACHINE_H
