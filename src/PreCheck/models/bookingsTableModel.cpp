#include "bookingsTableModel.h"

BookingsTableModel::BookingsTableModel(QString filter, QObject *parent):
    CheckableSortFilterProxyModel("bookings", "confirmed=false", parent)
{

}

void BookingsTableModel::fillModel() {
}
