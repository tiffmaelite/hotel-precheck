#ifndef CAISSE_H
#define CAISSE_H

#include <QtGui>
#include <QKeyEvent>
#include "fixed_grid_layout.h"
#include "services_tab.h"
#include "rooms_tab.h"
#include "billings_tab.h"
#include "bookings_tab.h"
#include "keyboard_tab.h"
#include "customizable_tab_widget.h"
#include "output_zone.h"
#include <QtWidgets/QMainWindow>


/*!
 \brief

*/
class PreCheckQtApp : public QMainWindow
{

    Q_OBJECT
    Q_ENUMS(AppMode)

public:

    /*!
     \brief

    */
    enum AppMode { RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };

/*!
 \brief

 \param parent
*/
    PreCheckQtApp(QWidget *parent = 0);

    /*!
     \brief

    */
    void fill();

    /*!
     \brief

     \param event
    */
    void keyPressEvent(QKeyEvent *event);

    /*!
     \brief

    */
    void centerAndResize();

    CustomizableTabWidget *middlePanel; /*!< TODO */
    QWidget *leftPanel; /*!< TODO */

protected:

    /*!
     \brief

    */
    void fillLeft();

    /*!
     \brief

    */
    void fillRight();

    /*!
     \brief

     \param rowsCount
     \param columnsCount
     \param container
    */
    void initKeyboard(int rowsCount, int columnsCount, QFrame* container);

    /*!
     \brief

     \param rowsCount
     \param columnsCount
    */
    void initTabs(int rowsCount, int columnsCount);

    FixedGridLayout *affichage; /*!< TODO */
    RoomsTabPage *roomsTab; /*!< TODO */

    OutputZone *outputZone; /*!< TODO */
    Keyboard *keyboard; /*!< TODO */
    QWidget *zoneCentrale; /*!< TODO */

private:
    double spacing; /*!< TODO */
    PreCheckQtApp::AppMode mode; /*!< TODO */
};


#endif // CAISSE_H
