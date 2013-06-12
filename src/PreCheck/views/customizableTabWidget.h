#ifndef CUSTOMIZABLETABWIDGET_h
#define CUSTOMIZABLETABWIDGET_h


#include "fixedGridLayout.h"
#include "tabPage.h"

#include <QtWidgets/QTabWidget>


class CustomizableTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    CustomizableTabWidget(int tabsHeight, QWidget *parent = 0);
    int addTab(TabPage *tab);
    int addTab(QWidget *widget, const QString &label);
    int addTab(QWidget *widget, const QIcon &icon, const QString &label);
    void removeTab(int index);

protected:


signals:
    
public slots:

protected:
    void setStyleWidth(double width);

private:
    QString baseStyle;
    QString heightStyle;
    QString widthStyle;
    void refreshStyleSheet();
};

#endif // CUSTOMIZABLETABWIDGET_h
