#ifndef SERVICECHARGING_H
#define SERVICECHARGING_H
#include "SH_LoopingIOStateMachine.h"

/*!
 * \brief The SH_ServiceCharging class
 */
class SH_ServiceCharging : public Sh_LoopingInOutStateMachine
{
    Q_OBJECT
public:
    /*!
     * \brief SH_ServiceCharging
     * \param name
     * \param parent
     */
    SH_ServiceCharging(QString name, QObject *parent = 0);

signals:

public slots:

private:
    /*!
     * \brief m_priceMin
     */
    qreal m_priceMin;
    /*!
     * \brief m_vat
     */
    qreal m_vat;

};

#endif /* SERVICECHARGING_H*/
