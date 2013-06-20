#ifndef GENERICSTATE_H
#define GENERICSTATE_H

#include <QState>
#include "SH_NamedObject.h"

/*!
 \brief

 \class GenericState genericstate.h "logic/genericstate.h"
*/
class SH_GenericState : public QState,SH_NamedObject
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn GenericState
 \param name
 \param parent
*/
    SH_GenericState(QString name="", QState *parent = 0);
    /*!
     \brief

     \fn toString
     \return QString
    */
    QString toString();


signals:
    /*!
     \brief

     \fn next
    */
    void next();

protected:
    /*!
     \brief
     \fn onEntry TODO comment this
     \param event TODO comment this
    */
    void onEntry(QEvent *event);
    /*!
     \brief
     \fn onExit TODO comment this
     \param event TODO comment this
    */
    void onExit(QEvent *event);


private:

private slots:
    /*!
     \brief
     \fn onMachineStarted TODO comment this
    */
    void onMachineStarted();
    /*!
     \brief
     \fn onTransitionTriggered TODO comment this
    */
    void onTransitionTriggered();

};

#endif // GENERICSTATE_H
