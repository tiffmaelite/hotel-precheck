#include "user.h"
#include "trainee.h"
#include "database_manager.h"
#include <QSqlRecord>
#include <QtCore>
#include <QCryptographicHash>
#include <QDebug>


/*!
 \brief

 \fn User::User
 \param name
 \param id
 \param isReceptionist
 \param isManagerX
 \param isManagerZ
 \param isAdministrator
 \param parent
*/
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

/*!
 \brief

 \fn User::isValid
 \return bool
*/
bool User::isValid() const {
    return ((!this->m_name.isEmpty()) && (this->m_id != 0));
}

/*!
 \brief

 \fn User::setName
 \param name
*/
void User::setName(QString name)
{
    m_name = name;
}


/*!
 \brief

 \fn User::name
 \return QString
*/
QString User::name() const
{
    return m_name;
}

/*!
 \brief

 \fn User::isReceptionist
 \return bool
*/
bool User::isReceptionist() const
{
    return this->m_receptionist;
}

/*!
 \brief

 \fn User::roles
 \return int
*/
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

/*!
 \brief

 \fn User::setID
 \param id
*/
void User::setID(int id)
{
    m_id = id;
}

/*!
 \brief

 \fn User::userExists
 \param login
 \return bool
*/
bool User::userExists(QString login) {
    qDebug() << "user exists";
    return (AppDatabase::getInstance()->dataCount("USERS", "LOGIN='"+login+"'") == 1);
}

/*!
 \brief

 \fn User::traineeExists
 \param login
 \return bool
*/
bool User::traineeExists(QString login) {
    qDebug() << "trainee exists";
    return (AppDatabase::getInstance()->dataCount("TRAINEES", "LOGIN='"+login+"'") == 1);
}

/*!
 \brief

 \fn User::logIn
 \param login
 \param pass
 \return User
*/
User *User::logIn(QString login, QString pass)
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
    QSqlQuery result = AppDatabase::getInstance()->execSelectQuery(table,fields,"WHERE LOGIN='"+login+"' AND ENCRYPTEDPASS='"+QString::fromLatin1(encPass.result().toHex()).toUpper()+"'");
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



