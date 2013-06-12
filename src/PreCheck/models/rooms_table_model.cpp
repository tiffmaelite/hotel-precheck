#include "rooms_table_model.h"
#include "database_manager.h"
#include "views/message_manager.h"

RoomsTableModel::RoomsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("ROOMSINFOS");
    CheckableSortFilterProxyModel::model->setOrderBy("FLOOR ASC, NUMBER ASC");
}

void RoomsTableModel::fillModel()
{
    CheckableSortFilterProxyModel::model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    CheckableSortFilterProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro de chambre"));
    CheckableSortFilterProxyModel::model->setHeaderData(2, Qt::Horizontal, QObject::tr("Étage"));
    CheckableSortFilterProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de chambre"));
    CheckableSortFilterProxyModel::model->setHeaderData(4, Qt::Horizontal, QObject::tr("Détail"));
    CheckableSortFilterProxyModel::model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix minimum"));
    CheckableSortFilterProxyModel::model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix maximum"));
    CheckableSortFilterProxyModel::sort(2,Qt::AscendingOrder);
    CheckableSortFilterProxyModel::addFilterKeyColumn(0);
    CheckableSortFilterProxyModel::addFilterKeyColumn(7);
}
