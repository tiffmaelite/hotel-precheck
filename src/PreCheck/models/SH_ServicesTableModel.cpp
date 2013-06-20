#include "SH_ServicesTableModel.h"


/*!
 \brief

 \fn ServicesTableModel::ServicesTableModel
 \param parent
*/
SH_ServicesTableModel::SH_ServicesTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("SERVICESINFOS");
}


/*!
 \brief

 \fn ServicesTableModel::fillModel
*/
void SH_ServicesTableModel::fillModel()
{
    SH_ExtendedProxyModel::sort(1,Qt::AscendingOrder);
}
