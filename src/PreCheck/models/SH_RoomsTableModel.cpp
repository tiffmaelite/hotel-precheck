#include "SH_RoomsTableModel.h"
#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"

/*!
 \brief

 \fn RoomsTableModel::RoomsTableModel
 \param parent
*/
SH_RoomsTableModel::SH_RoomsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("ROOMSINFOS");
    SH_ExtendedProxyModel::model->setOrderBy("FLOOR ASC, NUMBER ASC");
}

/*!
 \brief

 \fn RoomsTableModel::fillModel
*/
void SH_RoomsTableModel::fillModel()
{
    SH_ExtendedProxyModel::model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    SH_ExtendedProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro de chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(2, Qt::Horizontal, QObject::tr("Étage"));
    SH_ExtendedProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de chambre"));
    SH_ExtendedProxyModel::model->setHeaderData(4, Qt::Horizontal, QObject::tr("Détail"));
    SH_ExtendedProxyModel::model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix minimum"));
    SH_ExtendedProxyModel::model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix maximum"));
    SH_ExtendedProxyModel::sort(2,Qt::AscendingOrder);
    SH_ExtendedProxyModel::addFilterKeyColumn(0);
    SH_ExtendedProxyModel::addFilterKeyColumn(7);
}
