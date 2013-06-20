#include "SH_User.h"

#ifndef TRAINEE_H
#define TRAINEE_H



/*!
 \brief

 \class SH_Trainee
\headerfile trainee.h "models/trainee.h"
*/
class SH_Trainee : public SH_User
{
    Q_OBJECT
public:
/*!
 \brief

 \fn SH_Trainee
 \param name
 \param id
 \param parent
*/
    SH_Trainee(QString name, int id, QObject *parent = 0);
};

#endif /* TRAINEE_H*/
