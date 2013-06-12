#include "tabPage.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>
#include <QDebug>

TabPage::TabPage(int rows, int columns, QString tabName, QWidget *parent) :
    QWidget(parent)
{
    try {
        this->name = tabName;
        this->setMinimumSize(9*parent->width()/10,9*parent->height()/10);
        this->setMaximumSize(parent->width(),parent->height());
        this->setContentsMargins(0,0,0,0);
        this->rowsCount = rows;
        this->columnsCount = columns;
        qWarning() << this->name;
        qWarning("hauteur de l'onglet : %d, largeur de l'onglet : %d", this->height(), this->width());
        this->tabLayout = new FixedGridLayout(this->rowsCount, this->columnsCount, this);
        this->tabLayout->setContentsMargins(0,0,0,0);
        this->tabLayout->setSpacing(0);
        this->setLayout(this->tabLayout);
        qWarning("hauteur de l'onglet : %d, largeur de l'onglet : %d", this->height(), this->width());
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}


QString TabPage::getName() {
    return this->name;
}
