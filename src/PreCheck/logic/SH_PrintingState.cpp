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
    return this->m_nbPrintedLines;
}

void SH_PrintingState::setNbPrintedLines(int nbPrintedLines)
{
    this->m_nbPrintedLines = nbPrintedLines;
}
int SH_PrintingState::currentLineNb() const
{
    return this->m_currentLineNb;
}

void SH_PrintingState::setCurrentLineNb(int currentLineNb)
{
    this->m_currentLineNb = currentLineNb;
}


/*}*/
