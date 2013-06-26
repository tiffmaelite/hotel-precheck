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
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("NUMBER"), Qt::Horizontal, QObject::tr("Numéro de chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("FLOOR"), Qt::Horizontal, QObject::tr("Étage"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("LABEL"), Qt::Horizontal, QObject::tr("Type de chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("DESCRIPTION"), Qt::Horizontal, QObject::tr("Détail"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("PRICEMIN"), Qt::Horizontal, QObject::tr("Prix minimum"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("PRICEMAX"), Qt::Horizontal, QObject::tr("Prix maximum"));
    SH_ExtendedProxyModel::sort(fields.indexOf("FLOOR"),Qt::AscendingOrder);
    SH_ExtendedProxyModel::addFilterKeyColumn(fields.indexOf("ID"));
    SH_ExtendedProxyModel::addFilterKeyColumn(fields.indexOf("PRICEMAX"));
}
/*}*/
