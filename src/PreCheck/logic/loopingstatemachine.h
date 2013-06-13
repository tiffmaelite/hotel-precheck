#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "iostatemachine.h"

/*!
 \brief

 \class LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class LoopingIOStateMachine : public IOStateMachine
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
    LoopingIOStateMachine(QString tableName, int limit, QString name, QObject *parent = 0);

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

    void addChildrenNextTransition(QAbstractState *previousState, QAbstractState *nextState);
signals:
    void limitChanged();

public slots:

private:
    int m_limit; /*!< TODO */
    int m_current; /*!< TODO */
    QList<QVariantMap> m_contents; /*!< TODO */
    QVariantMap m_persistentContent; /*!< TODO */
};

#endif // LOOPINGSTATEMACHINE_H
