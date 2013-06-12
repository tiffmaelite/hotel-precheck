#ifndef BILLINGFACTORY_H
#define BILLINGFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class BillingFactory BillingFactory.h "BillingFactory.h"
*/
class BillingFactory : public PreCheckThread
{
    Q_OBJECT
public:
    /*!
     \brief

     \fn BillingFactory
     \param parent
    */
    explicit BillingFactory(QObject *parent = 0);
    /*!
     \brief

     \fn cancelProcess
    */
    void cancelProcess();
    /*!
     \brief

     \fn className
     \return QString
    */
    QString className() { return "BillingFactory"; }

signals:

public slots:
    /*!
     \brief

     \fn receiveInput
     \param text
    */
    void receiveInput(QString text);
    /*!
     \brief

     \fn confirmInput
    */
    void confirmInput();
    /*!
     \brief

     \fn validateInput
    */
    void validateInput();


protected:
    /*!
     \brief

     \fn run
    */
    void run();

};

#endif // BILLINGFACTORY_H
