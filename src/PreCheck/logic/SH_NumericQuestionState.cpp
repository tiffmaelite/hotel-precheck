#include "SH_NumericQuestionState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_NumericQuestionState::NumericQuestionState
*/
SH_NumericQuestionState::SH_NumericQuestionState(QString question, QString name, int min, int max, QState *parent) :
    SH_QuestionState(question, name, parent), m_min(min), m_max(max)
{
}
/*!
 * \details \~french
 * \fn SH_NumericQuestionState::isAnswerValid
*/
bool SH_NumericQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    SH_MessageManager::debugMessage("is answer valid ?");
    bool ok;
    int answer = givenAnswer.toInt(&ok);
    if(ok) {
    return ((m_max <= m_min || answer <= m_max) && answer >= m_min);
    } else {
    return false;
    }
}

/*}*/
