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
    SH_ExtendedProxyModel::model->setTableName("BOOKINGS");
    SH_ExtendedProxyModel::model->setFilterCondition(QObject::tr("ISCONFIRMED") + "='1'");
}


/*!
 * \details \~french
 * \fn SH_BookingsTableModel::fillModel
*/
void SH_BookingsTableModel::fillModel()
{
    /*this->setHeaderData(0, Qt::Horizontal, QObject::tr("Date réservation"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arrivée prévue"));
    this->setHeaderData(3, Qt::Horizontal, QObject::tr("Nb Personnes"));

    this->sort(fields.indexOf("BOOKINGDATE"),Qt::AscendingOrder);*/
}
/*}*/
