#ifndef PRECHECKTHREAD_H
#define PRECHECKTHREAD_H

#include <QThread>
#include <QMap>
#include <QVariant>

/*!
 \brief

 \class PreCheckThread PreCheckThread.h "PreCheckThread.h"
*/
class PreCheckThread : public QThread
{
    Q_OBJECT
public:
/*!
 \brief

 \fn PreCheckThread
 \param parent
*/
    PreCheckThread(QObject *parent = 0);
    /*!
     \brief

     \fn cancelProcess
    */
    virtual void cancelProcess() = 0;
    /*!
     \brief

     \fn className
     \return QString
    */
    virtual QString className() = 0;
    /*!
     \brief

     \fn insertUpdateDatabase
     \param tableName
     \return bool
    */
    bool insertUpdateDatabase(QString tableName);
    
signals:
    /*!
     \brief

     \fn sendText
     \param text
    */
    void sendText(QVariant text);
    /*!
     \brief

     \fn openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);

public slots:
    /*!
     \brief

     \fn receiveInput
     \param text
    */
    virtual void receiveInput(QString text) = 0;
    /*!
     \brief

     \fn confirmInput
    */
    virtual void confirmInput() = 0;
    /*!
     \brief

     \fn validateInput
    */
    virtual void validateInput() = 0;
    /*!
     \brief

     \fn replaceInput
     \param field
    */
    void replaceInput(QString field);
    /*!
     \brief

     \fn cancelReplacement
    */
    void cancelReplacement();

protected:
    QVariantMap content; /*!< TODO */
    int stepsCount; /*!< TODO */
    int currentStep; /*!< TODO */
    QString toBeReplaced; /*!< TODO */
};

#endif // PRECHECKTHREAD_H
