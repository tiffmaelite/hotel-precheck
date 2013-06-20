#include "SH_GroupsTableModel.h"


/*!
 \brief

 \fn GroupsTableModel::GroupsTableModel
 \param parent
*/
SH_GroupsTableModel::SH_GroupsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("GROUPS");
}

/*!
 \brief

 \fn GroupsTableModel::fillModel
*/
void SH_GroupsTableModel::fillModel()
{
}
