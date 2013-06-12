#ifndef THREADSMANAGER_H
#define THREADSMANAGER_H
#include <QThread>
#include <QObject>
#include "PreCheckThread.h"

/*!
 \brief

 \class ThreadsManager ThreadsManager.h "ThreadsManager.h"
*/
class ThreadsManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(PreCheckThread* runningThread READ runningThread NOTIFY runningThreadChanged)
public:
    /*!
     \brief

     \fn getInstance
     \return ThreadsManager
    */
    static ThreadsManager *getInstance();
/*!
 \brief

 \fn ThreadsManager
*/
    ThreadsManager();
    /*!
     \brief

     \fn runningThread
     \return PreCheckThread
    */
    PreCheckThread* runningThread() const { return m_runningThread; }

public slots:
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

     \fn launchBookingsThread
     \return bool
    */
    bool launchBookingsThread();
    /*!
     \brief

     \fn launchBillThread
     \param userId
     \return bool
    */
    bool launchBillThread(int userId);
    /*!
     \brief

     \fn launchBillingsThread
     \return bool
    */
    bool launchBillingsThread();
    /*!
     \brief

     \fn cancelRunningThread
     \return bool
    */
    bool cancelRunningThread();

signals:
    /*!
     \brief

     \fn runningThreadChanged
    */
    void runningThreadChanged();
    /*!
     \brief

     \fn sendText
     \param text
    */
    void sendText(QVariant text);
    /*!
     \brief

     \fn displayCalendar
    */
    void displayCalendar();
    /*!
     \brief

     \fn openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);
    /*!
     \brief

     \fn sendInput
     \param inputText
    */
    void sendInput(QString inputText);
    /*!
     \brief

     \fn validateInput
    */
    void validateInput();
    /*!
     \brief

     \fn confirmInput
    */
    void confirmInput();
    /*!
     \brief

     \fn replaceInput
     \param inputName
    */
    void replaceInput(QString inputName);
    /*!
     \brief

     \fn cancelReplacement
    */
    void cancelReplacement();

private:
    /*!
     \brief

     \fn connectRunningThread
     \return bool
    */
    bool connectRunningThread();
    PreCheckThread* m_runningThread; /*!< TODO */
    static ThreadsManager *_instance; /*!< TODO */
};

#endif // THREADSMANAGER_H
