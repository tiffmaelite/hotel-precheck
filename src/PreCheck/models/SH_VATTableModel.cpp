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
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("TAXES");
    SH_ExtendedProxyTableModel::model->setFilterCondition("((STARTDATE IS NULL OR STARTDATE <= CURRENT_DATE) AND (ENDDATE IS NULL OR ENDDATE >= CURRENT_DATE))");
    SH_ExtendedProxyTableModel::model->setOrderBy("PERCENTAGE ASC");
}

/*!
 \details \~french

 \fn SH_VATTableModel::fillModel
*/
void SH_VATTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyTableModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("Code"));
    //this->setHeaderData(fields.indexOf("PERCENTAGE"), Qt::Horizontal, QObject::tr("%"));
    this->setHeaderData(fields.indexOf("LABEL"), Qt::Horizontal, QObject::tr("Libellé"));
    this->sort(fields.indexOf("PERCENTAGE"),Qt::AscendingOrder);
    this->addHiddenColumn(fields.indexOf("ID"));
}
/*}*/
