#include "SH_RoomsTableModel.h"
#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_RoomsTableModel::RoomsTableModel
*/
SH_RoomsTableModel::SH_RoomsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("ROOMSINFOS");
    SH_ExtendedProxyModel::model->setOrderBy("FLOOR ASC, NUMBER ASC");
}

/*!
 \details \~french

 \fn SH_RoomsTableModel::fillModel
*/
void SH_RoomsTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(fields.indexOf("NUMBER"), Qt::Horizontal, QObject::tr("Numéro de chambre"));
    this->setHeaderData(fields.indexOf("FLOOR"), Qt::Horizontal, QObject::tr("Étage"));
    this->setHeaderData(fields.indexOf("LABEL"), Qt::Horizontal, QObject::tr("Type de chambre"));
    this->setHeaderData(fields.indexOf("DESCRIPTION"), Qt::Horizontal, QObject::tr("Détail"));
    this->setHeaderData(fields.indexOf("PRICEMIN"), Qt::Horizontal, QObject::tr("Prix minimum"));
    this->setHeaderData(fields.indexOf("PRICEMAX"), Qt::Horizontal, QObject::tr("Prix maximum"));
    this->sort(fields.indexOf("FLOOR"),Qt::AscendingOrder);
    this->addHiddenColumn(fields.indexOf("ID"));
    this->addHiddenColumn(fields.indexOf("PRICEMAX"));
}
/*}*/
