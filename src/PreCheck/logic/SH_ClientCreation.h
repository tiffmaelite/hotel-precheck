#ifndef CLIENTCREATION_H
#define CLIENTCREATION_H
#include "SH_IOStateMachine.h"

class SH_ClientCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
/*!
 \brief
 \fn ClientCreationStateMachine TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_ClientCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // CLIENTCREATION_H
