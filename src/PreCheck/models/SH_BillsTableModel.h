#ifndef BILLS_H
#define BILLS_H
#include <QtSql/QSqlRelationalTableModel>
#include "SH_ExtendedSqlProxyModel.h"



/*!
 \brief

 \class BillsTableModel bills_table_model.h "models/bills_table_model.h"
*/
class SH_BillsTableModel : public SH_ExtendedProxyModel
{
        Q_OBJECT

    public:

/*!
 \brief

 \fn BillsTableModel
 \param parent
*/
        SH_BillsTableModel(QObject *parent = 0);

    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // BILLS_H
