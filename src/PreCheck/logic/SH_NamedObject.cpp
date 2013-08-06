#include "SH_NamedObject.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_NamedObject::NamedObject
*/
SH_NamedObject::SH_NamedObject(QString name) :
    m_name(name)
{

    /*m_ptraddress = QString(&this);*/
}
/*!
 * \details \~french
 * \fn SH_NamedObject::toString
*/
QString SH_NamedObject::toString()
{
    return this->m_name;
}
/*!
 * \details \~french
 * \fn SH_NamedObject::name
*/
QString SH_NamedObject::name() const
{
    return this->m_name;
}
/*!
 * \details \~french
 * \fn SH_NamedObject::setName
*/
void SH_NamedObject::setName(const QString &name)
{
    this->m_name = name;
}
/*!
 * \details \~french
 * \fn SH_NamedObject::ptraddress
*/
QString SH_NamedObject::ptraddress() const
{
    return this->m_ptraddress;
}
/*}*/
