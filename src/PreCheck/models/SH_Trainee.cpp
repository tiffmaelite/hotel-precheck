#include "SH_Trainee.h"
#include "SH_DatabaseManager.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_Trainee::Trainee

*/
SH_Trainee::SH_Trainee(QString name, int id, QObject *parent) :
    SH_User(name, id, true, false, false, false, parent)
{

}


bool SH_Trainee::save(QString password) {
    QVariantMap map;
    if(id() > 0) {
        map.insert("ID",QVariant(this->id()));
    }
    map.insert("LOGIN",QVariant(this->name()));
    QCryptographicHash encPass(QCryptographicHash::Sha512);
    encPass.addData(password.toUtf8());
    map.insert("ENCRYPTEDPASS",QVariant(QString::fromLatin1(encPass.result().toHex()).toUpper()));

    return SH_DatabaseManager::getInstance()->execReplaceQuery("TRAINEES",map);
}
/*}*/
