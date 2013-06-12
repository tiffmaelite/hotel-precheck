#include "tabs_menu_widget.h"
#include <QDebug>

TabsMenuWidget::TabsMenuWidget(int maxRowsCount) :
    QTabWidget()
{
    QString style = styleSheet();
    baseStyle = baseStyle.left(style.length()-1);
    if(baseStyle == "") {
        baseStyle = "QTabBar::tab {";
    }
    widthStyle = "";
    heightStyle = "height: " + QString::number((9*height())/(maxRowsCount*10)) + "px;";
    refreshStyleSheet();
}

void  TabsMenuWidget::setStyleWidth(double width) {
    widthStyle = "width: " + QString::number(width)+ "px;";
    refreshStyleSheet();
}

void TabsMenuWidget::refreshStyleSheet() {
    setStyleSheet( baseStyle + "  " + widthStyle + " " + heightStyle + " " + "}");
}

int TabsMenuWidget::addTab(QWidget *widget, const QString &label) {
    int result = QTabWidget::addTab(widget, label);
    setStyleWidth(width()/count());
    return result;
}

int TabsMenuWidget::addTab(QWidget *widget, const QIcon &icon, const QString &label) {
    int result = QTabWidget::addTab(widget, icon, label);
    setStyleWidth(width()/count());
    return result;
}

void TabsMenuWidget::removeTab(int index) {
    QTabWidget::removeTab(index);
    setStyleWidth(width()/count());
}

