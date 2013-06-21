#ifndef DATEQUESTIONSTATE_H
#define DATEQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
\brief \~french 

 \class SH_DateQuestionState datequestionstate.h "logic/datequestionstate.h"
*/
class SH_DateQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn SH_DateQuestionState
 \param question
 \param name
 \param past
 \param future
 \param parent
*/
    SH_DateQuestionState(QString question, QString name, bool past = true, bool future = false, QState *parent = 0);
/*!
\brief \~french 

 \fn SH_isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
\brief \~french 

 \fn SH_getPast
 \return bool
*/
bool getPast() const;
/*!
\brief \~french 

 \fn SH_setPast
 \param value
*/
void setPast(bool value);

/*!
\brief \~french 

 \fn SH_getFuture
 \return bool
*/
bool getFuture() const;
/*!
\brief \~french 

 \fn SH_setFuture
 \param value
*/
void setFuture(bool value);

/*!
\brief \~french 
 \fn SH_rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant rawInput() const;
signals:

public slots:


private:
/*!
 *\brief \~french  m_past
 */
bool m_past;
/*!
 *\brief \~french  m_future
 */
bool m_future;
};

#endif /* DATEQUESTIONSTATE_H*/
