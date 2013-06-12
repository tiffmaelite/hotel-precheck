#include "offers_table_model.h"


OffersTableModel::OffersTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("BOOKINGS");
    CheckableSortFilterProxyModel::model->setFilterCondition(QObject::tr("ISCONFIRMED") + "='0'");
}


void OffersTableModel::fillModel()
{
}
