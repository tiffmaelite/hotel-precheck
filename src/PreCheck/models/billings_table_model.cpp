#include "billings_table_model.h"



BillingsTableModel::BillingsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("BILLINGSINFOS");
}


void BillingsTableModel::fillModel()
{
    CheckableSortFilterProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
    CheckableSortFilterProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Chambre"));
    CheckableSortFilterProxyModel::model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date arrivée"));
    CheckableSortFilterProxyModel::model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date départ prévue"));
    CheckableSortFilterProxyModel::model->field(4)->setSortOrder(Qt::AscendingOrder);
}
