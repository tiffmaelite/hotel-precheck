#include "bills_table_model.h"


BillsTableModel::BillsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("BILLS");
}


void BillsTableModel::fillModel()
{
}
