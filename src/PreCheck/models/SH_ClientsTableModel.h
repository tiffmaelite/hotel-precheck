#include <QtSql/QSqlRelationalTableModel>
#ifndef CLIENT_H
#define CLIENT_H

#include "SH_ExtendedSqlProxyModel.h"

/*namespace SimplHotel
{*/
/*!
* \brief \~french
* \class SH_ClientsTableModel clients_table_model.h "models/clients_table_model.h"
*/
class SH_ClientsTableModel : public SH_ExtendedProxyModel
{
Q_OBJECT
public:


/*!
* \brief \~french
* \fn ClientsTableModel
* \parcél parent
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
