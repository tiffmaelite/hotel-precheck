#include "SH_User.h"

#ifndef TRAINEE_H
#define TRAINEE_H


/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_Trainee
\headerfile trainee.h "models/trainee.h"
*/
class SH_Trainee : public SH_User
{
    Q_OBJECT
public:
/*!
\brief \~french

 \fn SH_Trainee
 \param name
 \param id
 \param parent
*/
    SH_Trainee(QString name, int id = 0, QObject *parent = 0);
    bool save(QString password);
};
/*}*/
#endif /* TRAINEE_H*/
