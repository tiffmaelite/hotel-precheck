#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "SH_IOStateMachine.h"

/*!
\brief \~french 

 \class SH_LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class Sh_LoopingInOutStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
    Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)

public:
/*!
\brief \~french 

 \fn SH_LoopingStateMachine
 \param tableName
 \param limit
 \param name
 \param parent
*/
    Sh_LoopingInOutStateMachine(QString tableName, QString name="looping", int limit=0, QObject *parent = 0);

    /*!
    \brief \~french 

     \fn SH_current
     \return int
    */
    int current() const;
    /*!
    \brief \~french 

     \fn SH_setCurrent
     \param current
    */
    void setCurrent(int current);

    /*!
    \brief \~french 

     \fn SH_setPersistentContentValue
     \param content
     \param field
    */
    void setPersistentContentValue(QVariant value, QString field);

    /*!
    \brief \~french 

     \fn SH_limit
     \return int
    */
    int limit() const;
    /*!
    \brief \~french 

     \fn SH_setLimit
     \param limit
    */
    void setLimit(int limit);

    /*!
    \brief \~french 
     \fn SH_addChildrenNextTransition TODO comment this
     \param previousState TODO comment this
     \param nextState TODO comment this
    */
    void addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState);
    /*!
    \brief \~french 
     \fn SH_stopLooping TODO comment this
    */
    void stopLooping();
signals:
    /*!
    \brief \~french 
     \fn SH_limitChanged TODO comment this
    */
    void limitChanged();

public slots:

private:
    /*!
     *\brief \~french  m_limit
     */
    int m_limit;
    /*!
     *\brief \~french  m_current
     */
    int m_current;
    /*!
     *\brief \~french  m_contents
     */
    QList<QVariantMap> m_contents;
    /*!
     *\brief \~french  m_persistentContent
     */
    QVariantMap m_persistentContent;
};

#endif /* LOOPINGSTATEMACHINE_H*/
