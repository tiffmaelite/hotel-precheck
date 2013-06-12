#include "namedobject.h"

NamedObject::NamedObject(QString name) :
    m_name(name)
{
    //m_ptraddress = QString(&this);
}

QString NamedObject::toString()
{
    return this->m_name;
}

QString NamedObject::name() const
{
    return m_name;
}

void NamedObject::setName(const QString &name)
{
    m_name = name;
}

QString NamedObject::ptraddress() const
{
    return m_ptraddress;
}
