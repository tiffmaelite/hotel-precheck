#include <QtSql/QSqlRelationalTableModel>

#ifndef GROUP_H
#define GROUP_H

#include "SH_ExtendedSqlProxyModel.h"

/*!
 \brief

 \class GroupsTableModel groups_table_model.h "models/groups_table_model.h"
*/
class SH_GroupsTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn GroupsTableModel
 \param parent
*/
        SH_GroupsTableModel(QObject *parent = 0);


    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // GROUP_H
