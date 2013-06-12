#include "clients_table_model.h"


/*!
 \brief

 \fn ClientsTableModel::ClientsTableModel
 \param parent
*/
ClientsTableModel::ClientsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("CLIENTS");
}


/*!
 \brief

 \fn ClientsTableModel::fillModel
*/
void ClientsTableModel::fillModel()
{
}
