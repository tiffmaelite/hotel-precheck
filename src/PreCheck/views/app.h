#ifndef PRECHECKAPP_H
#define PRECHECKAPP_H

#include <QtGui>
#include <QKeyEvent>
#include <QtWidgets/QMainWindow>



class PreCheckApp : public QMainWindow
{

        Q_OBJECT
        Q_ENUMS(AppMode)

    public:

        enum AppMode { RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };



        PreCheckApp(QWidget *parent = 0);


        void keyPressEvent(QKeyEvent *event);

        void centerAndResize();
        /*void fill();
        CustomizableTabWidget *middlePanel;
        QWidget *leftPanel;*/

    protected:
        /*void fillLeft();
        void fillRight();
        void initKeyboard(int rowsCount, int columnsCount, QFrame* container);
        void initTabs(int rowsCount, int columnsCount);

        FixedGridLayout *affichage;
        RoomsTabPage *roomsTab;

        OutputZone *outputZone;
        Keyboard *keyboard;
        QWidget *zoneCentrale;*/

    private:
        /*double spacing;*/
        PreCheckApp::AppMode mode;
};


#endif // PRECHECKAPP_H
