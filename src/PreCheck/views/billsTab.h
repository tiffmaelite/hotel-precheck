#include "tabPageWithTable.h"

#ifndef BILLSTAB_H
#define BILLSTAB_H

class BillsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:
    BillsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void fetchDatas();
    
};

#endif // BILLSTAB_H
