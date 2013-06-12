#include "servicesTableModel.h"

ServicesTableModel::ServicesTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("services", filter, parent)
{

}

void ServicesTableModel::fillModel() {
}
