#include "models/SH_SqlQueryModel.h"
#ifndef SH_ReportsTableModel_H
#define SH_ReportsTableModel_H

#include "SH_ExtendedProxyFuncResultModel.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_ReportsTableModel
\headerfile services_table_model.h "models/services_table_model.h"
*/
class SH_ReportsTableModel : public SH_ExtendedProxyFuncResultModel
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
