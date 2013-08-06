#include "SH_BillingsTableModel.h"


/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_BillingsTableModel::BillingsTableModel
*/
SH_BillingsTableModel::SH_BillingsTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("BILLINGSINFOS");
}


/*!
 * \details \~french
 * \fn SH_BillingsTableModel::fillModel
*/
void SH_BillingsTableModel::fillModel()
{
    this->setHeaderData(this->fieldIndex("NAME"), Qt::Horizontal, QObject::tr("Nom client"));
    this->setHeaderData(this->fieldIndex("ROOM"), Qt::Horizontal, QObject::tr("Chambre"));
    this->setHeaderData(this->fieldIndex("ARRIVINGDATE"), Qt::Horizontal, QObject::tr("Date arrivée"));
    this->setHeaderData(this->fieldIndex("EXPECTEDDEPARTUREDATE"), Qt::Horizontal, QObject::tr("Date départ prévue"));
    this->sort(this->fieldIndex("ARRIVINGDATE"),Qt::AscendingOrder);
}
/*}*/
