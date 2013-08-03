#include "SH_ExtendedProxyTableModel.h"

SH_ExtendedProxyTableModel::SH_ExtendedProxyTableModel(QObject *parent) :
    SH_ExtendedProxyModel(parent)
{
    this->model = new SH_SqlDataModel(parent);
    this->setSourceModel(this->model);
}
