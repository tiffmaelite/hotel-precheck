#include "BillingsFactory.h"
#include "models/database_manager.h"
#include "QtSql"

BillingsFactory::BillingsFactory(QObject *parent) :
    PreCheckThread(parent)
{
    this->currentPerson = 0;
    PreCheckThread::stepsCount = 8;
}

void BillingsFactory::cancelProcess()
{
    this->currentPerson = 0;
    this->currentStep = 0;
    PreCheckThread::content.empty();
}

void BillingsFactory::run() {
    emit PreCheckThread::sendText(QVariant(QObject::tr("Création d'une facturation\n")));
    emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nombre d'adultes\n")));
}

void BillingsFactory::receiveInput(QString text) {
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
                //emit displayCalendar();
            }
            break;
        }
        case 3: {
            emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le code de nationalité")));
            break;
        }
        case 4: {
            emit openTab(2);
            emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez choisir la chambre pour laquelle établir cette facturation")));
            break;
        }
        case 5: {
            emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez choisir le type de facturation, puis appuyer sur la touche \"VALIDER\"")));
            //emit displayBillingsTypes(); //radio buttons ListElement
            break;
        }
        case 6: {
            emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez appuyer sur la touche \"CONFIRMER\" pour confirmer les valeurs entrées et passer à l'étape suivante.")));
            break;
        }
        case 7: {
            if(this->currentPerson < PreCheckThread::content.value("NBADULTS").toInt()) {
                emit PreCheckThread::sendText(QVariant(QObject::tr("Veuillez entrer le nom du %Ln(ème) adulte occupant la chambre,puis appuyer sur la touche \"ENTREE\"","",currentPerson)));
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
