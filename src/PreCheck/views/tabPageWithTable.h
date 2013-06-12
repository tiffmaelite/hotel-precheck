#include "tabPage.h"
#include <QtWidgets/QTableView>
#include "models/checkablesortfilterproxymodel.h"


#ifndef TABPAGEWITHTABLE_H
#define TABPAGEWITHTABLE_H

class TabPageWithTable : public TabPage
{
    Q_OBJECT
public:  
    TabPageWithTable(QString tabName, QWidget *parent);

signals:
    
public slots:

protected:
    QTableView *table;
    CheckableSortFilterProxyModel *datas;
    virtual void fetchDatas () = 0;
    void initTable(int rows, int columns);
    
};

#endif // TABPAGEWITHTABLE_H
