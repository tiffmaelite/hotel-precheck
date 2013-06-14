#include "ThreadsManager.h"
ThreadsManager *ThreadsManager::_instance = 0; /*!< TODO */


/*!
 \brief

 \fn ThreadsManager::getInstance
 \return ThreadsManager
*/
ThreadsManager *ThreadsManager::getInstance()
{
    if (_instance == 0)
    {
        _instance = new ThreadsManager;
    }
    return _instance;
}

/*!
 \brief

 \fn ThreadsManager::ThreadsManager
*/
ThreadsManager::ThreadsManager()
{
    //this->m_runningThread = NULL;
}

/*!
 \brief

 \fn ThreadsManager::launchBillingsThread
 \return bool
*/
bool ThreadsManager::launchBillingsThread()
{
    /*if(this->m_runningThread != NULL) {
        return false;
    }
    this->m_runningThread= (PreCheckThread *)new NewBillingFactory();
    this->m_runningThread->start();
    QObject::connect(((NewBillingFactory *)this->m_runningThread), &NewBillingFactory::displayCalendar, this, &ThreadsManager::displayCalendar, Qt::DirectConnection);*/
    return this->connectRunningThread();

}

/*!
 \brief

 \fn ThreadsManager::launchBookingsThread
 \return bool
*/
bool ThreadsManager::launchBookingsThread()
{
    /*if(this->m_runningThread != NULL) {
        return false;
    }
    this->m_runningThread= (PreCheckThread *)new NewBookingFactory();
    this->m_runningThread->start();
    this->m_runningThread->start();
    QObject::connect(((NewBookingFactory *)this->m_runningThread), &NewBookingFactory::displayCalendar, this, &ThreadsManager::displayCalendar, Qt::DirectConnection);*/
    return this->connectRunningThread();
}

/*!
 \brief

 \fn ThreadsManager::launchBillThread
 \param userId
 \return bool
*/
bool ThreadsManager::launchBillThread(int userId)
{
    /*if(this->m_runningThread != NULL) {
        return false;
    }
    this->m_runningThread= (PreCheckThread *)new NewBillFactory(userId);
    this->m_runningThread->start();*/
    return this->connectRunningThread();
}

/*!
 \brief

 \fn ThreadsManager::cancelRunningThread
 \return bool
*/
bool ThreadsManager::cancelRunningThread()
{
    /*if(this->m_runningThread == NULL) {
        return true;
    }
    this->m_runningThread->cancelProcess();
    this->m_runningThread->exit();
    bool ok = this->m_runningThread->isFinished();
    this->m_runningThread = NULL;
    return ok;*/
    return true;
}

/*!
 \brief

 \fn ThreadsManager::customService
*/
void ThreadsManager::customService()
{
    /*if(this->m_runningThread != NULL && this->m_runningThread->className() == "NewBillFactory") {
        ((NewBillFactory *)this->m_runningThread)->customService();
    }*/
}

/*!
 \brief

 \fn ThreadsManager::customServiceWithoutName
*/
void ThreadsManager::customServiceWithoutName()
{
    /*if(this->m_runningThread != NULL && this->m_runningThread->className() == "NewBillFactory") {
        ((NewBillFactory *)this->m_runningThread)->customServiceWithoutName();
    }*/
}


/*!
 \brief

 \fn ThreadsManager::connectRunningThread
 \return bool
*/
bool ThreadsManager::connectRunningThread()
{
    /*if(this->m_runningThread == NULL) {
        return false;
    }
    QObject::connect(this->m_runningThread, &PreCheckThread::sendText, this, &ThreadsManager::sendText, Qt::DirectConnection);
    QObject::connect(this, &ThreadsManager::sendInput, this->m_runningThread, &PreCheckThread::receiveInput, Qt::DirectConnection);
    QObject::connect(this, &ThreadsManager::confirmInput, this->m_runningThread, &PreCheckThread::confirmInput, Qt::DirectConnection);
    QObject::connect(this, &ThreadsManager::validateInput, this->m_runningThread, &PreCheckThread::validateInput, Qt::DirectConnection);
    QObject::connect(this, &ThreadsManager::replaceInput, this->m_runningThread, &PreCheckThread::replaceInput, Qt::DirectConnection);
    QObject::connect(this, &ThreadsManager::cancelReplacement, this->m_runningThread, &PreCheckThread::cancelReplacement, Qt::DirectConnection);
    return this->m_runningThread->isRunning();*/
    return false;
}
