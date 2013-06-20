#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "SH_IOStateMachine.h"

/*!
 \brief

 \class LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class Sh_LoopingInOutStateMachine : public SH_InOutStateMachine
{
    Q_OBJECT
    Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)

public:
/*!
 \brief

 \fn LoopingStateMachine
 \param tableName
 \param limit
 \param name
 \param parent
*/
    Sh_LoopingInOutStateMachine(QString tableName, QString name="looping", int limit=0, QObject *parent = 0);

    /*!
     \brief

     \fn current
     \return int
    */
    int current() const;
    /*!
     \brief

     \fn setCurrent
     \param current
    */
    void setCurrent(int current);

    /*!
     \brief

     \fn setPersistentContentValue
     \param content
     \param field
    */
    void setPersistentContentValue(QVariant value, QString field);

    /*!
     \brief

     \fn limit
     \return int
    */
    int limit() const;
    /*!
     \brief

     \fn setLimit
     \param limit
    */
    void setLimit(int limit);

    /*!
     \brief
     \fn addChildrenNextTransition TODO comment this
     \param previousState TODO comment this
     \param nextState TODO comment this
    */
    void addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState);
    /*!
     \brief
     \fn stopLooping TODO comment this
    */
    void stopLooping();
signals:
    /*!
     \brief
     \fn limitChanged TODO comment this
    */
    void limitChanged();

public slots:

private:
    int m_limit; /*!< TODO */
    int m_current; /*!< TODO */
    QList<QVariantMap> m_contents; /*!< TODO */
    QVariantMap m_persistentContent; /*!< TODO */
};

#endif // LOOPINGSTATEMACHINE_H
