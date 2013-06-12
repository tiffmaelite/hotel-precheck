#include <QtSql/QSqlRelationalTableModel>
#ifndef RENT_H
#define RENT_H

#include "checkable_sort_filter_proxy_model.h"



/*!
 \brief

 \class BillingsTableModel billings_table_model.h "models/billings_table_model.h"
*/
class BillingsTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
public:


    /*!
 \brief

 \fn BillingsTableModel
 \param parent
*/
    BillingsTableModel(QObject *parent = 0);

protected:


    /*!
         \brief

         \fn fillModel
        */
    void fillModel();

};

#endif // RENT_H
