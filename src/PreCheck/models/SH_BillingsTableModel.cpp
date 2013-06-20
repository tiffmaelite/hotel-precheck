#include "SH_BillingsTableModel.h"



/*!
 \details

 \fn SH_BillingsTableModel::BillingsTableModel
*/
SH_BillingsTableModel::SH_BillingsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("BILLINGSINFOS");
}


/*!
 \details

 \fn SH_BillingsTableModel::fillModel
*/
void SH_BillingsTableModel::fillModel()
{
    SH_ExtendedProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
    SH_ExtendedProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date arrivée"));
    SH_ExtendedProxyModel::model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date départ prévue"));
    SH_ExtendedProxyModel::model->field(4)->setSortOrder(Qt::AscendingOrder);
}
