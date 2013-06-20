#ifndef RENT_H
#define RENT_H
#include <QtSql/QSqlRelationalTableModel>
#include "SH_ExtendedSqlProxyModel.h"



/*!
 \brief

 \class BillingsTableModel billings_table_model.h "models/billings_table_model.h"
*/
class SH_BillingsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:


    /*!
 \brief

 \fn BillingsTableModel
 \param parent
*/
    SH_BillingsTableModel(QObject *parent = 0);

protected:


    /*!
         \brief

         \fn fillModel
        */
    void fillModel();

};

#endif // RENT_H
