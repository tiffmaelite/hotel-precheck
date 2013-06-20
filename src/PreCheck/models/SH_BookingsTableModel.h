#include <QtSql/QSqlRelationalTableModel>
#ifndef BOOKING_H
#define BOOKING_H

#include "SH_ExtendedSqlProxyModel.h"



/*!
 \brief

 \class SH_BookingsTableModel bookings_table_model.h "models/bookings_table_model.h"
*/
class SH_BookingsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn SH_BookingsTableModel
 \param parent
*/
        SH_BookingsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn SH_fillModel
        */
        void fillModel();
};

#endif /* BOOKING_H*/