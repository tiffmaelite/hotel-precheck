#ifndef GENERICSTATE_H
#define GENERICSTATE_H

#include <QState>
#include "namedobject.h"

/*!
 \brief

 \class GenericState genericstate.h "logic/genericstate.h"
*/
class GenericState : public QState,NamedObject
{
    Q_OBJECT
public:
/*!
 \brief

 \fn GenericState
 \param name
 \param parent
*/
    GenericState(QString name="", QState *parent = 0);
    /*!
     \brief

     \fn toString
     \return QString
    */
    QString toString();

signals:
    /*!
     \brief

     \fn next
    */
    void next();

public slots:

private:

};

#endif // GENERICSTATE_H
