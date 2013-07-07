#include "SH_PrintingState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_PrintingState::PrintingState
*/
SH_PrintingState::SH_PrintingState(QString name, QState *parent) :
    SH_GenericState(name, parent), m_nbPrintedLines(0), m_currentLineNb(-1)
{
}
int SH_PrintingState::nbPrintedLines() const
{
    return m_nbPrintedLines;
}

void SH_PrintingState::setNbPrintedLines(int nbPrintedLines)
{
    m_nbPrintedLines = nbPrintedLines;
}
int SH_PrintingState::currentLineNb() const
{
    return m_currentLineNb;
}

void SH_PrintingState::setCurrentLineNb(int currentLineNb)
{
    m_currentLineNb = currentLineNb;
}


/*}*/
