#include "user.h"

#ifndef TRAINEE_H
#define TRAINEE_H



/*!
 \brief

 \class Trainee trainee.h "models/trainee.h"
*/
class Trainee : public User
{
    Q_OBJECT
public:
/*!
 \brief

 \fn Trainee
 \param name
 \param id
 \param parent
*/
    Trainee(QString name, int id, QObject *parent = 0);
};

#endif // TRAINEE_H
