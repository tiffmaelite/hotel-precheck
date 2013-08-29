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
    Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged) //MEMBER m_limit
    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged) //MEMBER m_current

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

    void setLimit(int newLimit) { this->m_limit = newLimit; emit limitChanged(); }
    int limit() const { return this->m_limit; }
    void setCurrent(int current) { this->m_current = current; emit currentChanged(); }
    int current() const { return this->m_current; }

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
    void currentChanged();
public slots:
private:

/*!
    * \brief \~french this->m_limit
    */
    int m_limit;

/*!
    * \brief \~french this->m_current
    */
    int m_current;

/*!
    * \brief \~french this->m_contents
    */
    QList<QVariantMap> m_contents;

/*!
    * \brief \~french this->m_persistentContent
    */
    QVariantMap m_persistentContent;
};
/*}*/
#endif /* LOOPINGSTATEMACHINE_H*/
