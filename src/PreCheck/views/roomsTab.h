#include "tabPageWithTable.h"

#ifndef ROOMSTAB_H
#define ROOMSTAB_H

class RoomsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:
    RoomsTabPage(int rowsCount,int columnsCount, QString tabName, QWidget *parent = 0);

signals:

public slots:

private:
    void fetchDatas();

};

#endif // ROOMSTAB_H_H
