#include "tab_page_with_table.h"


#ifndef BOOKINGSTAB_H
#define BOOKINGSTAB_H


/*!
 \brief

*/
class BookingsTabPage : public TabPageWithTable
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
    BookingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

private:

    /*!
     \brief

    */
    void fetchDatas();
    
};

#endif // BOOKINGSTAB_H
