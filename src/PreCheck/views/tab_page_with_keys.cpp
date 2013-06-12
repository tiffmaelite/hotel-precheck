#include "tab_page_with_keys.h"
#include <QDebug>

TabPageWithKeys::TabPageWithKeys(int rowsCount, int columnsCount, QString tabName, QWidget *parent) :
    TabPage(1, 1, tabName, parent)
{

    try {
        this->keys = new Keyboard(rowsCount, columnsCount,this);

    }
    catch(std::exception &exception)
    {
        qDebug() << "pb init prestations";
    }
}

void TabPageWithKeys::initKeyboard() {
    this->fillKeyboard();
    this->tabLayout->insertWidget(0,this->keys);
}
