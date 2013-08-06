#include "SH_ServicesTableModel.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_ServicesTableModel::ServicesTableModel
*/
SH_ServicesTableModel::SH_ServicesTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("SERVICESINFOS");
    SH_ExtendedProxyTableModel::model->setOrderBy("SERVICEFAMILY_ID ASC, SERVICETYPE_ID ASC, SERVICECODE ASC");
}


/*!
 \details \~french

 \fn SH_ServicesTableModel::fillModel
*/
void SH_ServicesTableModel::fillModel()
{
   SH_ExtendedProxyTableModel::setHeaderData(this->fieldIndex("SERVICEFULLCODE"), Qt::Horizontal, QObject::tr("Code"));

    this->setHeaderData(this->fieldIndex("SERVICENAME"), Qt::Horizontal, QObject::tr("Nom"));
    this->setHeaderData(this->fieldIndex("SERVICETYPE"), Qt::Horizontal, QObject::tr("Type"));
    this->setHeaderData(this->fieldIndex("SERVICEFAMILY"), Qt::Horizontal, QObject::tr("Famille"));
    this->setHeaderData(this->fieldIndex("ISAVAILABLE"), Qt::Horizontal, QObject::tr("Disponible"));
    this->setHeaderData(this->fieldIndex("_PRICEMIN"), Qt::Horizontal, QObject::tr("Prix minimal suggéré"));
    this->setHeaderData(this->fieldIndex("_PRICEMAX"), Qt::Horizontal, QObject::tr("Prix maximal suggéré"));
    this->setHeaderData(this->fieldIndex("VAT"), Qt::Horizontal, QObject::tr("TVA"));
    this->setHeaderData(this->fieldIndex("TYPENEEDSROOM"), Qt::Horizontal, QObject::tr("Chambre nécessaire"));
    this->sort(this->fieldIndex("SERVICETYPE"),Qt::AscendingOrder);
}
/*}*/
