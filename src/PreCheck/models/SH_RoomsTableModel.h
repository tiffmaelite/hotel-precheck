#ifndef SH_RoomsTableModel_H
#define SH_RoomsTableModel_H

#include "SH_ExtendedProxyTableModel.h"
#include "SH_SqlDataField.h"
#include <QtQml>
#include <QtQuick>

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_RoomsTableModel
\headerfile rooms_table_model.h "models/rooms_table_model.h"
*/
class SH_RoomsTableModel : public SH_ExtendedProxyTableModel
{
    Q_OBJECT
public:


/*!
\brief \~french

 \fn SH_RoomsTableModel
 \param parent
*/
    SH_RoomsTableModel(QObject *parent = 0);

protected:

/*!
    \brief \~french

    \fn fillModel
    */
    virtual void fillModel();
private:

};
/*}*/
#endif /* SH_RoomsTableModel_H*/
