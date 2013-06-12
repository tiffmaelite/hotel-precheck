#include "services_table_model.h"


ServicesTableModel::ServicesTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("SERVICES");
}


void ServicesTableModel::fillModel()
{
    CheckableSortFilterProxyModel::sort(1,Qt::AscendingOrder);
}
