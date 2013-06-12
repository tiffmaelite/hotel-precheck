#ifndef NAMEDOBJECT_H
#define NAMEDOBJECT_H
#include <QString>

class NamedObject
{
public:
    NamedObject(QString name);
    virtual QString toString();

    virtual QString name() const;
    virtual void setName(const QString &name);

    QString ptraddress() const;

private:
    QString m_name;
    QString m_ptraddress;
};

#endif // NAMEDOBJECT_H
