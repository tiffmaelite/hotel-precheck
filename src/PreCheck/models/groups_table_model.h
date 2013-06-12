#include <QtSql/QSqlRelationalTableModel>

#ifndef GROUP_H
#define GROUP_H

#include "models/checkable_sort_filter_proxy_model.h"

/*!
 \brief

 \class GroupsTableModel groups_table_model.h "models/groups_table_model.h"
*/
class GroupsTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn GroupsTableModel
 \param parent
*/
        GroupsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // GROUP_H
