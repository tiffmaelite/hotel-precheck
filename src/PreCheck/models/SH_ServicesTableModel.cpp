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
    QStringList fields = SH_ExtendedProxyTableModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("SERVICEFULLCODE"), Qt::Horizontal, QObject::tr("Code"));
    this->setHeaderData(fields.indexOf("SERVICENAME"), Qt::Horizontal, QObject::tr("Nom"));
    this->setHeaderData(fields.indexOf("SERVICETYPE"), Qt::Horizontal, QObject::tr("Type"));
    this->setHeaderData(fields.indexOf("SERVICEFAMILY"), Qt::Horizontal, QObject::tr("Famille"));
    this->setHeaderData(fields.indexOf("ISAVAILABLE"), Qt::Horizontal, QObject::tr("Disponible"));
    this->setHeaderData(fields.indexOf("_PRICEMIN"), Qt::Horizontal, QObject::tr("Prix minimal suggéré"));
    this->setHeaderData(fields.indexOf("_PRICEMAX"), Qt::Horizontal, QObject::tr("Prix maximal suggéré"));
    this->setHeaderData(fields.indexOf("VAT"), Qt::Horizontal, QObject::tr("TVA"));
    this->setHeaderData(fields.indexOf("TYPENEEDSROOM"), Qt::Horizontal, QObject::tr("Chambre nécessaire"));
    this->sort(fields.indexOf("SERVICETYPE"),Qt::AscendingOrder);
}
/*}*/
