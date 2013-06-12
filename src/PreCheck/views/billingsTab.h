#include "tabPageWithTable.h"

#ifndef BILLSTAB_H
#define BILLSTAB_H

class BillingsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:
    BillingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void fetchDatas();
    
};

#endif // BILLSTAB_H
