#ifndef VALIDATIONSTATE_H
#define VALIDATIONSTATE_H
#include "confirmationstate.h"

/*!
 \brief

 \class ValidationState validationstate.h "logic/validationstate.h"
*/
class ValidationState : public ConfirmationState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn ValidationState
 \param output
 \param name
 \param parent
*/
    ValidationState(QString output, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // VALIDATIONSTATE_H
