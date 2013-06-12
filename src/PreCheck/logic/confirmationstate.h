#ifndef CONFIRMATIONSTATE_H
#define CONFIRMATIONSTATE_H
#include "statementstate.h"

/*!
 \brief La class ConfirmationState représente un état dans lequel le système attend que l'utilisateur appuie sur une touche de confirmation

 \class ConfirmationState confirmationstate.h "logic/confirmationstate.h"

 L'état ConfirmationState correspond à un état de quasi-déclaration où la seule entrée acceptée de l'utilisateur est une confirmation.

*/
class ConfirmationState : public StatementState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn ConfirmationState
 \param output
 \param name
 \param parent
*/
    ConfirmationState(QString output, QString name, QState *parent = 0);



signals:

public slots:
    /*!
     \brief

     \fn confirmInput
    */
    void confirmInput();

};

#endif // CONFIRMATIONSTATE_H
