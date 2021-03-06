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
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("ROOMSINFOS");
    SH_ExtendedProxyTableModel::model->setOrderBy("NUMBER ASC");
    this->fetch();
}

/*!
 \details \~french

 \fn SH_RoomsTableModel::fillModel
*/
void SH_RoomsTableModel::fillModel()
{
    this->addHiddenColumn(this->fieldIndex("PRICEMAX"));
    this->setHeaderData(this->fieldIndex("ID"), Qt::Horizontal, QObject::tr("Identifiant"));
    this->setHeaderData(this->fieldIndex("NUMBER"), Qt::Horizontal, QObject::tr("Numéro de chambre"));
    this->setHeaderData(this->fieldIndex("FLOOR"), Qt::Horizontal, QObject::tr("Étage"));
    this->setHeaderData(this->fieldIndex("TYPE"), Qt::Horizontal, QObject::tr("Type de chambre"));
    this->setHeaderData(this->fieldIndex("ISCLEANED"), Qt::Horizontal, QObject::tr("Nettoyée"));
    this->setHeaderData(this->fieldIndex("ISAVAILABLE"), Qt::Horizontal, QObject::tr("Libre"));
    this->setHeaderData(this->fieldIndex("DESCRIPTION"), Qt::Horizontal, QObject::tr("Détail"));
    this->setHeaderData(this->fieldIndex("PRICEMIN"), Qt::Horizontal, QObject::tr("Prix minimum"));
    this->setHeaderData(this->fieldIndex("PRICEMAX"), Qt::Horizontal, QObject::tr("Prix maximum"));
    QList<int> boolCols;
    boolCols.append(this->fieldIndex("ISCLEANED"));
    boolCols.append(this->fieldIndex("ISAVAILABLE"));
    this->setBooleanColumns(boolCols);
    this->sort(this->fieldIndex("FLOOR"),Qt::AscendingOrder);
}
/*}*/
