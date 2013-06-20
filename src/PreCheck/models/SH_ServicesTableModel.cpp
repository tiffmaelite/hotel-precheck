#include "SH_ServicesTableModel.h"


/*!
 \details

 \fn SH_ServicesTableModel::ServicesTableModel
*/
SH_ServicesTableModel::SH_ServicesTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("SERVICESINFOS");
}


/*!
 \details

 \fn SH_ServicesTableModel::fillModel
*/
void SH_ServicesTableModel::fillModel()
{
    SH_ExtendedProxyModel::sort(1,Qt::AscendingOrder);
}
