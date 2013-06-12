#include "billsTableModel.h"

BillsTableModel::BillsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("rooms", filter, parent)
{

}

void BillsTableModel::fillModel() {
}
