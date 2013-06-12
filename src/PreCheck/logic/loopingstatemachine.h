#ifndef LOOPINGSTATEMACHINE_H
#define LOOPINGSTATEMACHINE_H
#include "iostatemachine.h"

/*!
 \brief

 \class LoopingStateMachine loopingstatemachine.h "logic/loopingstatemachine.h"
*/
class LoopingStateMachine : public IOStateMachine
{
    Q_OBJECT
public:
/*!
 \brief

 \fn LoopingStateMachine
 \param tableName
 \param limit
 \param name
 \param parent
*/
    LoopingStateMachine(QString tableName, int limit, QString name, QObject *parent = 0);

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

signals:

public slots:

private:
    int m_limit; /*!< TODO */
    int m_current; /*!< TODO */

};

#endif // LOOPINGSTATEMACHINE_H
