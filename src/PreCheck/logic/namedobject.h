#ifndef NAMEDOBJECT_H
#define NAMEDOBJECT_H
#include <QString>

/*!
 \brief

 \class NamedObject namedobject.h "logic/namedobject.h"
*/
class NamedObject
{
public:
/*!
 \brief

 \fn NamedObject
 \param name
*/
    NamedObject(QString name);
    /*!
     \brief

     \fn toString
     \return QString
    */
    virtual QString toString();

    /*!
     \brief

     \fn name
     \return QString
    */
    virtual QString name() const;
    /*!
     \brief

     \fn setName
     \param name
    */
    virtual void setName(const QString &name);

    /*!
     \brief

     \fn ptraddress
     \return QString
    */
    QString ptraddress() const;

private:
    QString m_name; /*!< TODO */
    QString m_ptraddress; /*!< TODO */
};

#endif // NAMEDOBJECT_H
