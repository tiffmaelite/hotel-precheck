#include "NewBillFactory.h"
#include "models/database_manager.h"
#include <QtSql>

NewBillFactory::NewBillFactory(int receptionistId, int billId, QObject *parent) :
    PreCheckThread(parent)
{
    PreCheckThread::stepsCount = 3;
    PreCheckThread::content.insert("BILL_ID", billId);
    PreCheckThread::content.insert("RECEPTIONIST_ID", receptionistId);
}

void NewBillFactory::cancelProcess()
{
    this->currentStep = 0;
    this->currentServiceMinPrice = 0;
    this->currentServiceMaxPrice = 0;
    PreCheckThread::content.empty();
}

void NewBillFactory::run() {

}

void NewBillFactory::receiveInput(QString text) {
    text = text.trimmed();
    if(PreCheckThread::currentStep < PreCheckThread::stepsCount) {
        switch(PreCheckThread::currentStep) {
        case 0: {
            bool ok;
            int sId = text.toInt(&ok, 10);
            if(ok) {
                int matches = AppDatabase::getInstance()->dataExists("SERVICES",QString("ID='%1'").arg(QString::number(sId)));
                if (matches == 1) {
                    QSqlQuery result = AppDatabase::getInstance()->execQuery("SELECT ISAVAILABLE, ROOMNEEDED, PRICE1, PRICE2 FROM SERVICES JOIN SERVICESTYPES ON SERVICES.TYPE_ID = SERVICESTYPES.ID WHERE SERVICES.ID="+sId);
                    result.next();
                    QSqlRecord rec = result.record();
                    bool available = (rec.value(rec.indexOf("AVAILABLE"))).toBool();
                    if(available) {
                        bool roomNeeded = ((rec.value(rec.indexOf("ROOMNEEDED")).toString()) == "1");
                        if((PreCheckThread::content.value("BILL_ID") != 0) || !roomNeeded) {
                            PreCheckThread::content.insert("SERVICE_ID", QVariant(sId));
                            this->currentServiceMinPrice = (rec.value(rec.indexOf("PRICE1"))).toDouble();
                            this->currentServiceMaxPrice = (rec.value(rec.indexOf("PRICE2"))).toDouble();
                            PreCheckThread::currentStep++;
                            emit PreCheckThread::sendText(QVariant(QObject::tr("Le prix habituel de cette prestation est de %1 (son prix maximum est de %2). Pour conserver le prix habituel, appuyez sur la touche \"CONFIRMER\". Sinon, entrez le prix désiré puis appuyez sur la touche \"ENTRÉE\".").arg(this->currentServiceMinPrice).arg(this->currentServiceMaxPrice)));
                        } else {
                            emit PreCheckThread::sendText(QVariant(QObject::tr("Cette prestation ne peut être facturée en vente seule (en dehors d'une facturation avec chambre).")));
                        }
                    } else {
                        emit PreCheckThread::sendText(QVariant(QObject::tr("Cette prestation n'est pas disponible actuellement")));
                    }
                }
            }
        }
        case 1: {
            bool ok;
            double price = text.toDouble(&ok);
            if(ok && price >= 0) {
                PreCheckThread::content.insert("CHARGEDUNITYPRICE", price);
                PreCheckThread::currentStep++;
            }
        }
        case 2: {
            if(text.left(1).toUpper() == QObject::tr("X") || text.left(1) == QObject::tr("*")) {
                bool ok;
                int mult = text.right(-1).toInt(&ok, 10);
                if(ok && mult > 0) {
                    PreCheckThread::content.insert("QUANTITY", QVariant(mult));
                }
            }
        }
        }
    }
}

void NewBillFactory::customService()
{
    //TODO
    PreCheckThread::currentStep = 1;
}

void NewBillFactory::customServiceWithoutName()
{
    //TODO
    PreCheckThread::currentStep = 1;
}

void NewBillFactory::confirmInput()
{
    if(PreCheckThread::currentStep==1) {
        PreCheckThread::content.insert("CHARGEDUNITYPRICE", QVariant(this->currentServiceMinPrice));
        PreCheckThread::currentStep=2;
    }
}

void NewBillFactory::validateInput()
{
    if(!PreCheckThread::content.value("QUANTITY").isValid()) {
        PreCheckThread::content.insert("QUANTITY", QVariant(1));
    }
    PreCheckThread::currentStep = 3;
    PreCheckThread::insertUpdateDatabase("CHARGEDSERVICES");
}
