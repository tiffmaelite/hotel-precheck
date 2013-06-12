#include "roomsTab.h"
#include "models/roomsTableModel.h"
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

        /*this->table->setItem(0,0,new QTableWidgetItem("Numéro"));
        this->table->setItem(0,1,new QTableWidgetItem("État"));
        this->table->setItem(0,2,new QTableWidgetItem("Nb Personnes"));

        QTableWidgetItem *item = new QTableWidgetItem("chambre test");
        this->table->setItem(1,1,item);

        //activation du tri pour usage ultérieur
        this->table->setSortingEnabled(true);
        this->table->sortByColumn(0);*/
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
