#include <QtSql/QSqlRelationalTableModel>
#ifndef CLIENT_H
#define CLIENT_H

#include "SH_ExtendedSqlProxyModel.h"



/*!
 \brief

 \class ClientsTableModel clients_table_model.h "models/clients_table_model.h"
*/
class SH_ClientsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn ClientsTableModel
 \param parent
*/
        SH_ClientsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // CLIENT_H
