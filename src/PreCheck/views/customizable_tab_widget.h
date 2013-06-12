#ifndef CUSTOMIZABLETABWIDGET_h
#define CUSTOMIZABLETABWIDGET_h


#include "fixed_grid_layout.h"
#include "tab_page.h"

#include <QtWidgets/QTabWidget>



/*!
 \brief

*/
class CustomizableTabWidget : public QTabWidget
{
    Q_OBJECT
public:

/*!
 \brief

 \param tabsHeight
 \param parent
*/
    CustomizableTabWidget(int tabsHeight, QWidget *parent = 0);

    /*!
     \brief

     \param tab
     \return int
    */
    int addTab(TabPage *tab);

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

protected:


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

#endif // CUSTOMIZABLETABWIDGET_h
