#include <QtSql/QSqlRelationalTableModel>
#ifndef CLIENT_H
#define CLIENT_H

#include "models/checkable_sort_filter_proxy_model.h"



/*!
 \brief

 \class ClientsTableModel clients_table_model.h "models/clients_table_model.h"
*/
class ClientsTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn ClientsTableModel
 \param parent
*/
        ClientsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // CLIENT_H
