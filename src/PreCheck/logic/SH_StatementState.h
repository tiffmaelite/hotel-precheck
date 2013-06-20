#ifndef STATEMENTSTATE_H
#define STATEMENTSTATE_H
#include "SH_IOState.h"

/*!
 \brief

 \class StatementState statementstate.h "logic/statementstate.h"
*/
class SH_StatementState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn StatementState
 \param output
 \param name
 \param parent
*/
    SH_StatementState(QString output, QString name, QState *parent = 0);

    /*!
     \brief

     \fn setInput
     \param input
    */
    void setInput(const QVariant &input);
    /*!
     \brief

     \fn onEntry
     \param event
    */
    void onEntry(QEvent *event);

signals:

public slots:

};

#endif // STATEMENTSTATE_H
