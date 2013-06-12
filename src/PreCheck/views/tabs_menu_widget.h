#ifndef TABSMENUWIDGET_H
#define TABSMENUWIDGET_H

#include <QtWidgets/QTabWidget>

/*!
 \brief

*/
class TabsMenuWidget : public QTabWidget
{
    Q_OBJECT
public:

/*!
 \brief

 \param maxRowsCount
*/
    TabsMenuWidget(int maxRowsCount);

    /*!
     \brief

     \param widget
     \param label
     \return int
    */
    int addTab(QWidget *widget, const QString &label);

    /*!
     \brief

     \param widget
     \param icon
     \param label
     \return int
    */
    int addTab(QWidget *widget, const QIcon &icon, const QString &label);

    /*!
     \brief

     \param index
    */
    void removeTab(int index);

signals:
    
public slots:
    
protected:

    /*!
     \brief

     \param width
    */
    void setStyleWidth(double width);

private:
    QString baseStyle; /*!< TODO */
    QString heightStyle; /*!< TODO */
    QString widthStyle; /*!< TODO */

    /*!
     \brief

    */
    void refreshStyleSheet();
};

#endif // TABSMENUWIDGET_H
