#ifndef ROOM_H
#define ROOM_H

#include "SH_ExtendedSqlProxyModel.h"
#include "SH_SqlDataField.h"
#include <QtQml>
#include <QtQuick>


/*!
 \brief

 \class RoomsTableModel rooms_table_model.h "models/rooms_table_model.h"
*/
class SH_RoomsTableModel : public SH_ExtendedProxyModel
{
        Q_OBJECT
    public:

/*!
 \brief

 \fn RoomsTableModel
 \param parent
*/
        SH_RoomsTableModel(QObject *parent = 0);

    protected:
        /*!
         \brief

         \fn fillModel
        */
        virtual void fillModel();
    private:

};

#endif // ROOM_H
