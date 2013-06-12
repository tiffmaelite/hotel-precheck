#include <exception>
#include <QtWidgets/QWidget>
#include <QDebug>
#include "customizableTabWidget.h"
#include "app.h"

CustomizableTabWidget::CustomizableTabWidget(int tabsHeight, QWidget *parent) :
    QTabWidget((QWidget*) parent)
{

    QString style = styleSheet();
    this->baseStyle = style.left(style.length()-1);
    if(this->baseStyle == "") {
        this->baseStyle = "QTabBar::tab {";
    }
    this->widthStyle = "";
    this->heightStyle = "height: " + QString::number(tabsHeight) + "px;";
    this->refreshStyleSheet();

}

void  CustomizableTabWidget::setStyleWidth(double width) {
    this->widthStyle = "width: " + QString::number(width)+ "px;";
    this->refreshStyleSheet();
}

void CustomizableTabWidget::refreshStyleSheet() {
    this->setStyleSheet( this->baseStyle + "  " + this->widthStyle + " " + this->heightStyle + " " + "}");
}

int CustomizableTabWidget::addTab(TabPage *tab) {
    int result = QTabWidget::addTab(tab, tab->getName());
    this->setStyleWidth(this->width()/this->count());
    return result;
}

int CustomizableTabWidget::addTab(QWidget *widget, const QString &label) {
    int result = QTabWidget::addTab(widget, label);
    this->setStyleWidth(this->width()/this->count());
    return result;
}

int CustomizableTabWidget::addTab(QWidget *widget, const QIcon &icon, const QString &label) {
    int result = QTabWidget::addTab(widget, icon, label);
    this->setStyleWidth(this->width()/this->count());
    return result;
}

void CustomizableTabWidget::removeTab(int index) {
    QTabWidget::removeTab(index);
    this->setStyleWidth(this->width()/this->count());
}

