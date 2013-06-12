#include "tabPageWithKeys.h"
#include <QtWidgets/QWidget>
#include <QList>
#include <QtWidgets/QPushButton>

#ifndef KEYBOARDTAB_H
#define KEYBOARDTAB_H

class KeyboardTabPage : public TabPageWithKeys
{
    Q_OBJECT
public:
    KeyboardTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void fillKeyboard();
};

#endif // KEYBOARDTAB_H
