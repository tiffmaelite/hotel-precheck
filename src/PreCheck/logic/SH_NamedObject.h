#ifndef NAMEDOBJECT_H
#define NAMEDOBJECT_H
#include <QString>

/*!
\brief \~french 

 \class SH_NamedObject namedobject.h "logic/namedobject.h"
*/
class SH_NamedObject
{
public:
/*!
\brief \~french 

 \fn SH_NamedObject
 \param name
*/
    SH_NamedObject(QString name);
    /*!
    \brief \~french 

     \fn SH_toString
     \return QString
    */
    virtual QString toString();

    /*!
    \brief \~french 

     \fn SH_name
     \return QString
    */
    virtual QString name() const;
    /*!
    \brief \~french 

     \fn SH_setName
     \param name
    */
    virtual void setName(const QString &name);

    /*!
    \brief \~french 

     \fn SH_ptraddress
     \return QString
    */
    QString ptraddress() const;

private:
    /*!
     *\brief \~french  m_name
     */
    QString m_name;
    /*!
     *\brief \~french  m_ptraddress
     */
    QString m_ptraddress;
};

#endif /* NAMEDOBJECT_H*/
