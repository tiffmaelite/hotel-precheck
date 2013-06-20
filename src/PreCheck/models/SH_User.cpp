#include <QSqlRecord>
#include <QtCore>
#include <QCryptographicHash>
#include <QDebug>
#include "SH_User.h"
#include "SH_Trainee.h"
#include "SH_DatabaseManager.h"

/*!
 \details

 \fn SH_User::User

*/
SH_User::SH_User(QString name, int id, bool isReceptionist, bool isManagerX, bool isManagerZ, bool isAdministrator, QObject *parent)
    : QObject(parent)
{
    this->setName(name);
    this->setID(id);
    this->m_receptionist = isReceptionist;
    this->m_managerX = isManagerX;
    this->m_managerZ = isManagerZ;
    this->m_administrator = isAdministrator;
}

/*!
 \details

 \fn SH_User::isValid

*/
bool SH_User::isValid() const {
    return ((!this->m_name.isEmpty()) && (this->m_id != 0));
}

/*!
 \details

 \fn SH_User::setName

*/
void SH_User::setName(QString name)
{
    m_name = name;
}


/*!
 \details

 \fn SH_User::name
 */
QString SH_User::name() const
{
    return m_name;
}

/*!
 \details

 \fn SH_User::isReceptionist

*/
bool SH_User::isReceptionist() const
{
    return this->m_receptionist;
}

/*!
 \details

 \fn SH_User::roles

*/
int SH_User::roles() const
{
    int nb = 0;
    if(this->isReceptionist()) {
        nb++;
    }
    if(this->isManagerX()) {
        nb++;
    }
    if(this->isManagerZ()) {
        nb++;
    }
    if(this->isAdministrator()) {
        nb++;
    }
    return nb;
}

/*!
 \details

 \fn SH_User::setID

*/
void SH_User::setID(int id)
{
    m_id = id;
}

/*!
 \details

 \fn SH_User::userExists

*/
bool SH_User::userExists(QString login) {
    qDebug() << "user exists";
    return (SH_DatabaseManager::getInstance()->dataCount("USERS", "LOGIN='"+login+"'") == 1);
}

/*!
 \details

 \fn SH_User::traineeExists

*/
bool SH_User::traineeExists(QString login) {
    qDebug() << "trainee exists";
    return (SH_DatabaseManager::getInstance()->dataCount("TRAINEES", "LOGIN='"+login+"'") == 1);
}

/*!
 \details

 \fn SH_User::logIn

*/
SH_User *SH_User::logIn(QString login, QString pass)
{
    qDebug() << "log in";
    bool isValid = false;
    QCryptographicHash encPass(QCryptographicHash::Sha512);
    encPass.addData(pass.toUtf8());
    bool trainee=false;
    QStringList fields;
    QString table;
    if(userExists(login)) {
        fields << "ID" << "LOGIN" << "ISRECEPTIONIST" << "ISMANAGERX" << "ISMANAGERZ" << "ISADMINISTRATOR";
        table ="USERS";
    } else if(traineeExists(login)) {
        fields << "ID" << "LOGIN";
        table ="TRAINEES";
        trainee=true;
    }
    QSqlQuery result = SH_DatabaseManager::getInstance()->execSelectQuery(table,fields,"LOGIN='"+login+"' AND ENCRYPTEDPASS='"+QString::fromLatin1(encPass.result().toHex()).toUpper()+"'");
    if(result.next()) {
        QSqlRecord rec = result.record();
        if(rec.isEmpty() || !result.isValid()) {
            isValid = false;
        } else {
            isValid = (rec.value(rec.indexOf("LOGIN")).toString() == login);
        }

        if(isValid) {
            if(trainee) {
                return new SH_Trainee(rec.value(rec.indexOf("LOGIN")).toString(),rec.value(rec.indexOf("ID")).toInt());
            } else {
                return new SH_User(rec.value(rec.indexOf("LOGIN")).toString(),rec.value(rec.indexOf("ID")).toInt(),(rec.value(rec.indexOf("ISRECEPTIONIST")).toString()=="1"),(rec.value(rec.indexOf("ISMANAGERX")).toString()=="1"),(rec.value(rec.indexOf("ISMANAGERZ")).toString()=="1"),(rec.value(rec.indexOf("ISADMINISTRATOR")).toString()=="1"));
            }
        }
    }
    return new SH_User();
}


