#include "tab_page_with_keys.h"
#include <QtWidgets/QWidget>
#include <QList>
#include <QtWidgets/QPushButton>

#ifndef SERVICESTAB_H
#define SERVICESTAB_H

/*!
 \brief

*/
class ServicesTabPage : public TabPageWithKeys
{
    Q_OBJECT
public:

/*!
 \brief

 \param rowsCount
 \param columnsCount
 \param tabName
 \param parent
*/
    ServicesTabPage(int rowsCount,int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

protected:

    /*!
     \brief

    */
    void fillKeyboard();
};

#endif // SERVICESTAB_H
