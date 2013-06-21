#ifndef ADDRESSCREATION_H
#define ADDRESSCREATION_H
#include "SH_IOStateMachine.h"
/*!
 *\brief \~french  The SH_AddressCreationStateMachine class
 */
class SH_AddressCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
/*!
\brief \~french 
 \fn SH_AddressCreation TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_AddressCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif /* ADDRESSCREATION_H*/
