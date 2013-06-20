#ifndef GENERICSTATE_H
#define GENERICSTATE_H

#include <QState>
#include "SH_NamedObject.h"

/*!
 \brief

 \class SH_GenericState genericstate.h "logic/genericstate.h"
*/
class SH_GenericState : public QState,SH_NamedObject
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn SH_GenericState
 \param name
 \param parent
*/
    SH_GenericState(QString name="", QState *parent = 0);
    /*!
     \brief

     \fn SH_toString
     \return QString
    */
    QString toString();


signals:
    /*!
     \brief

     \fn SH_next
    */
    void next();

protected:
    /*!
     \brief
     \fn SH_onEntry TODO comment this
     \param event TODO comment this
    */
    void onEntry(QEvent *event);
    /*!
     \brief
     \fn SH_onExit TODO comment this
     \param event TODO comment this
    */
    void onExit(QEvent *event);


private:

private slots:
    /*!
     \brief
     \fn SH_onMachineStarted TODO comment this
    */
    void onMachineStarted();
    /*!
     \brief
     \fn SH_onTransitionTriggered TODO comment this
    */
    void onTransitionTriggered();

};

#endif /* GENERICSTATE_H*/
