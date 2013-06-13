#ifndef ADDRESSCREATION_H
#define ADDRESSCREATION_H
#include "iostatemachine.h"

class AddressCreation : public IOStateMachine
{
    Q_OBJECT
public:
/*!
 \brief
 \fn AddressCreation TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    AddressCreation(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif // ADDRESSCREATION_H
