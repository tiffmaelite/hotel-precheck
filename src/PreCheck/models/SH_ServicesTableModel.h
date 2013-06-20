#include <QtSql/QSqlRelationalTableModel>
#ifndef SERVICE_H
#define SERVICE_H

#include "SH_ExtendedSqlProxyModel.h"

/*!
 \brief

 \class ServicesTableModel services_table_model.h "models/services_table_model.h"
*/
class SH_ServicesTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:


/*!
 \brief

 \fn ServicesTableModel
 \param parent
*/
        SH_ServicesTableModel(QObject *parent = 0);


    protected:

        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // SERVICE_H
