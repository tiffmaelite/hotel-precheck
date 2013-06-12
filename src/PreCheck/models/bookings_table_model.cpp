#include "bookings_table_model.h"


BookingsTableModel::BookingsTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("BOOKINGS");
    CheckableSortFilterProxyModel::model->setFilterCondition(QObject::tr("ISCONFIRMED") + "='1'");
}


void BookingsTableModel::fillModel()
{
    CheckableSortFilterProxyModel::model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date réservation"));
    CheckableSortFilterProxyModel::model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
    CheckableSortFilterProxyModel::model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arrivée prévue"));
    CheckableSortFilterProxyModel::model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nb Personnes"));

    CheckableSortFilterProxyModel::model->field(0)->setSortOrder(Qt::AscendingOrder);
}
