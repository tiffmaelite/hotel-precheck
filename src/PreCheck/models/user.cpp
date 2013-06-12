#include "user.h"
#include "trainee.h"
#include "database_manager.h"
#include <QSqlRecord>
#include <QtCore>
#include <QCryptographicHash>
#include <QDebug>


User::User(QString name, int id, bool isReceptionist, bool isManagerX, bool isManagerZ, bool isAdministrator, QObject *parent)
    : QObject(parent)
{
    this->setName(name);
    this->setID(id);
    this->m_receptionist = isReceptionist;
    this->m_managerX = isManagerX;
    this->m_managerZ = isManagerZ;
    this->m_administrator = isAdministrator;
}

bool User::isValid() const {
    return ((!this->m_name.isEmpty()) && (this->m_id != 0));
}

void User::setName(QString name)
{
    m_name = name;
}


QString User::name() const
{
    return m_name;
}

bool User::isReceptionist() const
{
    return this->m_receptionist;
}

int User::roles() const
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

void User::setID(int id)
{
    m_id = id;
}

bool User::userExists(QString login) {
    return (AppDatabase::getInstance()->dataExists("USERS", "LOGIN='"+login+"'") == 1);
}

bool User::traineeExists(QString login) {
    return false;
    //return (AppDatabase::getInstance()->dataExists("TRAINEE", "LOGIN='"+login+"'") == 1);
}

User *User::logIn(QString login, QString pass)
{
    bool isValid = false;
    QCryptographicHash encPass(QCryptographicHash::Sha512);
    encPass.addData(pass.toUtf8());
    bool trainee=false;
    QString query;
    if(userExists(login)) {
        query = "SELECT ID, LOGIN, ISRECEPTIONIST, ISMANAGERX, ISMANAGERZ, ISADMINISTRATOR FROM USERS WHERE LOGIN='"+login+"' AND ENCRYPTEDPASS='"+QString::fromLatin1(encPass.result().toHex()).toUpper()+"'";
    } else if(traineeExists(login)) {
        query="SELECT ID, LOGIN FROM USERS WHERE LOGIN='"+login+"' AND ENCRYPTEDPASS='"+QString::fromLatin1(encPass.result().toHex()).toUpper()+"'";
        trainee=true;
    }
    QSqlQuery result = AppDatabase::getInstance()->getDbConnection().exec(query);
    if(result.next()) {
        QSqlRecord rec = result.record();
        if(rec.isEmpty() || !result.isValid()) {
            isValid = false;
        } else {
            isValid = (rec.value(rec.indexOf("LOGIN")).toString() == login);
        }

        if(isValid) {
            if(trainee) {
                return new Trainee(rec.value(rec.indexOf("LOGIN")).toString(),rec.value(rec.indexOf("ID")).toInt());
            } else {
                return new User(rec.value(rec.indexOf("LOGIN")).toString(),rec.value(rec.indexOf("ID")).toInt(),(rec.value(rec.indexOf("ISRECEPTIONIST")).toString()=="1"),(rec.value(rec.indexOf("ISMANAGERX")).toString()=="1"),(rec.value(rec.indexOf("ISMANAGERZ")).toString()=="1"),(rec.value(rec.indexOf("ISADMINISTRATOR")).toString()=="1"));
            }
        }
    }
    return new User();
}



