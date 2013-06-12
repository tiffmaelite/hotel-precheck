#ifndef TABPAGE_H
#define TABPAGE_H


#include "fixedGridLayout.h"
#include <QString>
#include <QtWidgets/QWidget>

class TabPage : public QWidget
{
    Q_OBJECT
public:
    TabPage(int rows,int columns, QString tabName, QWidget *parent = 0);

    QString getName();
protected:
    FixedGridLayout *tabLayout;

signals:
    
public slots:
    
protected:
    QString name;


private:
    int rowsCount;
    int columnsCount;
};

#endif // TABPAGE_H
