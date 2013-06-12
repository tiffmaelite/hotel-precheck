#ifndef VALIDATIONSTATE_H
#define VALIDATIONSTATE_H
#include "confirmationstate.h"

class ValidationState : public ConfirmationState
{
    Q_OBJECT
public:
    ValidationState(QString output, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // VALIDATIONSTATE_H
