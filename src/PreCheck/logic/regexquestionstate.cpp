#include "regexquestionstate.h"

/*!
 \brief
 \fn RegExQuestionState::RegExQuestionState TODO comment this
 \param question TODO comment this
 \param name TODO comment this
 \param regex TODO comment this
 \param parent TODO comment this
*/
RegExpQuestionState::RegExpQuestionState(QString question, QString name, QRegularExpression regex, QState *parent) :
    StringQuestionState(question, name, 0,-1,parent)
{
}

/*!
 \brief
 \fn RegExQuestionState::isAnswerValid TODO comment this
 \param givenAnswer TODO comment this
 \return bool TODO comment this
*/
bool RegExpQuestionState::isAnswerValid(const QVariant &givenAnswer)
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
QRegularExpression RegExpQuestionState::regexp() const
{
    return m_regexp;
}

/*!
 \brief
 \fn RegExQuestionState::setRegexp TODO comment this
 \param regexp TODO comment this
*/
void RegExpQuestionState::setRegexp(const QRegularExpression &regexp)
{
    m_regexp = regexp;
}
