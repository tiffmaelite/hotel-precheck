#include "SH_DecimalQuestionState.h"


/*!
 \brief

 \fn DecimalQuestionState::DecimalQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
SH_DecimalQuestionState::SH_DecimalQuestionState(QString question, QString name, qreal min, qreal max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
{

}

/*!
 \brief

 \fn DecimalQuestionState::isAnswerValid
 \param givenAnswer
*/
bool SH_DecimalQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    bool ok;
    qreal answer = givenAnswer.toReal(&ok);
    if(ok) {
        return ((m_max <= m_min || answer <= m_max) && answer >= m_min);
    } else {
        return false;
    }
}

/*!
 \brief

 \fn DecimalQuestionState::min
 \return qreal
*/
qreal SH_DecimalQuestionState::min() const
{
    return m_min;
}

/*!
 \brief

 \fn DecimalQuestionState::setMin
 \param min
*/
void SH_DecimalQuestionState::setMin(const qreal &min)
{
    m_min = min;
}

/*!
 \brief

 \fn DecimalQuestionState::max
 \return qreal
*/
qreal SH_DecimalQuestionState::max() const
{
    return m_max;
}

/*!
 \brief

 \fn DecimalQuestionState::setMax
 \param max
*/
void SH_DecimalQuestionState::setMax(const qreal &max)
{
    m_max = max;
}
