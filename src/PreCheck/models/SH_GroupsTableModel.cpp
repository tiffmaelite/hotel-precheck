#include "SH_GroupsTableModel.h"


/*!
 \details

 \fn SH_GroupsTableModel::GroupsTableModel
*/
SH_GroupsTableModel::SH_GroupsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("GROUPS");
}

/*!
 \details

 \fn SH_GroupsTableModel::fillModel
*/
void SH_GroupsTableModel::fillModel()
{
}
