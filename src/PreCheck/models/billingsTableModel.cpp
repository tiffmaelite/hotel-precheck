#include "billingsTableModel.h"


BillingsTableModel::BillingsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("rooms", filter, parent)
{
}

void BillingsTableModel::fillModel() {
    this->model()->setRelation(0, QSqlRelation("clients", "id", "name"));
    this->model()->setRelation(1, QSqlRelation("rooms", "id", "number"));

    this->model()->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom client"));
    this->model()->setHeaderData(1, Qt::Horizontal, QObject::tr("Chambre"));
    this->model()->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arrivée"));
    this->model()->setHeaderData(3, Qt::Horizontal, QObject::tr("Date départ prévue"));
    this->model()->setSort(2, Qt::AscendingOrder);
}
