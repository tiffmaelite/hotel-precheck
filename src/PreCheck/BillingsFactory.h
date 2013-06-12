#ifndef BILLINGSFACTORY_H
#define BILLINGSFACTORY_H

#include <QObject>
#include <QThread>
#include "PreCheckThread.h"

class BillingsFactory : public PreCheckThread
{
    Q_OBJECT
public:
    BillingsFactory(QObject *parent = 0);
void cancelProcess();
signals:
    
public slots:
    void receiveInput(QString text);

protected:
    void run();

private:
    int currentPerson;
};

#endif // BILLINGSFACTORY_H
