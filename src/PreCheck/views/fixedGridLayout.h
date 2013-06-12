#ifndef FIXEDGRIDLAYOUT_H
#define FIXEDGRIDLAYOUT_H

#include <QtWidgets/QGridLayout>
#include <QPoint>

class FixedGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    FixedGridLayout(int rows,int columns, QWidget *parent = 0);
    void addWidget(QWidget *widget);
    void addWidget(QWidget *widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align);
    void insertWidget(int index, QWidget *widget);
    void addLayout(QLayout *layout);
    void addLayout(QLayout *layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align);
    void insertLayout(int index, QLayout *layout);
    int getRowsCount();
    int getColumnsCount();

signals:
    
public slots:

protected:
    int rowsCount;
    int columnsCount;
    int currentRow;
    int currentColumn;

private:
    QPoint* computePosition(int col, int row);
};

#endif // FIXEDGRIDLAYOUT_H
