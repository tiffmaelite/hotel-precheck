#include "clientsTableModel.h"

ClientsTableModel::ClientsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("rooms", filter, parent)
{

}

void ClientsTableModel::fillModel() {
}
