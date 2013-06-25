#ifndef ADDRESSCREATION_H
#define ADDRESSCREATION_H
#include "SH_IOStateMachine.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french La classe SH_AddressCreationStateMachine fournit une machine d'états finis permettant la création d'un entité "adresse" à enregistrer dans la base de données
 * * \class SH_AddressCreationStateMachine
 * * \headerfile SH_AddressCreationStateMachine.sh "logic/SH_AddressCreationStateMachine.h"
 */
class SH_AddressCreationStateMachine : public SH_InOutStateMachine
{
	Q_OBJECT
public:
/*!
 * \brief \~french Construit une instance de la classe SH_AddressCreationStateMachine
 * \fn AddressCreationStateMachine
 * \param name Le nom de la macheine d'états finis
 * \param parent L'objet auquel appartient cette machine
*/
	SH_AddressCreationStateMachine(QString name, QObject *parent = 0);
signals:
public slots:
};
/*}*/
#endif /* ADDRESSCREATION_H*/
