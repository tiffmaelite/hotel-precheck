#ifndef PRINTINGSTATE_H
#define PRINTINGSTATE_H
#include "SH_GenericDebugableState.h"

/*!
\brief \~french 

 \class SH_PrintingState printingstate.h "logic/printingstate.h"
*/
class SH_PrintingState : public SH_GenericState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn SH_PrintingState
 \param name
 \param parent
*/
    SH_PrintingState(QString name, QState *parent = 0);

signals:
    /*!
    \brief \~french 

     \fn SH_printStarted
    */
    void printStarted();
    /*!
    \brief \~french 

     \fn SH_printFinished
    */
    void printFinished();

public slots:

};

#endif /* PRINTINGSTATE_H*/
