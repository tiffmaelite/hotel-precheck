#include "SH_RegExpQuestionState.h"

/*!
 \brief
 \fn RegExQuestionState::RegExQuestionState TODO comment this
 \param question TODO comment this
 \param name TODO comment this
 \param regex TODO comment this
 \param parent TODO comment this
*/
SH_RegExpQuestionState::SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex, QState *parent) :
    SH_StringQuestionState(question, name, 0,-1,parent)
{
}

/*!
 \brief
 \fn RegExQuestionState::isAnswerValid TODO comment this
 \param givenAnswer TODO comment this
 \return bool TODO comment this
*/
bool SH_RegExpQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QString answer = givenAnswer.toString();
    QRegularExpressionMatch found = m_regexp.match(answer);
    return (found.hasMatch() && (found.captured(0) == answer));
}


/*!
 \brief
 \fn RegExQuestionState::regexp TODO comment this
 \return QRegExp TODO comment this
*/
QRegularExpression SH_RegExpQuestionState::regexp() const
{
    return m_regexp;
}

/*!
 \brief
 \fn RegExQuestionState::setRegexp TODO comment this
 \param regexp TODO comment this
*/
void SH_RegExpQuestionState::setRegexp(const QRegularExpression &regexp)
{
    m_regexp = regexp;
}
