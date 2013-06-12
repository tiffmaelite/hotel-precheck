#ifndef NEWCLIENTFACTORY_H
#define NEWCLIENTFACTORY_H
#include <QObject>
#include <QThread>
#include <QList>
#include "PreCheckThread.h"

/*!
 \brief

 \class NewClientFactory NewClientFactory.h "NewClientFactory.h"
*/
class NewClientFactory : public PreCheckThread
{
    Q_OBJECT
public:
/*!
 \brief

 \fn NewClientFactory
 \param name
 \param parent
*/
    NewClientFactory(QString name, QObject *parent = 0);
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
    QString className() { return "NewClientFactory"; }

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

#endif // NEWCLIENTFACTORY_H
