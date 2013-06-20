/* Copyright (c) 2013, Razvan Petru*/
/* All rights reserved.*/

/* Redistribution and use in source and binary forms, with or without modification,*/
/* are permitted provided that the following conditions are met:*/

/* * Redistributions of source code must retain the above copyright notice, this*/
/*   list of conditions and the following disclaimer.*/
/* * Redistributions in binary form must reproduce the above copyright notice, this*/
/*   list of conditions and the following disclaimer in the documentation and/or other*/
/*   materials provided with the distribution.*/
/* * The name of the contributors may not be used to endorse or promote products*/
/*   derived from this software without specific prior written permission.*/

/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND*/
/* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED*/
/* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.*/
/* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,*/
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,*/
/* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,*/
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF*/
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE*/
/* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED*/
/* OF THE POSSIBILITY OF SUCH DAMAGE.*/

#ifndef QSLOGDESTFILE_H
#define QSLOGDESTFILE_H

#include "QsLogDest.h"
#include <QFile>
#include <QTextStream>
#include <QtGlobal>
#include <QSharedPointer>

namespace QsLogging
{
/*!
 * \brief The RotationStrategy class
 */
class RotationStrategy
{
public:
    /*!
     * \brief ~RotationStrategy
     */
    virtual ~RotationStrategy();
    /*!
     * \brief setInitialInfo
     * \param file
     */
    virtual void setInitialInfo(const QFile &file) = 0;
    /*!
     * \brief includeMessageInCalculation
     * \param message
     */
    virtual void includeMessageInCalculation(const QString &message) = 0;
    /*!
     * \brief shouldRotate
     * \return
     */
    virtual bool shouldRotate() = 0;
    /*!
     * \brief rotate
     */
    virtual void rotate() = 0;
    /*!
     * \brief recommendedOpenModeFlag
     * \return
     */
    virtual QIODevice::OpenMode recommendedOpenModeFlag() = 0;
};

/* Never rotates file, overwrites existing file.*/
/*!
 * \brief The NullRotationStrategy class
 */
class NullRotationStrategy : public RotationStrategy
{
public:
    /*!
     * \brief setInitialInfo
     */
    virtual void setInitialInfo(const QFile &) {}
    /*!
     * \brief includeMessageInCalculation
     */
    virtual void includeMessageInCalculation(const QString &) {}
    /*!
     * \brief shouldRotate
     * \return
     */
    virtual bool shouldRotate() { return false; }
    /*!
     * \brief rotate
     */
    virtual void rotate() {}
    /*!
     * \brief recommendedOpenModeFlag
     * \return
     */
    virtual QIODevice::OpenMode recommendedOpenModeFlag() { return QIODevice::Truncate; }
};

/* Rotates after a size is reached, keeps a number of <= 10 backups, appends to existing file.*/
/*!
 * \brief The SizeRotationStrategy class
 */
class SizeRotationStrategy : public RotationStrategy
{
public:
    /*!
     * \brief SizeRotationStrategy
     */
    SizeRotationStrategy();
    /*!
     * \brief MaxBackupCount
     */
    static const int MaxBackupCount;
    /*!
     * \brief setInitialInfo
     * \param file
     */
    virtual void setInitialInfo(const QFile &file);
    /*!
     * \brief includeMessageInCalculation
     * \param message
     */
    virtual void includeMessageInCalculation(const QString &message);
    /*!
     * \brief shouldRotate
     * \return
     */
    virtual bool shouldRotate();
    /*!
     * \brief rotate
     */
    virtual void rotate();
    /*!
     * \brief recommendedOpenModeFlag
     * \return
     */
    virtual QIODevice::OpenMode recommendedOpenModeFlag();
    /*!
     * \brief setMaximumSizeInBytes
     * \param size
     */
    void setMaximumSizeInBytes(qint64 size);
    /*!
     * \brief setBackupCount
     * \param backups
     */
    void setBackupCount(int backups);

private:
    /*!
     * \brief mFileName
     */
    QString mFileName;
    /*!
     * \brief mCurrentSizeInBytes
     */
    qint64 mCurrentSizeInBytes;
    /*!
     * \brief mMaxSizeInBytes
     */
    qint64 mMaxSizeInBytes;
    /*!
     * \brief mBackupsCount
     */
    int mBackupsCount;
};
/*!
 * \brief RotationStrategyPtr
 */
typedef QSharedPointer<RotationStrategy> RotationStrategyPtr;

/* file message sink*/
/*!
 * \brief The FileDestination class
 */
class FileDestination : public Destination
{
public:
    /*!
     * \brief FileDestination
     * \param filePath
     * \param rotationStrategy
     */
    FileDestination(const QString& filePath, RotationStrategyPtr rotationStrategy);
    /*!
     * \brief write
     * \param message
     * \param level
     */
    virtual void write(const QString& message, Level level);
    /*!
     * \brief isValid
     * \return
     */
    virtual bool isValid();

private:
    /*!
     * \brief mFile
     */
    QFile mFile;
    /*!
     * \brief mOutputStream
     */
    QTextStream mOutputStream;
    /*!
     * \brief mRotationStrategy
     */
    QSharedPointer<RotationStrategy> mRotationStrategy;
};

}

#endif /* QSLOGDESTFILE_H*/
