#include <exception>
#include <QDebug>
#include <QtWidgets/QStatusBar>
#include <QtSql/QSqlRecord>
#include "appQtOnly.h"



PreCheckQtApp::PreCheckQtApp(QWidget *parent) :
    QMainWindow(parent)
{
    try {
        this->setWindowTitle(QObject::tr("Réception"));
        this->mode = PreCheckQtApp::RECEPTION;
        this->spacing = 5;
        this->affichage = new FixedGridLayout(1,2);
        this->affichage->setContentsMargins(this->spacing,this->spacing,this->spacing,this->spacing);
        this->affichage->setSpacing(this->spacing);
        //this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
        this->zoneCentrale = new QWidget();
        this->zoneCentrale->setLayout(this->affichage);
        //this->zoneCentrale->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

        //qWarning("hauteur de l'appli : %d, largeur de l'appli : %d", this->height(), this->width());
        //qWarning("hauteur de la zone centrale : %d, largeur de la zone centrale : %d", this->zoneCentrale->height(), this->zoneCentrale->width());

    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckQtApp !";
    }
}


void PreCheckQtApp::fill(){
    try {
        this->zoneCentrale->setMinimumSize(this->size());
        this->setCentralWidget(zoneCentrale);

        this->fillLeft();
        this->fillRight();

        this->affichage->insertWidget(0,this->leftPanel);
        this->affichage->insertWidget(1,this->middlePanel);
        //qWarning("hauteur de l'appli : %d, largeur de l'appli : %d", this->height(), this->width());
        //qWarning("hauteur de la zone centrale : %d, largeur de la zone centrale : %d", this->zoneCentrale->height(), this->zoneCentrale->width());
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckQtApp !";
    }
}

void PreCheckQtApp::fillLeft() {
    try {

        this->leftPanel = new QWidget();
        this->leftPanel->setFixedSize(this->zoneCentrale->width()/2-2*this->spacing,this->zoneCentrale->height()-2*this->spacing);
        this->leftPanel->setContentsMargins(0,0,0,0);
        double ratio = 0.5;
        //qWarning("hauteur du panel gauche : %d, largeur du panel gauche : %d", this->leftPanel->height(), this->leftPanel->width());
        FixedGridLayout *leftLayout = new FixedGridLayout(2, 1, this->leftPanel);
        this->leftPanel->setLayout(leftLayout);
        this->outputZone = new OutputZone(this->leftPanel);
        this->outputZone->setFixedHeight((this->leftPanel->height()*ratio)-leftLayout->spacing());
        //qWarning("hauteur de l'output : %d, largeur de l'output : %d, ratio : %f", this->outputZone->height(), this->outputZone->width(), ratio);
        QFrame *frame = new QFrame(this->leftPanel);
        frame->setContentsMargins(0,0,0,0);
        frame->setFixedSize(this->leftPanel->width()-leftLayout->spacing()-2*frame->frameWidth(),this->leftPanel->height()*ratio-leftLayout->spacing());
        frame->setFrameStyle(QFrame::Box);
        this->initKeyboard(6, 5, frame);
        //qWarning("hauteur de la frame du clavier : %d, largeur de la frame du clavier : %d", frame->height(), frame->width());
        //qWarning("hauteur du clavier : %d, largeur du clavier : %d", this->keyboard->height(), this->keyboard->width());
        leftLayout->addWidget(this->outputZone);
        leftLayout->addWidget(this->keyboard);
        //qWarning("hauteur de l'output : %d, largeur de l'output : %d, ratio : %f", this->outputZone->height(), this->outputZone->width(), ratio);
        //qWarning("hauteur du clavier : %d, largeur du clavier : %d", this->keyboard->height(), this->keyboard->width());
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckQtApp !";
    }
}



void PreCheckQtApp::fillRight() {
    try {
        int rowsCount = 10;
        int tabsHeight = (9*this->zoneCentrale->height())/(rowsCount*10);
        this->middlePanel = new CustomizableTabWidget(tabsHeight,this);
        this->middlePanel->setFixedSize(this->zoneCentrale->width()/2-2*this->spacing,this->zoneCentrale->height()-2*this->spacing);
        //qWarning("hauteur du panel droite : %d, largeur du panel droite : %d", this->middlePanel->height(), this->middlePanel->width());
        this->initTabs(rowsCount, 8);
    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb init PreCheckQtApp !";
    }
}


void PreCheckQtApp::keyPressEvent(QKeyEvent *event) {
    try {
        if (event->key() == Qt::Key_Escape) {
            this->close();
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR TOUCHE ECHAP !";
    }
}

void PreCheckQtApp::initKeyboard(int rowsCount, int columnsCount, QFrame* container) {
    try {

        this->keyboard = new Keyboard(rowsCount, columnsCount, container);
        //this->keyboard->setPalette(QApplication::palette(this->keyboard));
        this->keyboard->setContentsMargins(3,3,3,3);

        int colsCount = this->keyboard->getColumnsCount();
        QSqlTableModel keyList;
        keyList.setTable("keyboard");
        keyList.select();

        int nbKeys = keyList.rowCount();
        QSqlRecord currentRow;
        for(int i = 0; i < nbKeys; ++i) {
            currentRow = keyList.record(i);
            QString label = currentRow.value("label").toString();
            if(currentRow.value("isNumeric").toBool()) {
                this->keyboard->setButton(label,i,true, new QColor(Qt::lightGray));
            } else{
                this->keyboard->setButton(label,i);
            }
        }
        
        /*this->keyboard->setButton("Echap",0);
        this->keyboard->setButton("Supprimer",columnsCount);
        this->keyboard->setButton("Valider",2*columnsCount);
        this->keyboard->setButton("Annuler",3*columnsCount);
        this->keyboard->setButton("TVA 0%",4);
        this->keyboard->setButton("TVA 3.8%",columnsCount+4);
        this->keyboard->setButton("+",1, Qt::lightGray);
        this->keyboard->setButton("-",2, Qt::lightGray);
        this->keyboard->setButton("x",3, Qt::lightGray);
        this->keyboard->setButton("1",columnsCount+1, Qt::lightGray);
        this->keyboard->setButton("2",columnsCount+2, Qt::lightGray);
        this->keyboard->setButton("3",columnsCount+3, Qt::lightGray);
        this->keyboard->setButton("4",2*columnsCount+1, Qt::lightGray);
        this->keyboard->setButton("5",2*columnsCount+2, Qt::lightGray);
        this->keyboard->setButton("6",2*columnsCount+3, Qt::lightGray);
        this->keyboard->setButton("7",3*columnsCount+1, Qt::lightGray);
        this->keyboard->setButton("8",3*columnsCount+2, Qt::lightGray);
        this->keyboard->setButton("9",3*columnsCount+3, Qt::lightGray);
        this->keyboard->setButton("00",4*columnsCount+1, Qt::lightGray);
        this->keyboard->setButton("0",4*columnsCount+2, Qt::lightGray);
        this->keyboard->setButton(",",4*columnsCount+3, Qt::lightGray);*/

    }
    catch(std::exception &exception)
    {
        qDebug() << "Pb création clavier !";
    }
}


void PreCheckQtApp::initTabs(int rowsCount, int columnsCount) {
    try {
        switch(this->mode) {
        case PreCheckQtApp::RECEPTION :
            this->middlePanel->setContentsMargins(0,0,0,0);

            KeyboardTabPage *fullKeyboardTab = new KeyboardTabPage(5, 10, QObject::tr("Clavier complet"), this->middlePanel);
            ServicesTabPage *servicesTab = new ServicesTabPage(rowsCount, columnsCount, QObject::tr("Prestations"), this->middlePanel);
            RoomsTabPage *roomsTab = new RoomsTabPage(rowsCount, columnsCount, QObject::tr("Chambres"), this->middlePanel);
            BillingsTabPage *billsTab = new BillingsTabPage(rowsCount, columnsCount, QObject::tr("Facturations"), this->middlePanel);
            BookingsTabPage *bookingsTab = new BookingsTabPage(rowsCount, columnsCount, QObject::tr("Réservations"), this->middlePanel);

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

}

void PreCheckQtApp::centerAndResize(){
    show();
    // get the dimension available on this screen
    /*QSize availableSize = qApp->desktop()->availableGeometry().size();
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
