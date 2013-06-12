#include "errormessage.h"

void MessageManager::errorMessage(QString message)
{
    switch(errorMode) {
    case DEBUG:
        qWarning() << message;
        break;
    case TEST:
    case RELEASE:
        QMessageBox::critical(0,"Erreur",message);
    default:
        console.log(message);
    }
}

void MessageManager::successMessage(QString message)
{
    switch(errorMode) {
    case DEBUG:
        qDebug() << message;
        break;
    case TEST:
    case RELEASE:
        QMessageBox::information(0,"Réussite",message);
    default:
        console.log(message);
    }
}

QString MessageManager::parseMessage(QString message, QString values)
{
    return sprintf(message,values);
}
