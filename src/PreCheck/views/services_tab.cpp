#include "services_tab.h"
#include <QtWidgets/QWidget>
#include <QtGlobal>
#include <QDebug>
#include "keyboard.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>

ServicesTabPage::ServicesTabPage(int rowsCount, int colsCount, QString tabName, QWidget *parent) :
    TabPageWithKeys(rowsCount,colsCount, tabName, parent)
{
    initKeyboard();
}

void ServicesTabPage::fillKeyboard() {

    try {
        int colsCount = this->keys->getColumnsCount();
        QSqlTableModel keyList;
        keyList.setTable("services");
        //keyList.setFilter("codeType = " + filteringCode);
        keyList.setSort(2, Qt::AscendingOrder); // 2 <=> codeType
        keyList.select();

        int nbKeys = keyList.rowCount();
        int row = 0;
        int col = 0;
        QSqlRecord currentRow;
        for(int i = 0; i < nbKeys; ++i) {
            currentRow = keyList.record(i);
            int type = currentRow.value("codeType").toInt();
            QString text = currentRow.value("touchDisplay").toString();
            if(col >= colsCount || type > row) {
                row++;
                col = 0;
            }

            bool clickable = true;
            /*if(!PreCheckApp->isMenuOpened("bills")) { //FIXME restreindre possibilité de cliquer surs prestations affichées si pas de facturation ouverte
                int noBill = 1; //TODO faire requête pour obtenir le code pour les prestations sans facturation
                bool clickable = (type == noBill);
            }*/
            this->keys->setButton(text,row*colsCount+col, clickable);
        }
    }
    catch(std::exception &exception)
    {
        qDebug() << "pb init prestations";
    }
}
