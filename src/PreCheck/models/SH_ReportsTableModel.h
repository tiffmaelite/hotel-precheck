#include <QtSql/QSqlRelationalTableModel>
#ifndef SH_ReportsTableModel_H
#define SH_ReportsTableModel_H

#include "SH_ExtendedSqlProxyModel.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_ReportsTableModel
\headerfile services_table_model.h "models/services_table_model.h"
*/
class SH_ReportsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:



/*!
\brief \~french

 \fn SH_ReportsTableModel
 \param parent
*/
    SH_ReportsTableModel(QObject *parent = 0);


protected:


/*!
    \brief \~french

    \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* SH_ReportsTableModel_H*/
