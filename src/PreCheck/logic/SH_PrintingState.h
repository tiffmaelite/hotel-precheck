#ifndef PRINTINGSTATE_H
#define PRINTINGSTATE_H
#include "SH_GenericDebugableState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_PrintingState printingstate.h "logic/printingstate.h"
*/
class SH_PrintingState : public SH_GenericState
{
    Q_OBJECT
    Q_PROPERTY(int printedLines MEMBER m_nbPrintedLines NOTIFY nbPrintedLinesChanged)
    Q_PROPERTY(int currentLine MEMBER m_currentLineNb NOTIFY currentLineNbChanged)
public:
/*!
 * \brief \~french
 * \fn PrintingState
 * \param name
 * \param parent
*/
    SH_PrintingState(QString name, QState *parent = 0);
signals:

    /*!
    * \brief \~french
    * \fn printStarted
    */
    void printStarted();

    /*!
    * \brief \~french
    * \fn printFinished
    */
    void printFinished();
public slots:

private:
    int m_nbPrintedLines;
    int m_currentLineNb;
};
/*}*/
#endif /* PRINTINGSTATE_H*/
