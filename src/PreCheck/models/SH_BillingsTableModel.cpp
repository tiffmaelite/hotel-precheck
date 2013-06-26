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
    SH_ExtendedProxyModel::model->setTable("BILLINGSINFOS");
}


/*!
 * \details \~french
 * \fn SH_BillingsTableModel::fillModel
*/
void SH_BillingsTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("NAME"), Qt::Horizontal, QObject::tr("Nom client"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ROOM"), Qt::Horizontal, QObject::tr("Chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ARRIVINGDATE"), Qt::Horizontal, QObject::tr("Date arrivée"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("EXPECTEDDEPARTUREDATE"), Qt::Horizontal, QObject::tr("Date départ prévue"));
    SH_ExtendedProxyModel::model->field(4)->setSortOrder(Qt::AscendingOrder);
}
/*}*/
