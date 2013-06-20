#include "SH_StringQuestionState.h"


/*!
 \details

 \fn SH_StringQuestionState::StringQuestionState

*/
SH_StringQuestionState::SH_StringQuestionState(QString question, QString name, int minLength, int maxLength, QState *parent) :
    SH_QuestionState(question, name, parent), m_minLen(minLength), m_maxLen(maxLength)
{

}

/*!
 \details

 \fn SH_StringQuestionState::isAnswerValid

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

/*!
 \details

 \fn SH_StringQuestionState::maxLen

*/
int SH_StringQuestionState::maxLen() const
{
    return m_maxLen;
}

/*!
 \details

 \fn SH_StringQuestionState::setMaxLen

*/
void SH_StringQuestionState::setMaxLen(int maxLen)
{
    m_maxLen = maxLen;
}

/*!
 \details

 \fn SH_StringQuestionState::minLen

*/
int SH_StringQuestionState::minLen() const
{
    return m_minLen;
}

/*!
 \details

 \fn SH_StringQuestionState::setMinLen

*/
void SH_StringQuestionState::setMinLen(int minLen)
{
    m_minLen = minLen;
}
