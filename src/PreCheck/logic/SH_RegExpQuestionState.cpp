#include "SH_RegExpQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_RegExQuestionState::RegExQuestionState
*/
SH_RegExpQuestionState::SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex, QState *parent) :
    SH_StringQuestionState(question, name, 0,-1,parent), m_regexp(regex)
{
}
/*!
 * \details \~french
 * \fn SH_RegExQuestionState::isAnswerValid
*/
bool SH_RegExpQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QString answer = givenAnswer.toString();
    QRegularExpressionMatch found = m_regexp.match(answer);
    return (found.hasMatch() && (found.captured(0) == answer));
}
/*!
 * \details \~french
 * \fn SH_RegExQuestionState::regexp
*/
QRegularExpression SH_RegExpQuestionState::regexp() const
{
    return m_regexp;
}
/*!
 * \details \~french
 * \fn SH_RegExQuestionState::setRegexp
*/
void SH_RegExpQuestionState::setRegexp(const QRegularExpression &regexp)
{
    m_regexp = regexp;
}
/*}*/
