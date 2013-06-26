#include "SH_ServicesTableModel.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ServicesTableModel::ServicesTableModel
*/
SH_ServicesTableModel::SH_ServicesTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("SERVICESINFOS");
}


/*!
 \details \~french

 \fn SH_ServicesTableModel::fillModel
*/
void SH_ServicesTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    SH_ExtendedProxyModel::sort(fields.indexOf("SERVICETYPE"),Qt::AscendingOrder);
}
/*}*/
