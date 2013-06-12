#include <QtSql/QSqlRelationalTableModel>
#ifndef SERVICE_H
#define SERVICE_H

#include "models/checkable_sort_filter_proxy_model.h"

/*!
 \brief

 \class ServicesTableModel services_table_model.h "models/services_table_model.h"
*/
class ServicesTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
public:


/*!
 \brief

 \fn ServicesTableModel
 \param parent
*/
        ServicesTableModel(QObject *parent = 0);


    protected:

        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // SERVICE_H
