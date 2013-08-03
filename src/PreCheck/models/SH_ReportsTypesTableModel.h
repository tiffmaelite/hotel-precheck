#include <QtSql/QSqlRelationalTableModel>
#ifndef SH_ReportsTypesTableModel_H
#define SH_ReportsTypesTableModel_H

#include "SH_ExtendedProxyTableModel.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_ReportsTypesTableModel
\headerfile services_table_model.h "models/services_table_model.h"
*/
class SH_ReportsTypesTableModel : public SH_ExtendedProxyTableModel
{
    Q_OBJECT
public:



/*!
\brief \~french

 \fn SH_ReportsTypesTableModel
 \param parent
*/
    SH_ReportsTypesTableModel(QObject *parent = 0);


protected:


/*!
    \brief \~french

    \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* SH_ReportsTypesTableModel_H*/
