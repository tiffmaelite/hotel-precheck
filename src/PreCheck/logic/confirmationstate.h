#ifndef CONFIRMATIONSTATE_H
#define CONFIRMATIONSTATE_H
#include "statementstate.h"

class ConfirmationState : public StatementState
{
    Q_OBJECT
public:
    ConfirmationState(QString output, QString name, QState *parent = 0);



signals:

public slots:
    void confirmInput();

};

#endif // CONFIRMATIONSTATE_H
