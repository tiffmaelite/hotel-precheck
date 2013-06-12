#include "rooms_tab.h"
#include "models/rooms_table_model.h"
#include <QtWidgets/QWidget>
#include <QDebug>

RoomsTabPage::RoomsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent) :
    TabPageWithTable(tabName, parent)
{
    this->initTable(rowsCount, columnsCount);
}

void RoomsTabPage::fetchDatas() {
    try {
        this->datas = new RoomsTableModel();
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
