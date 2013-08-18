#include "SH_BillsTableModel.h"

/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_BillsTableModel::BillsTableModel
*/
SH_BillsTableModel::SH_BillsTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("BILLS");
    this->fetch();
}


/*!
 * \details \~french
 * \fn SH_BillsTableModel::fillModel
*/
void SH_BillsTableModel::fillModel()
{
}
/*}*/
