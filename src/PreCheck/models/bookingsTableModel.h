#include <QtSql/QSqlRelationalTableModel>
#ifndef BOOKING_H
#define BOOKING_H

#include "models/checkablesortfilterproxymodel.h"

class BookingsTableModel : public CheckableSortFilterProxyModel
{
public:
    BookingsTableModel(QString filter="", QObject *parent=0);


protected:
    void fillModel();
};

#endif // BOOKING_H
