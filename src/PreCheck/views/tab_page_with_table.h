#include "tab_page.h"
#include <QtWidgets/QTableView>
#include "models/checkable_sort_filter_proxy_model.h"


#ifndef TABPAGEWITHTABLE_H
#define TABPAGEWITHTABLE_H


/*!
 \brief

*/
class TabPageWithTable : public TabPage
{
    Q_OBJECT
public:  

/*!
 \brief

 \param tabName
 \param parent
*/
    TabPageWithTable(QString tabName, QWidget *parent);

signals:
    
public slots:

protected:
    QTableView *table; /*!< TODO */
    CheckableSortFilterProxyModel *datas; /*!< TODO */

    /*!
     \brief

    */
    virtual void fetchDatas () = 0;

    /*!
     \brief

     \param rows
     \param columns
    */
    void initTable(int rows, int columns);
    
};

#endif // TABPAGEWITHTABLE_H
