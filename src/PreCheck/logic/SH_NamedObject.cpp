#include "SH_NamedObject.h"

/*!
 \brief

 \fn NamedObject::NamedObject
 \param name
*/
SH_NamedObject::SH_NamedObject(QString name) :
    m_name(name)
{
    //m_ptraddress = QString(&this);
}

/*!
 \brief

 \fn NamedObject::toString
 \return QString
*/
QString SH_NamedObject::toString()
{
    return this->m_name;
}

/*!
 \brief

 \fn NamedObject::name
 \return QString
*/
QString SH_NamedObject::name() const
{
    return m_name;
}

/*!
 \brief

 \fn NamedObject::setName
 \param name
*/
void SH_NamedObject::setName(const QString &name)
{
    m_name = name;
}

/*!
 \brief

 \fn NamedObject::ptraddress
 \return QString
*/
QString SH_NamedObject::ptraddress() const
{
    return m_ptraddress;
}
