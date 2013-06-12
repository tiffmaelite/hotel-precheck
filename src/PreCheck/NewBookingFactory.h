#ifndef NEWBOOKINGFACTORY_H
#define NEWBOOKINGFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class NewBookingFactory NewBookingFactory.h "NewBookingFactory.h"
*/
class NewBookingFactory : public PreCheckThread
{
    Q_OBJECT
public:
    /*!
     \brief

     \fn NewBookingFactory
     \param parent
    */
    explicit NewBookingFactory(QObject *parent = 0);
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
    QString className() { return "NewBookingFactory"; }

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

    
};

#endif // NEWBOOKINGFACTORY_H
