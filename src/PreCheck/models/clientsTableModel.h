#include <QtSql/QSqlRelationalTableModel>
#ifndef CLIENT_H
#define CLIENT_H

#include "models/checkablesortfilterproxymodel.h"

class ClientsTableModel : public CheckableSortFilterProxyModel
{
public:
    ClientsTableModel(QString filter="", QObject *parent=0);


protected:
    void fillModel();
};

#endif // CLIENT_H
