#ifndef TABSMENUWIDGET_H
#define TABSMENUWIDGET_H

#include <QtWidgets/QTabWidget>

class TabsMenuWidget : public QTabWidget
{
    Q_OBJECT
public:
    TabsMenuWidget(int maxRowsCount);
    int addTab(QWidget *widget, const QString &label);
    int addTab(QWidget *widget, const QIcon &icon, const QString &label);
    void removeTab(int index);

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

#endif // TABSMENUWIDGET_H
