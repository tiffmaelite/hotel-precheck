#include "SH_ClientsTableModel.h"

/*namespace SimplHotel
{*/
/*!
* \details \~french
* \fn SH_ClientsTableModel::ClientsTableModel
*/
SH_ClientsTableModel::SH_ClientsTableModel(QObject *parent):
SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("CLIENTS");
}


/*!
* \details \~french
* \fn SH_ClientsTableModel::fillModel
*/
void SH_ClientsTableModel::fillModel()
{
}
/*}*/
