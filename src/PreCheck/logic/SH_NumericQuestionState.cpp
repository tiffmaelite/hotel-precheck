#include "SH_NumericQuestionState.h"


/*!
 \details

 \fn SH_NumericQuestionState::NumericQuestionState

*/
SH_NumericQuestionState::SH_NumericQuestionState(QString question, QString name, int min, int max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
{

}

/*!
 \details

 \fn SH_NumericQuestionState::isAnswerValid

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
 \details

 \fn SH_NumericQuestionState::min

*/
int SH_NumericQuestionState::min() const
{
    return m_min;
}

/*!
 \details

 \fn SH_NumericQuestionState::setMin
 \param min*/
void SH_NumericQuestionState::setMin(int min)
{
    m_min = min;
}

/*!
 \details

 \fn SH_NumericQuestionState::max

*/
int SH_NumericQuestionState::max() const
{
    return m_max;
}

/*!
 \details

 \fn SH_NumericQuestionState::setMax

*/
void SH_NumericQuestionState::setMax(int max)
{
    m_max = max;
}
