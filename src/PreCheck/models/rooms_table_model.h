#ifndef ROOM_H
#define ROOM_H

#include "checkable_sort_filter_proxy_model.h"
#include "sql_data_field.h"
#include <QtQml>
#include <QtQuick>


/*!
 \brief

 \class RoomsTableModel rooms_table_model.h "models/rooms_table_model.h"
*/
class RoomsTableModel : public CheckableSortFilterProxyModel
{
        Q_OBJECT
    public:

/*!
 \brief

 \fn RoomsTableModel
 \param parent
*/
        RoomsTableModel(QObject *parent = 0);

    protected:
        /*!
         \brief

         \fn fillModel
        */
        virtual void fillModel();
    private:

};

#endif // ROOM_H
