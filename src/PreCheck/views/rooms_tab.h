#include "tab_page_with_table.h"

#ifndef ROOMSTAB_H
#define ROOMSTAB_H


/*!
 \brief

*/
class RoomsTabPage : public TabPageWithTable
{
    Q_OBJECT
public:
/**
 * @brief
 *
 * @param rowsCount
 * @param columnsCount
 * @param tabName
 * @param parent
 */
/*!
 \brief

 \param rowsCount
 \param columnsCount
 \param tabName
 \param parent
*/
    RoomsTabPage(int rowsCount,int columnsCount, QString tabName, QWidget *parent = 0);

signals:

public slots:

private:

    /*!
     \brief

    */
    void fetchDatas();

};

#endif // ROOMSTAB_H_H
