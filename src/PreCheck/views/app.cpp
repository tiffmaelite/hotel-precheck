#include <exception>
#include <QDebug>
#include "app.h"
#include "models/rooms_table_model.h"
#include <QtWidgets/QMainWindow>



PreCheckApp::PreCheckApp(QWidget *parent) :
    QMainWindow(parent)
{
    try
    {
        //choix du mode d'exécution de l'application
        this->mode = PreCheckApp::RECEPTION;

        //création de la fenêtre de l'application
        //QtQuick2ApplicationViewer viewer;
        //QmlApplicationViewer viewer;

        //lien vers le fichier QML de la fenêtre principale de l'application
        //viewer.setMainQmlFile(QStringLiteral("$$PWD/views/qml/app.qml"));
        //viewer.setSource(QUrl("qrc:/qml/app.qml"));

        //affichage
        //viewer.show();
    }
    catch (std::exception &exception)
    {
        qDebug() << "Pb init PreCheckApp !";
    }
}


void PreCheckApp::keyPressEvent(QKeyEvent *event)
{
    try
    {
        if (event->key() == Qt::Key_Escape)
        {
            this->close();
        }
    }
    catch (std::exception &exception)
    {
        qDebug() << "ERREUR TOUCHE ECHAP !";
    }
}


/*void PreCheckApp::fill(){
    try {
        this->zoneCentrale->setMinimumSize(this->size());
        this->setCentralWidget(zoneCentrale);

        this->fillLeft();
        this->fillRight();

        this->affichage->insertWidget(0,this->leftPanel);
        this->affichage->insertWidget(1,this->middlePanel);
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckApp !";
    }
}

void PreCheckApp::fillLeft() {
    try {

        this->leftPanel = new QWidget();
        this->leftPanel->setFixedSize(this->zoneCentrale->width()/2-2*this->spacing,this->zoneCentrale->height()-2*this->spacing);
        this->leftPanel->setContentsMargins(0,0,0,0);
        double ratio = 0.5;
        FixedGridLayout *leftLayout = new FixedGridLayout(2, 1, this->leftPanel);
        this->leftPanel->setLayout(leftLayout);
        this->outputZone = new OutputZone(this->leftPanel);
        this->outputZone->setFixedHeight((this->leftPanel->height()*ratio)-leftLayout->spacing());
        QFrame *frame = new QFrame(this->leftPanel);
        frame->setContentsMargins(0,0,0,0);
        frame->setFixedSize(this->leftPanel->width()-leftLayout->spacing()-2*frame->frameWidth(),this->leftPanel->height()*ratio-leftLayout->spacing());
        frame->setFrameStyle(QFrame::Box);
        this->initKeyboard(6, 5, frame);
        leftLayout->addWidget(this->outputZone);
        leftLayout->addWidget(this->keyboard);
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckApp !";
    }
}



void PreCheckApp::fillRight() {
    try {
        int rowsCount = 10;
        int tabsHeight = (9*this->zoneCentrale->height())/(rowsCount*10);
        this->middlePanel = new CustomizableTabWidget(tabsHeight,this);
        this->middlePanel->setFixedSize(this->zoneCentrale->width()/2-2*this->spacing,this->zoneCentrale->height()-2*this->spacing);
        this->initTabs(rowsCount, 8);
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckApp !";
    }
}

void PreCheckApp::initKeyboard(int rowsCount, int columnsCount, QFrame* container) {
    try {

        this->keyboard = new Keyboard(rowsCount, columnsCount, container);
        this->keyboard->setContentsMargins(3,3,3,3);

        int colsCount = this->keys->getColumnsCount();
        QSqlTableModel keyList;
        keyList.setTable("keyboard");
        keyList.select();

        int nbKeys = keyList.rowCount();
        QSqlRecordRow currentRow;
        for(int i = 0; i < nbKeys; ++i) {
            currentRow = keyList.record(i);
            QString text = currentRow.value("label").toString();
            if(currentRow.value("isNumeric").toBoolean()) {
            this->keys->setButton(label,i,true, Qt::lightGray);
            else{
                this->keys->setButton(label,i);
            }
        }

    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb création clavier !";
    }
}


void PreCheckApp::initTabs(int rowsCount, int columnsCount) {
    try {
        switch(this->mode) {
        case PreCheckApp::CASHIER :
            this->middlePanel->setContentsMargins(0,0,0,0);

            KeyboardTabPage *fullKeyboardTab = new KeyboardTabPage(5, 10, "Clavier complet", this->middlePanel);
            ServicesTabPage *servicesTab = new ServicesTabPage(rowsCount, columnsCount, "Prestations", this->middlePanel);
            RoomsTabPage *roomsTab = new RoomsTabPage(rowsCount, columnsCount, "Chambres", this->middlePanel);
            BillsTabPage *billsTab = new BillsTabPage(rowsCount, columnsCount, "Facturations", this->middlePanel);
            BookingsTabPage *bookingsTab = new BookingsTabPage(rowsCount, columnsCount, "Réservations", this->middlePanel);

            this->middlePanel->addTab(fullKeyboardTab);
            this->middlePanel->addTab(servicesTab);
            this->middlePanel->addTab(roomsTab);
            this->middlePanel->addTab(billsTab);
            this->middlePanel->addTab(bookingsTab);

            this->middlePanel->setCurrentIndex(1);
            break;
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
    }

}*/


void PreCheckApp::centerAndResize()
{
    show();
    // get the dimension available on this screen
    /*QSize availableSize = qApp->screens()->availableGeometry().size();
        int width  = availableSize.width();
        int height = availableSize.height();
        qDebug() << "Available dimensions " << width << "x" << height;
        width  *= 0.9;   // 90% of the screen size
        height *= 0.9;  // 90% of the screen size
        qDebug() << "Computed dimensions " << width << "x" << height;
        QSize newSize( width, height );

        setGeometry(
        QStyle::alignedRect( Qt::LeftToRight,
        Qt::AlignCenter,
        newSize,
        qApp->desktop()->availableGeometry() )
        );*/

}
