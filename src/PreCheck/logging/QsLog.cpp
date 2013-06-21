/* Copyright (c) 2013, Razvan Petru
*/
/* All rights reserved.
*/

/* Redistribution and use in source and binary forms, with or without modification,
*/
/* are permitted provided that the following conditions are met:
*/

/* Redistributions of source code must retain the above copyright notice, this
*/
/*   list of conditions and the following disclaimer.
*/
/* Redistributions in binary form must reproduce the above copyright notice, this
*/
/*   list of conditions and the following disclaimer in the documentation and/or other
*/
/*   materials provided with the distribution.
*/
/* The name of the contributors may not be used to endorse or promote products
*/
/*   derived from this software without specific prior written permission.
*/

/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
*/
/* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
*/
/* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*/
/* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
*/
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*/
/* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*/
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*/
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
*/
/* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
*/
/* OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "QsLog.h"
#include "QsLogDest.h"
#ifdef QS_LOG_SEPARATE_THREAD
#include <QThreadPool>
#include <QRunnable>
#else
#include <QMutex>
#endif
#include <QVector>
#include <QDateTime>
#include <QtGlobal>
#include <cassert>
#include <cstdlib>
#include <stdexcept>

namespace QsLogging
{
/*!
 * \typedef DestinationList
 */
typedef QVector<DestinationPtr> DestinationList;
/*!
 * \var TraceString
 */
static const char TraceString[] = "TRACE";
/*!
 * \var DebugString
 */
static const char DebugString[] = "DEBUG";
/*!
 * \var InfoString
 */
static const char InfoString[]  = "INFO";
/*!
 * \var WarnString
 */
static const char WarnString[]  = "WARN";
/*!
 * \var ErrorString
 */
static const char ErrorString[] = "ERROR";
/*!
 * \var FatalString
 */
static const char FatalString[] = "FATAL";

/*!
 * \var fmtDateTime
 * \details \~french not using Qt::ISODate because we need the milliseconds too
 */
static const QString fmtDateTime("yyyy-MM-ddThh:mm:ss.zzz");
/*!
 * \fn SH_LevelToText
 * \param theLevel
 * \return
 */
static const char* LevelToText(Level theLevel)
{
    switch (theLevel) {
    case TraceLevel:
        return TraceString;
    case DebugLevel:
        return DebugString;
    case InfoLevel:
        return InfoString;
    case WarnLevel:
        return WarnString;
    case ErrorLevel:
        return ErrorString;
    case FatalLevel:
        return FatalString;
    case OffLevel:
        return "";
    default: {
        assert(!"bad log level");
        return InfoString;
    }
    }
}

#ifdef QS_LOG_SEPARATE_THREAD
/*!
 * \class SH_The LogWriterRunnable class
 */
class LogWriterRunnable : public QRunnable
{
public:
    /*!
     * \fn SH_LogWriterRunnable
     * \param message
     * \param level
     */
    LogWriterRunnable(const QString &message, Level level)
        : mMessage(message)
        , mLevel(level) {}
    /*!
     * \fn SH_run
     */
    virtual void run()
    {
        Logger::instance().write(mMessage, mLevel);
    }

private:
    /*!
     * \property mMessage
     */
    QString mMessage;
    /*!
     * \property mLevel
     */
    Level mLevel;
};
#endif
/*!
 * \class SH_The LoggerImpl class
 */
class LoggerImpl
{
public:
    /*!
     * \fn SH_LoggerImpl
     */
    LoggerImpl() :
        level(InfoLevel)
    {
        /* assume at least file + console */
        destList.reserve(2);
#ifdef QS_LOG_SEPARATE_THREAD
        threadPool.setMaxThreadCount(1);
        threadPool.setExpiryTimeout(-1);
#endif
    }
#ifdef QS_LOG_SEPARATE_THREAD
    QThreadPool threadPool;
#else
    /*!
     * \property logMutex
     */
    QMutex logMutex;
#endif
    /*!
     * \property level
     */
    Level level;
    /*!
     * \property destList
     */
    DestinationList destList;
};
/*!
 * \fn SH_Logger::Logger
 */
Logger::Logger() :
    d(new LoggerImpl)
{
}
/*!
 * \fn SH_Logger::~Logger
 */
Logger::~Logger()
{
    delete d;
}
/*!
 * \fn SH_Logger::addDestination
 */
void Logger::addDestination(DestinationPtr destination)
{
    assert(destination.data());
    d->destList.push_back(destination);
}
/*!
 * \fn SH_Logger::setLoggingLevel
 */
void Logger::setLoggingLevel(Level newLevel)
{
    d->level = newLevel;
}
/*!
 * \fn SH_Logger::loggingLevel
 */
Level Logger::loggingLevel() const
{
    return d->level;
}

/*!
 * \fn SH_Logger::Helper::writeToLog
 * \details \~french creates the complete log message and passes it to the logger
 */
void Logger::Helper::writeToLog()
{
    const char* const levelName = LevelToText(level);
    const QString completeMessage(QString("%1 %2 %3")
                                  .arg(levelName, 5)
                                  .arg(QDateTime::currentDateTime().toString(fmtDateTime))
                                  .arg(buffer)
                                  );

    Logger::instance().enqueueWrite(completeMessage, level);
}
/*!
 * \fn SH_Logger::Helper::~Helper
 */
Logger::Helper::~Helper()
{
    try {
        writeToLog();
    }
    catch(std::exception&) {
        /* you shouldn't throw exceptions from a sink */
        assert(!"exception in logger helper destructor");
        throw;
    }
}


/*!
 * \fn SH_Logger::enqueueWrite
 * \details \~french directs the message to the task queue or writes it directly
 */
void Logger::enqueueWrite(const QString& message, Level level)
{
#ifdef QS_LOG_SEPARATE_THREAD
    LogWriterRunnable *r = new LogWriterRunnable(message, level);
    d->threadPool.start(r);
#else
    QMutexLocker lock(&d->logMutex);
    write(message, level);
#endif
}


/*!
 * \fn SH_Logger::write
 * \details \~french Sends the message to all the destinations. The level for this message is passed in case it's useful for processing in the destination.
 */
void Logger::write(const QString& message, Level level)
{
    for (DestinationList::iterator it = d->destList.begin(),
         endIt = d->destList.end();it != endIt;++it) {
        (*it)->write(message, level);
    }
}

} /* end namespace
*/
