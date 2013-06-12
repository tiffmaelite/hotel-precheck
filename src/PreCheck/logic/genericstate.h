#ifndef GENERICSTATE_H
#define GENERICSTATE_H

#include <QState>
#include "namedobject.h"

class GenericState : public QState,NamedObject
{
    Q_OBJECT
public:
    GenericState(QString name="", QState *parent = 0);
    QString toString();

signals:
    void next();

public slots:

private:

};

#endif // GENERICSTATE_H
