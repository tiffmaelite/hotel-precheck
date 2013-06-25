#include "SH_VATTableModel.h"
#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_VATTableModel::VATTableModel
*/
SH_VATTableModel::SH_VATTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("TAXES");
    SH_ExtendedProxyModel::model->setFilterCondition("STARTDATE <= CURRENT_DATE && (ENDDATE IS NULL || ENDDATE >= CURRENT_DATE)");
    SH_ExtendedProxyModel::model->setOrderBy("PERCENTAGE ASC");
}

/*!
 \details \~french

 \fn SH_VATTableModel::fillModel
*/
void SH_VATTableModel::fillModel()
{
    SH_ExtendedProxyModel::addFilterKeyColumn(0);
    //SH_ExtendedProxyModel::addFilterKeyColumn(2);
    SH_ExtendedProxyModel::addFilterKeyColumn(3);
    SH_ExtendedProxyModel::addFilterKeyColumn(4);
}
/*}*/
