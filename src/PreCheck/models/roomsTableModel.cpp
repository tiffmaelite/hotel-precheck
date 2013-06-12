#include "roomsTableModel.h"
#include "databaseManager.h"

RoomsTableModel::RoomsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("rooms", filter, parent)
{
}

void RoomsTableModel::fillModel() {
    this->model()->setRelation(2, QSqlRelation("roomsType", "id", "label"));

    this->model()->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    this->model()->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro Chambre"));
    this->model()->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    this->model()->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de couchages"));
    this->model()->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix 1"));
    this->model()->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix 2"));

    this->model()->setSort(2, Qt::AscendingOrder);
}
