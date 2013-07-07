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
    Q_PROPERTY(int printedLines READ nbPrintedLines WRITE setNbPrintedLines NOTIFY nbPrintedLinesChanged) //MEMBER m_nbPrintedLines
    Q_PROPERTY(int currentLine READ currentLineNb WRITE setCurrentLineNb NOTIFY currentLineNbChanged) //MEMBER m_currentLineNb
public:
/*!
 * \brief \~french
 * \fn PrintingState
 * \param name
 * \param parent
*/
    SH_PrintingState(QString name, QState *parent = 0);
    int nbPrintedLines() const;
    void setNbPrintedLines(int nbPrintedLines);

    int currentLineNb() const;
    void setCurrentLineNb(int currentLineNb);

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
signals:
    void nbPrintedLinesChanged();
    void currentLineNbChanged();

private:
    int m_nbPrintedLines;
    int m_currentLineNb;
};
/*}*/
#endif /* PRINTINGSTATE_H*/
