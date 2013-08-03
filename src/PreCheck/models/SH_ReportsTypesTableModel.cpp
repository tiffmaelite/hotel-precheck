#include "SH_ReportsTypesTableModel.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ReportsTypesTableModel::ServicesTableModel
*/
SH_ReportsTypesTableModel::SH_ReportsTypesTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("REPORTSTYPES");
}


/*!
 \details \~french

 \fn SH_ReportsTypesTableModel::fillModel
*/
void SH_ReportsTypesTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyTableModel::model->fieldsList();
    this->sort(fields.indexOf("LABEL"),Qt::AscendingOrder);
}
/*}*/
