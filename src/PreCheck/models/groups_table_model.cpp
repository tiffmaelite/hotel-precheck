#include "groups_table_model.h"


GroupsTableModel::GroupsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("GROUPS");
}

void GroupsTableModel::fillModel()
{
}
