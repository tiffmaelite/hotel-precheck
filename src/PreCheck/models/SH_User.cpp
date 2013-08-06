#include <QSqlRecord>
#include <QtCore>
#include <QCryptographicHash>
#include <QDebug>
#include "SH_MessageManager.h"
#include "SH_User.h"
#include "SH_Trainee.h"
#include "SH_DatabaseManager.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_User::User

*/
SH_User::SH_User(QString name, int id, bool isReceptionist, bool isManagerX, bool isManagerZ, bool isAdministrator, QObject *parent)
    : QObject(parent), m_id(0), m_receptionist(isReceptionist), m_managerX(isManagerX), m_managerZ(isManagerZ), m_administrator(isAdministrator)
{
    this->setName(name);
    this->setID(id);

    connect(this, &SH_User::receptionistChanged, this, &SH_User::rolesChanged);
    connect(this, &SH_User::managerXChanged, this, &SH_User::rolesChanged);
    connect(this, &SH_User::managerZChanged, this, &SH_User::rolesChanged);
    connect(this, &SH_User::administratorChanged, this, &SH_User::rolesChanged);
}

/*!
 \details \~french

 \fn SH_User::isValid

*/
bool SH_User::isValid() const {
    return ((!this->m_name.isEmpty()) && (this->m_id != 0));
}

/*!
 \details \~french

 \fn SH_User::setName

*/
void SH_User::setName(QString name)
{
    this->m_name = name;
}

/*!
 \details \~french

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
 \details \~french

 \fn SH_User::setID

*/
void SH_User::setID(int id)
{
    this->m_id = id;
}

/*!
 \details \~french

 \fn SH_User::userExists

*/
bool SH_User::userExists(QString login) {
    SH_MessageManager::debugMessage("user exists");
    return (SH_DatabaseManager::getInstance()->dataCount("USERS", "LOGIN='"+login+"'") == 1);
}

/*!
 \details \~french

 \fn SH_User::traineeExists

*/
bool SH_User::traineeExists(QString login) {
    SH_MessageManager::debugMessage("trainee exists");
    return (SH_DatabaseManager::getInstance()->dataCount("TRAINEES", "LOGIN='"+login+"'") == 1);
}


bool SH_User::save(QString password) {
    QVariantMap map;
    if(id() > 0) {
        map.insert("ID",QVariant(this->id()));
    }
    map.insert("LOGIN",QVariant(this->name()));
    map.insert("ISRECEPTIONIST",QVariant(this->isReceptionist()));
    map.insert("ISMANAGERX",QVariant(this->isManagerX()));
    map.insert("ISMANAGERZ",QVariant(this->isManagerZ()));
    map.insert("ISADMINISTRATOR",QVariant(this->isAdministrator()));
    QCryptographicHash encPass(QCryptographicHash::Sha512);
    encPass.addData(password.toUtf8());
    map.insert("ENCRYPTEDPASS",QVariant(QString::fromLatin1(encPass.result().toHex()).toUpper()));

    return SH_DatabaseManager::getInstance()->execReplaceQuery("USERS",map);
}

bool SH_User::setNewPassword(QString newPass) {
    return this->save(newPass);
}

/*!
 \details \~french

 \fn SH_User::logIn

*/
SH_User *SH_User::logIn(QString login, QString pass)
{
    SH_MessageManager::debugMessage("log in");
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
                return new SH_User(rec.value(rec.indexOf("LOGIN")).toString(),rec.value(rec.indexOf("ID")).toInt(),(rec.value(rec.indexOf("ISRECEPTIONIST")).toBool()),(rec.value(rec.indexOf("ISMANAGERX")).toBool()),(rec.value(rec.indexOf("ISMANAGERZ")).toBool()),(rec.value(rec.indexOf("ISADMINISTRATOR")).toBool()));
            }
        }
    }
    return new SH_User();
}
/*}*/
