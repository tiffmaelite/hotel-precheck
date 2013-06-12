#include "tabPageWithKeys.h"
#include <QtWidgets/QWidget>
#include <QList>
#include <QtWidgets/QPushButton>

#ifndef SERVICESTAB_H
#define SERVICESTAB_H

class ServicesTabPage : public TabPageWithKeys
{
    Q_OBJECT
public:
    ServicesTabPage(int rowsCount,int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void fillKeyboard();
};

#endif // SERVICESTAB_H
