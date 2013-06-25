#include "SH_BookingsTableModel.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_BookingsTableModel::BookingsTableModel
*/
SH_BookingsTableModel::SH_BookingsTableModel(QObject *parent):
	SH_ExtendedProxyModel(parent)
{
	SH_ExtendedProxyModel::model->setTable("BOOKINGS");
	SH_ExtendedProxyModel::model->setFilterCondition(QObject::tr("ISCONFIRMED") + "='1'");
}


/*!
 * \details \~french
 * \fn SH_BookingsTableModel::fillModel
*/
void SH_BookingsTableModel::fillModel()
{
	SH_ExtendedProxyModel::model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date réservation"));
	SH_ExtendedProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
	SH_ExtendedProxyModel::model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arrivée prévue"));
	SH_ExtendedProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nb Personnes"));

	SH_ExtendedProxyModel::model->field(0)->setSortOrder(Qt::AscendingOrder);
}
/*}*/
