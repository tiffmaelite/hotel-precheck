#include "numericquestionstate.h"


/*!
 \brief

 \fn NumericQuestionState::NumericQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
NumericQuestionState::NumericQuestionState(QString question, QString name, int min, int max, QState *parent) :
    QuestionState(question, name, parent), m_min(min), m_max(max)
{

}

/*!
 \brief

 \fn NumericQuestionState::isAnswerValid
 \param givenAnswer
*/
void NumericQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    bool ok;
    int answer = givenAnswer.toInt(&ok);
    if(ok) {
        return ((m_max <= m_min || answer <= m_max) && answer >= m_min);
    } else {
        return false;
    }
}

/*!
 \brief

 \fn NumericQuestionState::min
 \return int
*/
int NumericQuestionState::min() const
{
    return m_min;
}

/*!
 \brief

 \fn NumericQuestionState::setMin
 \param min
*/
void NumericQuestionState::setMin(int min)
{
    m_min = min;
}

/*!
 \brief

 \fn NumericQuestionState::max
 \return int
*/
int NumericQuestionState::max() const
{
    return m_max;
}

/*!
 \brief

 \fn NumericQuestionState::setMax
 \param max
*/
void NumericQuestionState::setMax(int max)
{
    m_max = max;
}
