#include "clients_table_model.h"


ClientsTableModel::ClientsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("CLIENTS");
}


void ClientsTableModel::fillModel()
{
}
