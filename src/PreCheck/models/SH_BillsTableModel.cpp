#include "SH_BillsTableModel.h"


/*!
 \details

 \fn SH_BillsTableModel::BillsTableModel
*/
SH_BillsTableModel::SH_BillsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("BILLS");
}


/*!
 \details

 \fn SH_BillsTableModel::fillModel
*/
void SH_BillsTableModel::fillModel()
{
}
