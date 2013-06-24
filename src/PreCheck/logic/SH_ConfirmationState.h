#ifndef CONFIRMATIONSTATE_H
#define CONFIRMATIONSTATE_H
#include "SH_StatementState.h"

/*!
\brief \~french  La class ConfirmationState représente un état dans lequel le système attend que l'utilisateur appuie sur une touche de confirmation

 \class SH_ConfirmationState confirmationstate.h "logic/confirmationstate.h"

 L'état ConfirmationState correspond à un état de quasi-déclaration où la seule entrée acceptée de l'utilisateur est une confirmation.

*/
class SH_ConfirmationState : public SH_StatementState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn ConfirmationState
 \param output
 \param name
 \param parent
*/
    SH_ConfirmationState(QString output, QString name, QState *parent = 0);



signals:

public slots:
    /*!
    \brief \~french 

     \fn confirmInput
    */
    void confirmInput();

};

#endif /* CONFIRMATIONSTATE_H*/
