#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QtWidgets/QFrame>
#include <QList>
#include <QtWidgets/QPushButton>
#include "fixed_grid_layout.h"


/*!
 \brief

*/
class Keyboard : public QWidget
{
    Q_OBJECT
public:

/*!
 \brief

 \param rowsCount
 \param columnsCount
 \param parent
*/
    Keyboard(int rowsCount,int columnsCount, QWidget *parent = 0);

    /*!
     \brief

     \param textLabel
     \param index
     \param pushable
     \param colorCode
    */
    void setButton(QString textLabel, int index, bool pushable = true, QColor *colorCode = new QColor(Qt::white));

    /*!
     \brief

     \return int
    */
    int getRowsCount();

    /*!
     \brief

     \return int
    */
    int getColumnsCount();

    /*!
     \brief

     \param left
     \param top
     \param right
     \param bottom
    */
    void setContentsMargins(int left, int top, int right, int bottom);

    /*!
     \brief

     \param spacing
    */
    void setSpacing(int spacing);

    /*!
     \brief

     \return double
    */
    double getKeysHeight();

    /*!
     \brief

     \return double
    */
    double getKeysWidth();

signals:
    
public slots:

private:
    FixedGridLayout *keysLayout; /*!< TODO */

protected:

    double maxWidth; /*!< TODO */
    double maxHeight; /*!< TODO */
    QFont *buttonsFont; /*!< TODO */


    /*!
     \brief

    */
    void resizeKeys();

    /*!
     \brief

     \return int
    */
    int getLineLength();
};

#endif // KEYBOARD_H
