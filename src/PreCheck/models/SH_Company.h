#include <QtSql/QSqlRelationalTableModel>
#ifndef COMPANY_H
#define COMPANY_H
#include "SH_User.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_Company
\headerfile company.h "models/company.h"
*/
class SH_Company : public QObject
{
    Q_OBJECT
public:
    explicit SH_Company(QObject* parent = 0);
    bool setContact(SH_User* contactUser);
private:
    QStringList bannedUsers;
};
/*}*/
#endif /* COMPANY_H*/
