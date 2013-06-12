#include <QtSql/QSqlRelationalTableModel>
#ifndef BOOKING_H
#define BOOKING_H

#include "models/checkable_sort_filter_proxy_model.h"



/*!
 \brief

 \class BookingsTableModel bookings_table_model.h "models/bookings_table_model.h"
*/
class BookingsTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn BookingsTableModel
 \param parent
*/
        BookingsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // BOOKING_H
