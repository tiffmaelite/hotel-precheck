#include "tabPageWithTable.h"


#ifndef BOOKINGSTAB_H
#define BOOKINGSTAB_H

class BookingsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:
    BookingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void fetchDatas();
    
};

#endif // BOOKINGSTAB_H
