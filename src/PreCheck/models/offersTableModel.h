#ifndef OFFER_H
#define OFFER_H

#include "models/checkablesortfilterproxymodel.h"

class OffersTableModel : public CheckableSortFilterProxyModel
{
public:
    OffersTableModel(QString filter="", QObject *parent=0);

protected:
    void fillModel();
};

#endif // OFFER_H
