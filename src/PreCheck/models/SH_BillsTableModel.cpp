#include "SH_BillsTableModel.h"


/*!
 \brief

 \fn BillsTableModel::BillsTableModel
 \param parent
*/
SH_BillsTableModel::SH_BillsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("BILLS");
}


/*!
 \brief

 \fn BillsTableModel::fillModel
*/
void SH_BillsTableModel::fillModel()
{
}
