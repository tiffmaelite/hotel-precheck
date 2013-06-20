#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "SH_IOStateMachine.h"

/*!
 \brief

 \class SH_LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class Sh_LoopingInOutStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
    Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)

public:
/*!
 \brief

 \fn SH_LoopingStateMachine
 \param tableName
 \param limit
 \param name
 \param parent
*/
    Sh_LoopingInOutStateMachine(QString tableName, QString name="looping", int limit=0, QObject *parent = 0);

    /*!
     \brief

     \fn SH_current
     \return int
    */
    int current() const;
    /*!
     \brief

     \fn SH_setCurrent
     \param current
    */
    void setCurrent(int current);

    /*!
     \brief

     \fn SH_setPersistentContentValue
     \param content
     \param field
    */
    void setPersistentContentValue(QVariant value, QString field);

    /*!
     \brief

     \fn SH_limit
     \return int
    */
    int limit() const;
    /*!
     \brief

     \fn SH_setLimit
     \param limit
    */
    void setLimit(int limit);

    /*!
     \brief
     \fn SH_addChildrenNextTransition TODO comment this
     \param previousState TODO comment this
     \param nextState TODO comment this
    */
    void addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState);
    /*!
     \brief
     \fn SH_stopLooping TODO comment this
    */
    void stopLooping();
signals:
    /*!
     \brief
     \fn SH_limitChanged TODO comment this
    */
    void limitChanged();

public slots:

private:
    /*!
     * \brief m_limit
     */
    int m_limit;
    /*!
     * \brief m_current
     */
    int m_current;
    /*!
     * \brief m_contents
     */
    QList<QVariantMap> m_contents;
    /*!
     * \brief m_persistentContent
     */
    QVariantMap m_persistentContent;
};

#endif /* LOOPINGSTATEMACHINE_H*/
