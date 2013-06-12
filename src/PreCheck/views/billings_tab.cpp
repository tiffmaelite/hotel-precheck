#include "billings_tab.h"
#include "models/billings_table_model.h"
#include <QDebug>
#include <QtWidgets/QWidget>

BillingsTabPage::BillingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent) :
    TabPageWithTable(tabName, parent)
{
    this->initTable(rowsCount, columnsCount);
}

void BillingsTabPage::fetchDatas() {
    try {
        this->datas = new BillingsTableModel();
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
