#ifndef BILLINGSFACTORY_H
#define BILLINGSFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class NewBillingFactory NewBillingFactory.h "NewBillingFactory.h"
*/
class NewBillingFactory : public PreCheckThread
{
    Q_OBJECT
public:
/*!
 \brief

 \fn NewBillingFactory
 \param parent
*/
    NewBillingFactory(QObject *parent = 0);
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
    QString className() { return "NewBillingFactory"; }

    /*!
     \brief

     \fn print
    */
    void print();
signals:
    /*!
     \brief

     \fn displayCalendar
    */
    void displayCalendar();

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

private:
    int currentPerson; /*!< TODO */
    QList<bool> currentPersonOk; /*!< TODO */
    bool newClient; /*!< TODO */
    PreCheckThread * newClientProcess; /*!< TODO */
};

#endif // BILLINGSFACTORY_H
