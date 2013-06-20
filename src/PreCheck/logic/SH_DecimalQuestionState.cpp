#include "SH_DecimalQuestionState.h"


/*!
 \details

 \fn SH_DecimalQuestionState::DecimalQuestionState

*/
SH_DecimalQuestionState::SH_DecimalQuestionState(QString question, QString name, qreal min, qreal max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
{

}

/*!
 \details

 \fn SH_DecimalQuestionState::isAnswerValid

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
 \details

 \fn SH_DecimalQuestionState::min

*/
qreal SH_DecimalQuestionState::min() const
{
    return m_min;
}

/*!
 \details

 \fn SH_DecimalQuestionState::setMin

*/
void SH_DecimalQuestionState::setMin(const qreal &min)
{
    m_min = min;
}

/*!
 \details

 \fn SH_DecimalQuestionState::max

*/
qreal SH_DecimalQuestionState::max() const
{
    return m_max;
}

/*!
 \details

 \fn SH_DecimalQuestionState::setMax

*/
void SH_DecimalQuestionState::setMax(const qreal &max)
{
    m_max = max;
}
