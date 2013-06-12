#include "bookingsTab.h"
#include <QDebug>
#include <QtWidgets/QWidget>

BookingsTabPage::BookingsTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent) :
    TabPageWithTable(tabName, parent)
{
    this->initTable(rowsCount, columnsCount);
}

void BookingsTabPage::fetchDatas() {
    try {
        this->datas->model()->setTable("bookings");

        this->datas->model()->setRelation(1, QSqlRelation("clients", "id", "name"));

        this->datas->model()->setHeaderData(0, Qt::Horizontal, QObject::tr("Date réservation"));
        this->datas->model()->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom client"));
        this->datas->model()->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arrivée prévue"));
        this->datas->model()->setHeaderData(3, Qt::Horizontal, QObject::tr("Nb Personnes"));

        this->datas->model()->setSort(0, Qt::AscendingOrder);

        /*
    //remplissage du tableau
        this->table->setItem(0,0,new QTableWidgetItem("Date"));
        this->table->setItem(0,1,new QTableWidgetItem("Nom client"));

        QTableWidgetItem *item = new QTableWidgetItem("réservation test");
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
