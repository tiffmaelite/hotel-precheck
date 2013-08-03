#include <QtSql/QSqlRelationalTableModel>
#ifndef SH_ClientsTableModel_H
#define SH_ClientsTableModel_H

#include "SH_ExtendedProxyTableModel.h"

/*namespace SimplHotel
{*/
/*!
* \brief \~french
* \class SH_ClientsTableModel clients_table_model.h "models/clients_table_model.h"
*/
class SH_ClientsTableModel : public SH_ExtendedProxyTableModel
{
Q_OBJECT
public:


/*!
* \brief \~french
* \fn SH_ClientsTableModel
* \param parent
*/
SH_ClientsTableModel(QObject *parent = 0);


protected:


/*!
* \brief \~french
* \fn fillModel
*/
void fillModel();
};
/*}*/
#endif /* CLIENT_H*/
