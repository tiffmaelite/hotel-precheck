#ifndef ROOM_H
#define ROOM_H

#include "models/checkablesortfilterproxymodel.h"

class RoomsTableModel : public CheckableSortFilterProxyModel
{
public:
    RoomsTableModel(QString filter="", QObject *parent=0);

protected:
    void fillModel();
};

#endif // ROOM_H
