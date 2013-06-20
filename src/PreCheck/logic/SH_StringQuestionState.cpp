#include "SH_StringQuestionState.h"


/*!
 \brief

 \fn StringQuestionState::StringQuestionState
 \param question
 \param name
 \param minLength
 \param maxLength
 \param parent
*/
SH_StringQuestionState::SH_StringQuestionState(QString question, QString name, int minLength, int maxLength, QState *parent) :
    SH_QuestionState(question, name, parent), m_minLen(minLength), m_maxLen(maxLength)
{

}

/*!
 \brief

 \fn StringQuestionState::isAnswerValid
 \param givenAnswer
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
 \brief

 \fn StringQuestionState::maxLen
 \return int
*/
int SH_StringQuestionState::maxLen() const
{
    return m_maxLen;
}

/*!
 \brief

 \fn StringQuestionState::setMaxLen
 \param maxLen
*/
void SH_StringQuestionState::setMaxLen(int maxLen)
{
    m_maxLen = maxLen;
}

/*!
 \brief

 \fn StringQuestionState::minLen
 \return int
*/
int SH_StringQuestionState::minLen() const
{
    return m_minLen;
}

/*!
 \brief

 \fn StringQuestionState::setMinLen
 \param minLen
*/
void SH_StringQuestionState::setMinLen(int minLen)
{
    m_minLen = minLen;
}
