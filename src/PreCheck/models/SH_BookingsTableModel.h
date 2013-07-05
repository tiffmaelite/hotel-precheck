#include <QtSql/QSqlRelationalTableModel>
#ifndef SH_BookingsTableModel_H
#define SH_BookingsTableModel_H

#include "SH_ExtendedSqlProxyModel.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_BookingsTableModel
 * \headerfile bookings_table_model.h "models/bookings_table_model.h"
*/
class SH_BookingsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    public:


/*!
 * \brief \~french
 * \fn SH_BookingsTableModel
 * \param parent
*/
    SH_BookingsTableModel(QObject *parent = 0);


    protected:



/*!
    * \brief \~french
 * \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* BOOKING_H*/
