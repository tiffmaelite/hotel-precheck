#include "keyboard.h"
#include "tab_page.h"

#ifndef TABPAGEWITHKEYS_H
#define TABPAGEWITHKEYS_H


/*!
 \brief

*/
class TabPageWithKeys : public TabPage
{
public:

/*!
 \brief

 \param rowsCount
 \param columnsCount
 \param tabName
 \param parent
*/
    TabPageWithKeys(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);

protected:
    Keyboard *keys; /*!< TODO */

    /*!
     \brief

    */
    void initKeyboard();

    /*!
     \brief

    */
    virtual void fillKeyboard() = 0;
};

#endif // TABPAGEWITHKEYS_H
