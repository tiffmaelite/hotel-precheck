#include <QtSql/QSqlRelationalTableModel>

#ifndef GROUP_H
#define GROUP_H

#include "models/checkablesortfilterproxymodel.h"

class GroupsTableModel : public CheckableSortFilterProxyModel
{
public:
    GroupsTableModel(QString filter="", QObject *parent=0);


protected:
    void fillModel();
};

#endif // GROUP_H
