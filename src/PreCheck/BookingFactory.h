#ifndef BOOKINGFACTORY_H
#define BOOKINGFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class BookingFactory BookingFactory.h "BookingFactory.h"
*/
class BookingFactory : public PreCheckThread
{
    Q_OBJECT
public:
    /*!
     \brief

     \fn BookingFactory
     \param parent
    */
    explicit BookingFactory(QObject *parent = 0);
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
    QString className() { return "BookingFactory"; }

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

#endif // BOOKINGFACTORY_H
