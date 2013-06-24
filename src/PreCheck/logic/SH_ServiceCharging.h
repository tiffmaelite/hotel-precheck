#ifndef SERVICECHARGING_H
#define SERVICECHARGING_H
#include "SH_LoopingIOStateMachine.h"

/*!
 *\brief \~french  The SH_ServiceCharging class
 */
class SH_ServiceCharging : public SH_LoopingInOutStateMachine
{
    Q_OBJECT
public:
    /*!
     *\brief \~french  SH_ServiceCharging
     * \param name
     * \param parent
     */
    SH_ServiceCharging(QString name, QObject *parent = 0);

signals:

public slots:

private:
    /*!
     *\brief \~french  m_priceMin
     */
    qreal m_priceMin;
    /*!
     *\brief \~french  m_vat
     */
    qreal m_vat;

};

#endif /* SERVICECHARGING_H*/
