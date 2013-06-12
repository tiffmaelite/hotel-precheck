#include "bills_table_model.h"


/*!
 \brief

 \fn BillsTableModel::BillsTableModel
 \param parent
*/
BillsTableModel::BillsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("BILLS");
}


/*!
 \brief

 \fn BillsTableModel::fillModel
*/
void BillsTableModel::fillModel()
{
}
