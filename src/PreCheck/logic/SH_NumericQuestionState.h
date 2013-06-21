#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
\brief \~french 

 \class SH_NumericQuestionState numericquestionstate.h "logic/numericquestionstate.h"
*/
class SH_NumericQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn SH_NumericQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_NumericQuestionState(QString question, QString name, int min=0, int max=-1, QState *parent = 0);
/*!
\brief \~french 

 \fn SH_isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
\brief \~french 

 \fn SH_min
 \return int
*/
int min() const;
/*!
\brief \~french 

 \fn SH_setMin
 \param min
*/
void setMin(int min);

/*!
\brief \~french 

 \fn SH_max
 \return int
*/
int max() const;
/*!
\brief \~french 

 \fn SH_setMax
 \param max
*/
void setMax(int max);

signals:

public slots:


private:
/*!
 *\brief \~french  m_min
 */
int m_min;
/*!
 *\brief \~french  m_max
 */
int m_max;
};

#endif /* NUMERICQUESTIONSTATE_H*/