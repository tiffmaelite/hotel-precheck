#include "SH_NumericQuestionState.h"


/*!
 \brief

 \fn NumericQuestionState::NumericQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
SH_NumericQuestionState::SH_NumericQuestionState(QString question, QString name, int min, int max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
{

}

/*!
 \brief

 \fn NumericQuestionState::isAnswerValid
 \param givenAnswer
*/
bool SH_NumericQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    qDebug() << "is answer valid";
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
int SH_NumericQuestionState::min() const
{
    return m_min;
}

/*!
 \brief

 \fn NumericQuestionState::setMin
 \param min
*/
void SH_NumericQuestionState::setMin(int min)
{
    m_min = min;
}

/*!
 \brief

 \fn NumericQuestionState::max
 \return int
*/
int SH_NumericQuestionState::max() const
{
    return m_max;
}

/*!
 \brief

 \fn NumericQuestionState::setMax
 \param max
*/
void SH_NumericQuestionState::setMax(int max)
{
    m_max = max;
}
