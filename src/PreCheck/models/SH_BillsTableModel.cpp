#include "SH_BillsTableModel.h"

/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_BillsTableModel::BillsTableModel
*/
SH_BillsTableModel::SH_BillsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTableName("BILLS");
}


/*!
 * \details \~french
 * \fn SH_BillsTableModel::fillModel
*/
void SH_BillsTableModel::fillModel()
{
}
/*}*/
