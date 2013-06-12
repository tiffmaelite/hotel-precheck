#ifndef PRINTINGSTATE_H
#define PRINTINGSTATE_H
#include "genericstate.h"

/*!
 \brief

 \class PrintingState printingstate.h "logic/printingstate.h"
*/
class PrintingState : public GenericState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn PrintingState
 \param name
 \param parent
*/
    PrintingState(QString name, QState *parent = 0);

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
