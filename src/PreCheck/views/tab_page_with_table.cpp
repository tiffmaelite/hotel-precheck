#include "tab_page_with_table.h"
#include <QtWidgets/QWidget>
#include <QDebug>
#include "models/my_sql_relational_delegate.h"

TabPageWithTable::TabPageWithTable(QString tabName, QWidget *parent) :
    TabPage(3, 3, tabName, parent)
{
    this->table = new QTableView(this);
}

void TabPageWithTable::initTable(int rows, int columns) {
    try {
        /*this->table->setColumnCount(rows);
        this->table->setRowCount(columns);
        //désactivation du tri lors du remplissage du tableau
        this->table->setSortingEnabled(false);*/
        this->fetchDatas();
        this->table->setModel(this->datas);
        this->table->setItemDelegate(new mySqlRelationalDelegate(this->table));
        //this->table->setItemDelegate(new QSqlRelationalDelegate(this->table));
        this->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //this->table->show();
        this->tabLayout->insertWidget(5,this->table);
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

