#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class SH_NumericQuestionState numericquestionstate.h "logic/numericquestionstate.h"
*/
class SH_NumericQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn SH_NumericQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_NumericQuestionState(QString question, QString name, int min=0, int max=-1, QState *parent = 0);
/*!
 \brief

 \fn SH_isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
 \brief

 \fn SH_min
 \return int
*/
int min() const;
/*!
 \brief

 \fn SH_setMin
 \param min
*/
void setMin(int min);

/*!
 \brief

 \fn SH_max
 \return int
*/
int max() const;
/*!
 \brief

 \fn SH_setMax
 \param max
*/
void setMax(int max);

signals:

public slots:


private:
/*!
 * \brief m_min
 */
int m_min;
/*!
 * \brief m_max
 */
int m_max;
};

#endif /* NUMERICQUESTIONSTATE_H*/
