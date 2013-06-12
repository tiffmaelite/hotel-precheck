#include "bookings_tab.h"
#include "models/bookings_table_model.h"
#include <QDebug>
#include <QtWidgets/QWidget>

BookingsTabPage::BookingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent) :
    TabPageWithTable(tabName, parent)
{
    this->initTable(rowsCount, columnsCount);
}

void BookingsTabPage::fetchDatas() {
    try {
        this->datas = new BookingsTableModel();
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
