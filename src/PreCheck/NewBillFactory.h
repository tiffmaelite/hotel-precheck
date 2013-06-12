#ifndef NEWBILLFACTORY_H
#define NEWBILLFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class NewBillFactory NewBillFactory.h "NewBillFactory.h"
*/
class NewBillFactory : public PreCheckThread
{
    Q_OBJECT
public:
    /*!
     \brief

     \fn NewBillFactory
     \param receptionistId
     \param billId
     \param parent
    */
    explicit NewBillFactory(int receptionistId, int billId = 0, QObject *parent = 0);
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
    QString className() { return "NewBillFactory"; }

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

     \fn customService
    */
    void customService();
    /*!
     \brief

     \fn customServiceWithoutName
    */
    void customServiceWithoutName();
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
    double currentServiceMinPrice; /*!< TODO */
    double currentServiceMaxPrice; /*!< TODO */
};

#endif // NEWBILLFACTORY_H
