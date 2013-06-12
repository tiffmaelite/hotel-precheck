#include "keyboard.h"
#include <QtGlobal>
#include <QDebug>
#include <QtWidgets/QWidget>
#include "keyboardTab.h"

KeyboardTabPage::KeyboardTabPage(int rowsCount, int columnsCount, QString tabName,  QWidget *parent) :
    TabPageWithKeys(rowsCount,columnsCount, tabName, parent)
{
    initKeyboard();
}

void KeyboardTabPage::fillKeyboard() {

    try {

        this->keys->setButton("Q",0);
        this->keys->setButton("W",1);
        this->keys->setButton("E",2);
        this->keys->setButton("R",3);
        this->keys->setButton("T",4);
        this->keys->setButton("Z",5);

    }
    catch(std::exception &exception)
    {
        qDebug() << "pb init prestations";
    }
}
