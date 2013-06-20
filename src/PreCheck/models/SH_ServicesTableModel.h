#include <QtSql/QSqlRelationalTableModel>
#ifndef SERVICE_H
#define SERVICE_H

#include "SH_ExtendedSqlProxyModel.h"

/*!
 \brief

 \class SH_ServicesTableModel
\headerfile services_table_model.h "models/services_table_model.h"
*/
class SH_ServicesTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:


    /*!
 \brief

 \fn SH_ServicesTableModel
 \param parent
*/
    SH_ServicesTableModel(QObject *parent = 0);


protected:

    /*!
         \brief

         \fn SH_fillModel
        */
    void fillModel();
};

#endif /* SERVICE_H*/