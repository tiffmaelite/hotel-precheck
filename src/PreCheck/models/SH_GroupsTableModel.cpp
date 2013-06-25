#include "SH_GroupsTableModel.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_GroupsTableModel::GroupsTableModel
*/
SH_GroupsTableModel::SH_GroupsTableModel(QObject *parent):
	SH_ExtendedProxyModel(parent)
{
	SH_ExtendedProxyModel::model->setTable("GROUPS");
}

/*!
 \details \~french

 \fn SH_GroupsTableModel::fillModel
*/
void SH_GroupsTableModel::fillModel()
{
}
/*}*/
