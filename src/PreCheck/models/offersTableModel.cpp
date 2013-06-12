#include "offersTableModel.h"

OffersTableModel::OffersTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("bookings", filter+"confirmed=false", parent)
{

}

void OffersTableModel::fillModel() {
}
