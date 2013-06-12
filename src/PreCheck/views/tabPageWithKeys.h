#include "keyboard.h"
#include "tabPage.h"

#ifndef TABPAGEWITHKEYS_H
#define TABPAGEWITHKEYS_H

class TabPageWithKeys : public TabPage
{
public:
    TabPageWithKeys(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);

protected:
    Keyboard *keys;
    void initKeyboard();
    virtual void fillKeyboard() = 0;
};

#endif // TABPAGEWITHKEYS_H
