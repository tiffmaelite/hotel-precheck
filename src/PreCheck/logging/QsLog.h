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

#ifndef QSLOG_H
#define QSLOG_H

#include "QsLogLevel.h"
#include "QsLogDest.h"
#include <QDebug>
#include <QString>

#define QS_LOG_VERSION "2.0b1"

namespace QsLogging
{
class Destination;
class LoggerImpl; /* d pointer  */

/*!
\brief \~french

 \class SH_Logger
 \headerfile QsLog.h "logging/QsLog.h"
*/
class Logger
{
public:
    /*!
    \brief \~french
     \fn instance
     \return Logger
    */
    static Logger& instance()
    {
        static Logger staticLog;
        return staticLog;
    }

    /*!
    \brief \~french  Adds a log message destination. Don't add null destinations.
     \fn addDestination
     \param destination
    */
    void addDestination(DestinationPtr destination);

    /*!
    \brief \~french  Logging at a level < 'newLevel' will be ignored
     \fn setLoggingLevel
     \param newLevel
    */
    void setLoggingLevel(Level newLevel);

    /*!
    \brief \~french  The default level is INFO
     \fn loggingLevel
     \return Level
    */
    Level loggingLevel() const;

    /*!
    \brief \~french  The helper forwards the streaming to QDebug and builds the final log message.
     \class SH_Helper
    \headerfile QsLog.h "logging/QsLog.h"
    */
    class Helper
    {
    public:
        /*!
        \brief \~french
         \fn Helper
         \param logLevel
        */
        explicit Helper(Level logLevel) :
            level(logLevel),
            qtDebug(&buffer) {}

        /*!
        \brief \~french
         \fn ~Helper
        */
        ~Helper();

        /*!
        \brief \~french
         \fn stream
         \return QDebug
        */
        QDebug& stream(){ return qtDebug; }

    private:
        /*!
        \brief \~french
         \fn writeToLog
        */
        void writeToLog();

        /*!
         *\brief \~french  level
         */
        Level level;

        /*!
         *\brief \~french  buffer
         */
        QString buffer;

        /*!
         *\brief \~french  qtDebug
         */
        QDebug qtDebug;
    };

private:
    /*!
\brief \~french
  \fn Logger
*/
    Logger();

    /*!
\brief \~french
 \fn Logger
 \param
*/
    Logger(const Logger&);

    /*!
    \brief \~french
     \fn operator =
     \param
     \return Logger &operator
    */
    Logger& operator=(const Logger&);

    /*!
    \brief \~french
     \fn ~Logger
    */
    ~Logger();

    /*!
    \brief \~french
     \fn enqueueWrite
     \param message
     \param level
    */
    void enqueueWrite(const QString& message, Level level);

    /*!
    \brief \~french
     \fn write
     \param message
     \param level
    */
    void write(const QString& message, Level level);

    /*!
     * \var d
     */
    LoggerImpl* d;
    friend class LogWriterRunnable;
};

} /* end namespace */

/* Logging macros: define QS_LOG_LINE_NUMBERS to get the file and line number
    in the log output. */
#ifndef QS_LOG_LINE_NUMBERS
#define QLOG_TRACE() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::TraceLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::TraceLevel).stream()
#define QLOG_DEBUG() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::DebugLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::DebugLevel).stream()
#define QLOG_INFO()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::InfoLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::InfoLevel).stream()
#define QLOG_WARN()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::WarnLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::WarnLevel).stream()
#define QLOG_ERROR() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::ErrorLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::ErrorLevel).stream()
#define QLOG_FATAL() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::FatalLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::FatalLevel).stream()
#else
#define QLOG_TRACE() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::TraceLevel) {} \
    else  QsLogging::Logger::Helper(QsLogging::TraceLevel).stream() << __FILE__ << '@' << __LINE__
#define QLOG_DEBUG() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::DebugLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::DebugLevel).stream() << __FILE__ << '@' << __LINE__
#define QLOG_INFO()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::InfoLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::InfoLevel).stream() << __FILE__ << '@' << __LINE__
#define QLOG_WARN()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::WarnLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::WarnLevel).stream() << __FILE__ << '@' << __LINE__
#define QLOG_ERROR() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::ErrorLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::ErrorLevel).stream() << __FILE__ << '@' << __LINE__
#define QLOG_FATAL() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::FatalLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::FatalLevel).stream() << __FILE__ << '@' << __LINE__
#endif

#ifdef QS_LOG_DISABLE
#include "QsLogDisableForThisFile.h"
#endif

#endif /* QSLOG_H  */
