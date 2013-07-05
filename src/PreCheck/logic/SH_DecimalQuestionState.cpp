#include "SH_DecimalQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DecimalQuestionState::DecimalQuestionState
*/
SH_DecimalQuestionState::SH_DecimalQuestionState(QString question, QString name, qreal min, qreal max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
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
        return ((m_max <= m_min || answer <= m_max) && answer >= m_min);
    } else {
        return false;
    }
}

/*}*/
