#include "SH_StringQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_StringQuestionState::StringQuestionState
*/
SH_StringQuestionState::SH_StringQuestionState(QString question, QString name, int minLength, int maxLength, QState *parent) :
    SH_QuestionState(question, name, parent), m_minLen(minLength), m_maxLen(maxLength)
{
}
/*!
 * \details \~french
 * \fn SH_StringQuestionState::isAnswerValid
*/
bool SH_StringQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QString answer = givenAnswer.toString();
    if(!answer.isEmpty()) {
        int answerLength= answer.length();
        return ((m_maxLen <= m_minLen || answerLength <= m_maxLen) && answerLength >= m_minLen);
    } else {
        return false;
    }
}

/*}*/
