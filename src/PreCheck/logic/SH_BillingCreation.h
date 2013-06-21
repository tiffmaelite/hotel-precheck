#ifndef BILLINGCREATIONSTATEMACHINE_H
#define BILLINGCREATIONSTATEMACHINE_H
#include "SH_IOStateMachine.h"
/*!
 *\brief \~french  The SH_BillingCreationStateMachine class
 */
class SH_BillingCreationStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
public:
    /*!
     *\brief \~french  SH_BillingCreationStateMachine
     * \param name
     * \param parent
     */
    SH_BillingCreationStateMachine(QString name, QObject *parent = 0);

signals:

public slots:

};

#endif /* BILLINGCREATIONSTATEMACHINE_H*/
