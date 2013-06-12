#include <QtSql/QSqlRelationalTableModel>
#ifndef SERVICE_H
#define SERVICE_H

#include "models/checkablesortfilterproxymodel.h"

class ServicesTableModel : public CheckableSortFilterProxyModel
{
public:
    ServicesTableModel(QString filter="", QObject *parent=0);


protected:
    void fillModel();
};

#endif // SERVICE_H
