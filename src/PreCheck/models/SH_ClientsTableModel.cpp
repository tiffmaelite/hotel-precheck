#include "SH_ClientsTableModel.h"


/*!
 \details

 \fn SH_ClientsTableModel::ClientsTableModel
*/
SH_ClientsTableModel::SH_ClientsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("CLIENTS");
}


/*!
 \details

 \fn SH_ClientsTableModel::fillModel
*/
void SH_ClientsTableModel::fillModel()
{
}
