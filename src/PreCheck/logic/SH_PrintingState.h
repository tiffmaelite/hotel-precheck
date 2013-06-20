#ifndef PRINTINGSTATE_H
#define PRINTINGSTATE_H
#include "SH_GenericDebugableState.h"

/*!
 \brief

 \class PrintingState printingstate.h "logic/printingstate.h"
*/
class SH_PrintingState : public SH_GenericState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn PrintingState
 \param name
 \param parent
*/
    SH_PrintingState(QString name, QState *parent = 0);

signals:
    /*!
     \brief

     \fn printStarted
    */
    void printStarted();
    /*!
     \brief

     \fn printFinished
    */
    void printFinished();

public slots:

};

#endif // PRINTINGSTATE_H
