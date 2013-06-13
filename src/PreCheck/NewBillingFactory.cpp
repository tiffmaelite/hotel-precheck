#include "NewBillingFactory.h"
#include "models/database_manager.h"
#include "NewClientFactory.h"
#include <QtSql>
#include <QList>
#include <QtPrintSupport/QtPrintSupport>
#include <QtPrintSupport/QPrintEngine>
#include <QtPrintSupport/QPrinter>
#include <QPaintEngine>
#include <QPainter>
#include <QTextLayout>
#include <QTextLine>

/*!
 \brief

 \fn NewBillingFactory::NewBillingFactory
 \param parent
*/
NewBillingFactory::NewBillingFactory(QObject *parent) :
    PreCheckThread(parent)
{
    this->currentPerson = 0;
    PreCheckThread::stepsCount = 8;
    this->newClient = false;
}

/*!
 \brief

 \fn NewBillingFactory::cancelProcess
*/
void NewBillingFactory::cancelProcess()
{
    this->currentPerson = 0;
    if(this->newClient) {
        this->newClientProcess->terminate();
    }
    this->newClient = false;
    this->currentPersonOk.clear();
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

/*!
 \brief

 \fn NewBillingFactory::run
*/
void NewBillingFactory::run() {
    emit PreCheckThread::sendText(QVariant(QObject::tr("Création d'une facturation\n")));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nombre d'adultes\n")));
    PreCheckThread::currentStep++;
}

/*!
 \brief

 \fn NewBillingFactory::receiveInput
 \param text
*/
void NewBillingFactory::receiveInput(QString text) {
    text = text.trimmed();
    if(PreCheckThread::currentStep < PreCheckThread::stepsCount) {
        switch(PreCheckThread::currentStep) {
        case 1: {
            bool ok;
            int nb = text.toInt(&ok, 10);
            if(ok && nb > 0) {
                PreCheckThread::content.insert("NBADULTS",QVariant(nb));
                PreCheckThread::currentStep++;
                emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nombre d'enfants\n")));
            }
            break;
        }
        case 2: {
            bool ok;
            int nb = text.toInt(&ok, 10);
            if(ok) {
                PreCheckThread::content.insert("NBCHILDREN",nb);
                PreCheckThread::currentStep++;
                emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer la date de départ prévue\n")));
                emit displayCalendar();
            }
            break;
        }
        case 3: {
            QDate date = QDate::fromString(text);
            if(date.isValid()) {
                PreCheckThread::content.insert("EXPECTED_DEPARTURE_DATE",date.toString());
                PreCheckThread::currentStep++;
                emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le code de nationalité")));
            }
            break;
        }
        case 4: {
            int matches = AppDatabase::getInstance()->dataCount("NATIONALITIES","LABEL='"+text.toUpper()+"'");
            if (matches == 1) {
                QSqlQuery result = AppDatabase::getInstance()->execSelectQuery("SELECT ID FROM NATIONALITIES WHERE LABEL='"+text.toUpper()+"'");
                result.next();
                bool ok;
                int nat = (result.record().value(result.record().indexOf("ID"))).toInt(&ok);
                if(ok) {
                    PreCheckThread::content.insert("NATIONALITY_ID",nat);
                    emit openTab(QVariant(1));
                    PreCheckThread::currentStep++;
                    emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez choisir la chambre pour laquelle établir cette facturation")));
                }
            }
            break;
        }
        case 5: {
            int matches = AppDatabase::getInstance()->dataCount("ROOMS","NUMBER='"+text.toUpper()+"'");
            if (matches == 1) {
                QSqlQuery result = AppDatabase::getInstance()->execSelectQuery("SELECT ID FROM ROOMS WHERE NUMBER='"+text.toUpper()+"'");
                result.next();
                bool ok;
                int room = (result.record().value(result.record().indexOf("ID"))).toInt(&ok);
                if(ok) {
                    PreCheckThread::content.insert("ROOM_ID",room);
                    emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez choisir le type de facturation, puis appuyer sur la touche \"VALIDER\"")));
                    //emit displayBillingsTypes(); //radio buttons ListElement
                }
            }
            break;
        }
        case 6: {
            emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez appuyer sur la touche \"CONFIRMER\" pour confirmer les valeurs entrées et passer à l'étape suivante.")));
            break;
        }
        case 7: {
            if(this->currentPerson < 0) {
                emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nom du 1er adulte occupant la chambre,puis appuyer sur la touche \"ENTREE\"","")));
            } else if(this->currentPerson < PreCheckThread::content.value("NBADULTS").toInt()) {
                if(this->currentPersonOk.size() < this->currentPerson) {
                    QString clientName = "NAME = '%"+text+"'%";
                    for(int i =0; i < text.length(); i++) {
                        clientName += "OR NAME LIKE '"+text.left(i+1)+"%' OR NAME LIKE '%"+text.right(text.length()-(i+1))+"'";
                    }
                    int matches = AppDatabase::getInstance()->dataCount("CLIENTS",clientName);
                    if (matches == 1) {
                        QSqlQuery result = AppDatabase::getInstance()->execSelectQuery("SELECT ID FROM CLIENTS WHERE "+clientName);
                        result.next();
                        bool ok;
                        int id = (result.record().value(result.record().indexOf("ID"))).toInt(&ok);
                        if(ok) {
                            PreCheckThread::content.insert("CLIENT_ID",id);
                            this->currentPersonOk[this->currentPerson] = true;
                        }
                    } else if(matches > 1){ //clients similaires existants
                        //TODO
                        this->currentPersonOk[this->currentPerson] = false;
                    } else { //client inexistant
                        this->newClientProcess = new NewClientFactory(text);
                        this->newClientProcess->start();
                        QObject::connect(this->newClientProcess, &PreCheckThread::sendText, this, &PreCheckThread::sendText, Qt::DirectConnection);
                        QObject::connect(this, &PreCheckThread::receiveInput, this->newClientProcess, &PreCheckThread::receiveInput, Qt::DirectConnection);
                        this->newClient = this->newClientProcess->isRunning();
                        //this->newClientProcess->wait();
                    }
                } else {
                    if(this->currentPersonOk[this->currentPerson] == false) {
                    } else {
                        this->currentPerson++;
                        emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nom du %Ln(ème) adulte occupant la chambre,puis appuyer sur la touche \"ENTREE\"","",this->currentPerson+1)));
                    }
                }
            } else {
                PreCheckThread::currentStep++;
            }
            break;
        }
        case 8: {
            PreCheckThread::insertUpdateDatabase("BILLINGS");
            break;
        }
        }
    }
}

/*!
 \brief

 \fn NewBillingFactory::confirmInput
*/
void NewBillingFactory::confirmInput()
{
    if(PreCheckThread::currentStep==6) {
        PreCheckThread::currentStep++;
    }
}

/*!
 \brief

 \fn NewBillingFactory::validateInput
*/
void NewBillingFactory::validateInput()
{
    if(PreCheckThread::currentStep==5) {
        PreCheckThread::currentStep++;
    }
}


/*!
 \brief

 \fn NewBillingFactory::print
*/
void NewBillingFactory::print() {
    QPrinter* printer = new QPrinter();
    QPainter painter(printer);
    int lineHeight = 10;
    QTextLayout pageLayout;
    QString t1("prestation non encore imprimée");
    painter.drawText(0,0,printer->pageSizeMM().width(), lineHeight,Qt::AlignLeft,t1);
    painter.drawText(lineHeight,0,printer->pageSizeMM().width(), lineHeight,Qt::AlignLeft, "2ème prestation non encore imprimée");
}
