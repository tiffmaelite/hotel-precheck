#include "message_manager.h"
#include <QDebug>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdio>


/*!
 \brief

 \fn MessageManager::errorMessage
 \param message
 \param title
*/
void MessageManager::errorMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
        /*switch(errorMode) {
    case DEBUG:*/
        qWarning() << QObject::tr("%L1 : %L2").arg(title).arg(message);
        /*break;
    case TEST:
    case RELEASE:
        QMessageBox::critical(0,QObject::tr("%L1).arg(title),QObject::tr("%L2).arg(message));
    default:
        console.log(title+" : " + message);
    }*/
    }
}


/*!
 \brief

 \fn MessageManager::successMessage
 \param message
 \param title
*/
void MessageManager::successMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
        /*switch(errorMode) {
    case DEBUG:*/
        qDebug() << QObject::tr("%L1 : %L2").arg(title).arg(message);
        /*break;
    case TEST:
    case RELEASE:
        QMessageBox::information(0,QObject::tr("%L1).arg(title),QObject::tr("%L2).arg(message));
    default:
        console.log(title+" : " + message);
    }*/
    }
}

/*!
 \brief

 \fn MessageManager::infoMessage
 \param message
 \param title
*/
void MessageManager::infoMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
        /*switch(errorMode) {
    case DEBUG:*/
        qDebug() << QObject::tr("%L1 : %L2").arg(title).arg(message);
        /*break;
    case TEST:
    case RELEASE:
        QMessageBox::information(0,QObject::tr("%L1).arg(title),QObject::tr("%L2).arg(message));
    default:
        console.log(title+" : " + message);
    }*/
    }
}
