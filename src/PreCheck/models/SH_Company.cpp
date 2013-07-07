#include "SH_Company.h"

/*namespace SimplHotel
{*/


SH_Company::SH_Company(QObject *parent)
{

}

bool SH_Company::setContact(SH_User* contactUser) {
    if(!bannedUsers.contains(contactUser->name())) { //-----> HERE I get compilation error "class SH_User has no member named 'name'
        //TODO
    }
    return false;
}
/*}*/
