#ifndef ADDRESSCREATION_H
#define ADDRESSCREATION_H
#include "SH_IOStateMachine.h"

class SH_AddressCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
/*!
 \brief
 \fn AddressCreation TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_AddressCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // ADDRESSCREATION_H
