#ifndef SH_BillingsTableModel_H
#define SH_BillingsTableModel_H
#include <QtSql/QSqlRelationalTableModel>
#include "SH_ExtendedSqlProxyModel.h"

/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_BillingsTableModel billings_table_model.h "models/billings_table_model.h"
*/
class SH_BillingsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:



/*!
 * \brief \~french
 * \fn SH_BillingsTableModel
 * \param parent
*/
    SH_BillingsTableModel(QObject *parent = 0);

protected:



/*!
    * \brief \~french
 * \fn fillModel
    */
    void fillModel();

};
/*}*/
#endif /* SH_BillingsTableModel*/
