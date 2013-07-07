#include "SH_BillingsTableModel.h"


/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_BillingsTableModel::BillingsTableModel
*/
SH_BillingsTableModel::SH_BillingsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTableName("BILLINGSINFOS");
}


/*!
 * \details \~french
 * \fn SH_BillingsTableModel::fillModel
*/
void SH_BillingsTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("NAME"), Qt::Horizontal, QObject::tr("Nom client"));
    this->setHeaderData(fields.indexOf("ROOM"), Qt::Horizontal, QObject::tr("Chambre"));
    this->setHeaderData(fields.indexOf("ARRIVINGDATE"), Qt::Horizontal, QObject::tr("Date arrivée"));
    this->setHeaderData(fields.indexOf("EXPECTEDDEPARTUREDATE"), Qt::Horizontal, QObject::tr("Date départ prévue"));
    this->sort(fields.indexOf("ARRIVINGDATE"),Qt::AscendingOrder);
}
/*}*/
