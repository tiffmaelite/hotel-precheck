#ifndef SH_BillsTableModel_H
#define SH_BillsTableModel_H
#include <QtSql/QSqlRelationalTableModel>
#include "SH_ExtendedSqlProxyModel.h"

/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_BillsTableModel bills_table_model.h "models/bills_table_model.h"
*/
class SH_BillsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT

    public:

/*!
 * \brief \~french
 * \fn SH_BillsTableModel
 * \param parent
*/
    SH_BillsTableModel(QObject *parent = 0);

    protected:



/*!
    * \brief \~french
 * \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* BILLS_H*/
