#include "SH_ReportsTableModel.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ReportsTableModel::ServicesTableModel
*/
SH_ReportsTableModel::SH_ReportsTableModel(QObject *parent):
    SH_ExtendedProxyFuncResultModel(parent)
{
    SH_ExtendedProxyFuncResultModel::model->setFunctionCall("");
}


/*!
 \details \~french

 \fn SH_ReportsTableModel::fillModel
*/
void SH_ReportsTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    this->sort(fields.indexOf("SERVICETYPE"),Qt::AscendingOrder);
}
/*}*/
