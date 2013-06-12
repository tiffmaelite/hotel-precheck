#include "namedobject.h"

/*!
 \brief

 \fn NamedObject::NamedObject
 \param name
*/
NamedObject::NamedObject(QString name) :
    m_name(name)
{
    //m_ptraddress = QString(&this);
}

/*!
 \brief

 \fn NamedObject::toString
 \return QString
*/
QString NamedObject::toString()
{
    return this->m_name;
}

/*!
 \brief

 \fn NamedObject::name
 \return QString
*/
QString NamedObject::name() const
{
    return m_name;
}

/*!
 \brief

 \fn NamedObject::setName
 \param name
*/
void NamedObject::setName(const QString &name)
{
    m_name = name;
}

/*!
 \brief

 \fn NamedObject::ptraddress
 \return QString
*/
QString NamedObject::ptraddress() const
{
    return m_ptraddress;
}
