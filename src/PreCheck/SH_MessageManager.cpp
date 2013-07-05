#include "SH_MessageManager.h"
#include <QDebug>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include <string>
#include <QMessageBox>

/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_MessageManager::errorMessage
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
 * \details \~french
 * \fn SH_MessageManager::debugMessage
*/
void SH_MessageManager::debugMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
//#ifdef DEBUG
    qDebug() << QObject::tr("%L1 : %L2").arg(title).arg(message);
//#endif
    }
}


/*!
 * \details \~french
 * \fn SH_MessageManager::successMessage
*/
void SH_MessageManager::successMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
#ifdef DEBUG
    qDebug() << QObject::tr("%L1 : %L2").arg(title).arg(message);
#else
    QMessageBox::information(0,QObject::tr("%L1").arg(title),QObject::tr("%L2").arg(message));
#endif
    }
}

/*!
 * \details \~french
 * \fn SH_MessageManager::infoMessage
*/
void SH_MessageManager::infoMessage(QString message, QString title)
{
    if(!message.isEmpty()) {
#ifdef DEBUG
    qDebug() << QObject::tr("%L1 : %L2").arg(title).arg(message);
#else
    QMessageBox::warning(0, QObject::tr("%L1").arg(title), QObject::tr("%L1 : %L2").arg(title).arg(message));
#endif
    }
}
/*}*/
