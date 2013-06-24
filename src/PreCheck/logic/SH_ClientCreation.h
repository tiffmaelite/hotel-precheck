#ifndef CLIENTCREATION_H
#define CLIENTCREATION_H
#include "SH_IOStateMachine.h"

/*!
 *\brief \~french  The SH_ClientCreationStateMachine class
 */
class SH_ClientCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
/*!
\brief \~french 
 \fn ClientCreationStateMachine 
 \param name 
 \param parent 
*/
    SH_ClientCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif /* CLIENTCREATION_H*/
