#include "billingsTab.h"
#include "models/billingsTableModel.h"
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

        /*
        //remplissage du tableau
        this->table->setItem(0,0,new QTableWidgetItem("Date"));
        this->table->setItem(0,1,new QTableWidgetItem("Nom client"));
        this->table->setItem(0,2,new QTableWidgetItem("Chambre"));
        this->table->setItem(0,3,new QTableWidgetItem("Nb factures"));

        QTableWidgetItem *item = new QTableWidgetItem("facturation test");
        this->table->setItem(1,1,item);

        //activation du tri pour usage ultérieur
        this->table->setSortingEnabled(true);
this->table->sortByColumn(0);
*/
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
