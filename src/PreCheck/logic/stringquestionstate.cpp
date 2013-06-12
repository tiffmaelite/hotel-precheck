#include "stringquestionstate.h"


/*!
 \brief

 \fn StringQuestionState::StringQuestionState
 \param question
 \param name
 \param minLength
 \param maxLength
 \param parent
*/
StringQuestionState::StringQuestionState(QString question, QString name, int minLength, int maxLength, QState *parent) :
    QuestionState(question, name, parent), m_minLen(minLength), m_maxLen(maxLength)
{

}

/*!
 \brief

 \fn StringQuestionState::isAnswerValid
 \param givenAnswer
*/
void StringQuestionState::isAnswerValid(const QVariant &givenAnswer)
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
int StringQuestionState::maxLen() const
{
    return m_maxLen;
}

/*!
 \brief

 \fn StringQuestionState::setMaxLen
 \param maxLen
*/
void StringQuestionState::setMaxLen(int maxLen)
{
    m_maxLen = maxLen;
}

/*!
 \brief

 \fn StringQuestionState::minLen
 \return int
*/
int StringQuestionState::minLen() const
{
    return m_minLen;
}

/*!
 \brief

 \fn StringQuestionState::setMinLen
 \param minLen
*/
void StringQuestionState::setMinLen(int minLen)
{
    m_minLen = minLen;
}
