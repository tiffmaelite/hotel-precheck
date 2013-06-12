#include "tab_page_with_table.h"

#ifndef BILLSTAB_H
#define BILLSTAB_H


/*!
 \brief

*/
class BillingsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:

/*!
 \brief

 \param rowsCount
 \param columnsCount
 \param tabName
 \param parent
*/
    BillingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

private:

    /*!
     \brief

    */
    void fetchDatas();
    
};

#endif // BILLSTAB_H
