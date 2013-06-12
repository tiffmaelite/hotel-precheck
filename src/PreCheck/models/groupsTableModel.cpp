#include "groupsTableModel.h"

GroupsTableModel::GroupsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("rooms", filter, parent)
{

}

void GroupsTableModel::fillModel() {
}
