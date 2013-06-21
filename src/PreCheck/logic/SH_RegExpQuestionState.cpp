#include "SH_RegExpQuestionState.h"

/*!
 \details \~french
 \fn SH_RegExQuestionState::RegExQuestionState TODO comment this

*/
SH_RegExpQuestionState::SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex, QState *parent) :
    SH_StringQuestionState(question, name, 0,-1,parent)
{
}

/*!
 \details \~french
 \fn SH_RegExQuestionState::isAnswerValid TODO comment this

*/
bool SH_RegExpQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QString answer = givenAnswer.toString();
    QRegularExpressionMatch found = m_regexp.match(answer);
    return (found.hasMatch() && (found.captured(0) == answer));
}


/*!
 \details \~french
 \fn SH_RegExQuestionState::regexp TODO comment this

*/
QRegularExpression SH_RegExpQuestionState::regexp() const
{
    return m_regexp;
}

/*!
 \details \~french
 \fn SH_RegExQuestionState::setRegexp TODO comment this

*/
void SH_RegExpQuestionState::setRegexp(const QRegularExpression &regexp)
{
    m_regexp = regexp;
}
