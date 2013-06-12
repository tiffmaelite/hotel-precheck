#include "tab_page_with_keys.h"
#include <QtWidgets/QWidget>
#include <QList>
#include <QtWidgets/QPushButton>

#ifndef KEYBOARDTAB_H
#define KEYBOARDTAB_H


/*!
 \brief

*/
class KeyboardTabPage : public TabPageWithKeys
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
    KeyboardTabPage(int rowsCount, int columnsCount, QString tabName, QWidget *parent = 0);
    
signals:
    
public slots:

protected:

    /*!
     \brief

    */
    void fillKeyboard();
};

#endif // KEYBOARDTAB_H
