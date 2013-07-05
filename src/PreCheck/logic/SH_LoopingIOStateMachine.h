#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "SH_IOStateMachine.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class SH_LoopingInOutStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
    Q_PROPERTY(int limit MEMBER m_limit NOTIFY limitChanged)
    Q_PROPERTY(int current MEMBER m_current NOTIFY currentChanged)
public:
/*!
 * \brief \~french
 * \fn LoopingStateMachine
 * \param tableName
 * \param limit
 * \param name
 * \param parent
*/
    SH_LoopingInOutStateMachine(QString tableName, QString name="looping", int limit=0, QObject *parent = 0);

/*!
    * \brief \~french
 * \fn setPersistentContentValue
    * \param content
    * \param field
    */
    void setPersistentContentValue(QVariant value, QString field);


/*!
    * \brief \~french
    * \fn addChildrenNextTransition
    * \param previousState
    * \param nextState
    */
    void setStatesNextTransition(QAbstractState *previousState, QAbstractState *nextState);

/*!
    * \brief \~french
    * \fn stopLooping
    */
    void stopLooping();
signals:

/*!
    * \brief \~french
    * \fn limitChanged
    */
    void limitChanged();
public slots:
private:

/*!
    * \brief \~french m_limit
    */
    int m_limit;

/*!
    * \brief \~french m_current
    */
    int m_current;

/*!
    * \brief \~french m_contents
    */
    QList<QVariantMap> m_contents;

/*!
    * \brief \~french m_persistentContent
    */
    QVariantMap m_persistentContent;
};
/*}*/
#endif /* LOOPINGSTATEMACHINE_H*/
