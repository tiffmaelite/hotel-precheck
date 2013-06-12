#include <QtSql/QSqlRelationalTableModel>
#ifndef BILLS_H
#define BILLS_H

#include "models/checkablesortfilterproxymodel.h"

class BillsTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT

public:
    BillsTableModel(QString filter = "", QObject *parent = 0);

protected:
    void fillModel();
};

#endif // BILLS_H
