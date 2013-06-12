#include "keyboard.h"
#include <QtGlobal>
#include <QDebug>
#include <QtWidgets/QFrame>
#include "math.h"
#include <QtWidgets/QWidget>
#include <QString>
#include "touch_button.h"

Keyboard::Keyboard(int rowsCount, int columnsCount, QWidget *parent) :
    QWidget(parent)
{
    try {

        this->keysLayout = new FixedGridLayout(rowsCount, columnsCount, this);
        this->keysLayout->setSpacing(0);
        this->keysLayout->setContentsMargins(0,0,0,0);

        this->maxWidth = parent->width()-this->keysLayout->spacing();
        this->maxHeight = parent->height()-this->keysLayout->spacing();

        this->buttonsFont = new QFont(QObject::tr("Arial"));

        int max = rowsCount*columnsCount;
        int i = 0;

        for(i=0;i<max;i++) {
            this->setButton("", i, true, new QColor(Qt::white));
        }

        this->setLayout(this->keysLayout);

    }
    catch(std::exception &exception)
    {
        qDebug() << "pb init boutons";
    }
}

int Keyboard::getLineLength() {
    return (this->getKeysWidth() / this->buttonsFont->wordSpacing());
}

int Keyboard::getColumnsCount() {
    return this->keysLayout->getColumnsCount();
}

int Keyboard::getRowsCount() {
    return this->keysLayout->getRowsCount();
}


void Keyboard::setButton(QString textLabel, int index, bool pushable, QColor *colorCode) {
    try {
        TouchButton *btn = new TouchButton(this);
        btn->setMaximumSize(this->maxWidth, this->maxHeight);
        btn->setMinimumSize(this->getKeysWidth(), this->getKeysHeight());
        btn->setFont(*this->buttonsFont);
        btn->setEnabled(pushable);
        //if(textLabel.length() > this->getLineLength()) {
        //TODO: trouver premier espace avant maxNbChars et le remplacer par \n, s'il n'y en a pas, introduire un \n à la position maxNbChars-1
        //}
        btn->setText(textLabel);
        btn->setAutoFillBackground(true);
        QPalette palette = this->palette();
        palette.setBrush (btn->backgroundRole (),*colorCode);
        palette.setColor(QPalette::Button, *colorCode);
        palette.setColor(QPalette::ButtonText, Qt::black);
        btn->setPalette(palette);
        this->keysLayout->insertWidget(index, btn);
    }
    catch(std::exception &exception)
    {
        qDebug() << "PB ajout bouton clavier !";
    }
}

void Keyboard::setContentsMargins(int left, int top, int right, int bottom) {
    QMargins oldMargins = contentsMargins();
    this->maxWidth = this->maxWidth + oldMargins.left() - left + oldMargins.right() - right;
    this->maxHeight = this->maxHeight + oldMargins.top() - top + oldMargins.bottom() - bottom;
    QWidget::setContentsMargins(left, top, right, bottom);
    resizeKeys();
}


void Keyboard::setSpacing(int spacing) {
    int oldSpacing = this->keysLayout->spacing();
    this->maxWidth = this->maxWidth + oldSpacing - spacing;
    this->maxHeight = this->maxHeight + oldSpacing - spacing;
    this->keysLayout->setSpacing(spacing);
    resizeKeys();
}

void Keyboard::resizeKeys() {
    int quantity = this->getColumnsCount()*this->getRowsCount();
    int index = 0;
    QLayoutItem* item;

    for(index = 0; index < quantity; index++) {
        item = this->keysLayout->itemAt(index);
        if(qobject_cast<TouchButton*>(item->widget()) != NULL) {
            item->widget()->setMaximumSize(this->maxWidth, this->maxHeight);
            item->widget()->setMinimumSize(this->getKeysWidth(), this->getKeysHeight());
        }
    }
}

double Keyboard::getKeysHeight() {
    return qRound(this->maxHeight/this->getRowsCount());
}

double Keyboard::getKeysWidth() {
    return qRound(this->maxWidth/this->getColumnsCount());
}
