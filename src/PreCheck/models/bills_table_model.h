#include <QtSql/QSqlRelationalTableModel>
#ifndef BILLS_H
#define BILLS_H

#include "models/checkable_sort_filter_proxy_model.h"



/*!
 \brief

 \class BillsTableModel bills_table_model.h "models/bills_table_model.h"
*/
class BillsTableModel : public CheckableSortFilterProxyModel
{
        Q_OBJECT

    public:

/*!
 \brief

 \fn BillsTableModel
 \param parent
*/
        BillsTableModel(QObject *parent = 0);

    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // BILLS_H
