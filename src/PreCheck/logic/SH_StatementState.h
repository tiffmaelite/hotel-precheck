#ifndef STATEMENTSTATE_H
#define STATEMENTSTATE_H
#include "SH_IOState.h"

/*!
\brief \~french 

 \class SH_StatementState statementstate.h "logic/statementstate.h"
*/
class SH_StatementState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn SH_StatementState
 \param output
 \param name
 \param parent
*/
    SH_StatementState(QString output, QString name, QState *parent = 0);

    /*!
    \brief \~french 

     \fn SH_setInput
     \param input
    */
    void setInput(const QVariant &input);
    /*!
    \brief \~french 

     \fn SH_onEntry
     \param event
    */
    void onEntry(QEvent *event);

signals:

public slots:

};

#endif /* STATEMENTSTATE_H*/
