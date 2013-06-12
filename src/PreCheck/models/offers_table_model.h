#ifndef OFFER_H
#define OFFER_H

#include "models/checkable_sort_filter_proxy_model.h"


/*!
 \brief

 \class OffersTableModel offers_table_model.h "models/offers_table_model.h"
*/
class OffersTableModel : public CheckableSortFilterProxyModel
{
    Q_OBJECT
    public:


/*!
 \brief

 \fn OffersTableModel
 \param parent
*/
        OffersTableModel(QObject *parent = 0);

    protected:


        /*!
         \brief

         \fn fillModel
        */
        void fillModel();
};

#endif // OFFER_H
