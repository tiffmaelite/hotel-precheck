#include <QtSql/QSqlRelationalTableModel>
#ifndef RENT_H
#define RENT_H

#include "models/checkablesortfilterproxymodel.h"

class BillingsTableModel : public CheckableSortFilterProxyModel
{
public:
    BillingsTableModel(QString filter="", QObject *parent=0);

protected:
    void fillModel();

};

#endif // RENT_H
