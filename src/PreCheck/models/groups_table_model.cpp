#include "groups_table_model.h"


/*!
 \brief

 \fn GroupsTableModel::GroupsTableModel
 \param parent
*/
GroupsTableModel::GroupsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("GROUPS");
}

/*!
 \brief

 \fn GroupsTableModel::fillModel
*/
void GroupsTableModel::fillModel()
{
}
