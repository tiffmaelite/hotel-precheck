#ifndef VAT_H
#define VAT_H

#include "SH_ExtendedProxyTableModel.h"
#include "SH_SqlDataField.h"
#include <QtQml>
#include <QtQuick>

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_VATTableModel
\headerfile VAT_table_model.h "models/VAT_table_model.h"
*/
class SH_VATTableModel : public SH_ExtendedProxyTableModel
{
    Q_OBJECT
public:


/*!
\brief \~french

 \fn VATTableModel
 \param parent
*/
    SH_VATTableModel(QObject *parent = 0);

protected:

/*!
    \brief \~french

    \fn fillModel
    */
    virtual void fillModel();
private:

};
/*}*/
#endif /* VAT_H*/
