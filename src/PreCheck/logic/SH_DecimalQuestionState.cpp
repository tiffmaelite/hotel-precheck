#include "SH_DecimalQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DecimalQuestionState::DecimalQuestionState
*/
SH_DecimalQuestionState::SH_DecimalQuestionState(QString question, QString name, qreal min, qreal max, QState *parent) :
    SH_QuestionState(question, name, parent), m_minimum(min), m_maximum(max)
{
}
/*!
 * \details \~french
 * \fn SH_DecimalQuestionState::isAnswerValid
*/
bool SH_DecimalQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    bool ok;
    qreal answer = givenAnswer.toReal(&ok);
    if(ok) {
        return ((m_maximum <= m_minimum || answer <= m_maximum) && answer >= m_minimum);
    } else {
        return false;
    }
}

/*}*/
