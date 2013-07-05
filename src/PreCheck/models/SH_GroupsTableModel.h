#include <QtSql/QSqlRelationalTableModel>

#ifndef SH_GroupsTableModel_H
#define SH_GroupsTableModel_H

#include "SH_ExtendedSqlProxyModel.h"

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_GroupsTableModel
\headerfile groups_table_model.h "models/groups_table_model.h"
*/
class SH_GroupsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    public:


/*!
\brief \~french

 \fn SH_GroupsTableModel
 \param parent
*/
    SH_GroupsTableModel(QObject *parent = 0);


    protected:



/*!
    \brief \~french

    \fn fillModel
    */
    void fillModel();
};
/*}*/
#endif /* GROUP_H*/
