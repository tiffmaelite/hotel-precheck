#ifndef VALIDATIONSTATE_H
#define VALIDATIONSTATE_H
#include "SH_ConfirmationState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_ValidationState validationstate.h "logic/validationstate.h"
*/
class SH_ValidationState : public SH_ConfirmationState
{
	Q_OBJECT
public:
/*!
 * \brief \~french
 * \fn ValidationState
 * \param output
 * \param name
 * \param parent
*/
	SH_ValidationState(QString output, QString name, QState *parent = 0);
signals:
public slots:
};
/*}*/
#endif /* VALIDATIONSTATE_H*/
