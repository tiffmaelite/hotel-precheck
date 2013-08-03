#include <QtSql/QSqlRelationalTableModel>
#ifndef SH_ServicesTableModel_H
#define SH_ServicesTableModel_H

#include "SH_ExtendedProxyTableModel.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_ServicesTableModel
\headerfile services_table_model.h "models/services_table_model.h"
*/
class SH_ServicesTableModel : public SH_ExtendedProxyTableModel
{
    Q_OBJECT
public:



/*!
\brief \~french

 \fn SH_ServicesTableModel
 \param parent
*/
    SH_ServicesTableModel(QObject *parent = 0);


protected:


/*!
    \brief \~french

    \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* SH_ServicesTableModel_H*/
