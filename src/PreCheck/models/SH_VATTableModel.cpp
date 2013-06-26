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
    SH_ExtendedProxyModel::model->setFilterCondition("((STARTDATE IS NULL OR STARTDATE <= CURRENT_DATE) AND (ENDDATE IS NULL OR ENDDATE >= CURRENT_DATE))");
    SH_ExtendedProxyModel::model->setOrderBy("PERCENTAGE ASC");
}

/*!
 \details \~french

 \fn SH_VATTableModel::fillModel
*/
void SH_VATTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("Code"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("PERCENTAGE"), Qt::Horizontal, QObject::tr("\%"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("LABEL"), Qt::Horizontal, QObject::tr("Libellé"));
    SH_ExtendedProxyModel::addFilterKeyColumn(fields.indexOf("PERCENTAGE"));
}
/*}*/
