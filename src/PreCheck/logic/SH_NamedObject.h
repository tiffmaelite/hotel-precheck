#ifndef NAMEDOBJECT_H
#define NAMEDOBJECT_H
#include <QString>

/*!
 \brief

 \class SH_NamedObject namedobject.h "logic/namedobject.h"
*/
class SH_NamedObject
{
public:
/*!
 \brief

 \fn SH_NamedObject
 \param name
*/
    SH_NamedObject(QString name);
    /*!
     \brief

     \fn SH_toString
     \return QString
    */
    virtual QString toString();

    /*!
     \brief

     \fn SH_name
     \return QString
    */
    virtual QString name() const;
    /*!
     \brief

     \fn SH_setName
     \param name
    */
    virtual void setName(const QString &name);

    /*!
     \brief

     \fn SH_ptraddress
     \return QString
    */
    QString ptraddress() const;

private:
    /*!
     * \brief m_name
     */
    QString m_name;
    /*!
     * \brief m_ptraddress
     */
    QString m_ptraddress;
};

#endif /* NAMEDOBJECT_H*/
