#ifndef TABPAGE_H
#define TABPAGE_H


#include "fixed_grid_layout.h"
#include <QString>
#include <QtWidgets/QWidget>


/*!
 \brief

*/
class TabPage : public QWidget
{
    Q_OBJECT
public:

/*!
 \brief

 \param rows
 \param columns
 \param tabName
 \param parent
*/
    TabPage(int rows,int columns, QString tabName, QWidget *parent = 0);


    /*!
     \brief

     \return QString
    */
    QString getName();
protected:
    FixedGridLayout *tabLayout; /*!< TODO */

signals:
    
public slots:
    
protected:
    QString name; /*!< TODO */


private:
    int rowsCount; /*!< TODO */
    int columnsCount; /*!< TODO */
};

#endif // TABPAGE_H
