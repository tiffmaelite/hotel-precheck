#include "fixedGridLayout.h"
#include <QDebug>
#include <QtGlobal>
#include <QtWidgets/QWidget>

FixedGridLayout::FixedGridLayout(int rows, int columns, QWidget *parent) :
    QGridLayout(parent)
{
    try{
        this->currentRow = 0;
        this->currentColumn = 0;
        this->rowsCount = rows;
        this->columnsCount = columns;
        this->setContentsMargins(0,0,0,0);
        this->setSpacing(0);
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

int FixedGridLayout::getRowsCount() {
    return this->rowsCount;
}

int FixedGridLayout::getColumnsCount() {
    return this->columnsCount;
}

QPoint* FixedGridLayout::computePosition(int column, int row) {
    QPoint* position;
    if(this->columnsCount <= column) {
        column = 0;
        row++;
    }
    if(this->rowsCount >= row) {
        position = new QPoint(column, row);
        column++;
        this->currentColumn = qMax(column, this->currentColumn);
        this->currentRow = qMax(row, this->currentRow);
    }
    /*qDebug() << position->x();
    qDebug() << position->y();*/
    return position;
}


void FixedGridLayout::addWidget(QWidget *widget) {
    try {
        QPoint *position = this->computePosition(this->currentColumn, this->currentRow);
        if(position==NULL) {
            qWarning("Pas assez de lignes pour l'ajout du widget ! %d / %d",this->currentRow,this->rowsCount);
        } else {
            QGridLayout::addWidget(widget,position->y(), position->x());
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

void FixedGridLayout::addWidget(QWidget *widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align = 0) {
    try {
        QPoint *startPosition = this->computePosition(row, column);
        QPoint *endPosition = this->computePosition(column+columnSpan, row+rowSpan);
        if(!(startPosition==NULL || endPosition==NULL)) {
            QGridLayout::addWidget(widget,startPosition->y(), startPosition->x(), rowSpan, columnSpan, align);
        } else{
            qWarning("Pas assez de place pour l'ajout du widget de largeur %d et de hauteur %d ! %d / %d lignes et %d / %d colonnes",columnSpan, rowSpan,this->currentRow,this->rowsCount,this->currentColumn,this->columnsCount);
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

void FixedGridLayout::insertWidget(int index, QWidget *widget) {
    try {
        int column = index%this->columnsCount;
        int row = index/this->columnsCount;
        QPoint *position = this->computePosition(column, row);

        if(position==NULL) {
            qWarning("Pas assez de lignes pour l'ajout du widget a la position %d ! %d / %d",index, this->currentRow,this->rowsCount);
        } else{
            QGridLayout::addWidget(widget,position->y(), position->x());
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

void FixedGridLayout::addLayout(QLayout *layout) {
    try {
        QPoint *position = this->computePosition(this->currentColumn, this->currentRow);

        if(position!=NULL) {
            QGridLayout::addLayout(layout,position->y(), position->x());
        } else{
            qWarning("Pas assez de lignes pour l'ajout du layout ! %d / %d",this->currentRow,this->rowsCount);
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

void FixedGridLayout::addLayout(QLayout *layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align = 0) {
    try {
        QPoint *startPosition = this->computePosition(column, row);
        QPoint *endPosition = this->computePosition(column+columnSpan, row+rowSpan);
        if(!(startPosition==NULL || endPosition==NULL)) {
            QGridLayout::addLayout(layout,startPosition->y(), startPosition->x(), rowSpan, columnSpan, align);
        } else{
            qWarning("Pas assez de place pour l'affichage du layout de largeur %d et de hauteur %d ! %d / %d lignes et %d / %d colonnes",columnSpan, rowSpan,this->currentRow,this->rowsCount, this->currentColumn,this->columnsCount);
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}

void FixedGridLayout::insertLayout(int index, QLayout *layout) {
    try {
        int column = index%this->columnsCount;
        int row = index/this->columnsCount;
        QPoint *position = this->computePosition(column, row);

        if(position != NULL) {
            QGridLayout::addLayout(layout,position->y(), position->x());
        } else{
            qWarning("Pas assez de lignes pour l'insertion du layout a la position %d ! %d / %d",index, this->currentRow,this->rowsCount);
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }
}
