#include "SH_MessageManager.h"
#include <QDebug>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string>
#include <QMessageBox>

/*!
 \details \~french

 \fn SH_MessageManager::errorMessage
*/
void SH_MessageManager::errorMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
#ifdef DEBUG
        qWarning() << QObject::tr("%L1 : %L2").arg(title).arg(message);
#else
        QMessageBox::critical(0,QObject::tr("%L1").arg(title),QObject::tr("%L2").arg(message));
#endif
    }
}


/*!
 \details \~french

 \fn SH_MessageManager::successMessage
*/
void SH_MessageManager::successMessage(QString message, QString title)
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
 \details \~french

 \fn SH_MessageManager::infoMessage
*/
void SH_MessageManager::infoMessage(QString message, QString title)
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
