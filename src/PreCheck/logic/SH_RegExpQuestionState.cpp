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
    this->m_regexp.setPatternOptions(QRegularExpression::UseUnicodePropertiesOption);
}
/*!
 * \details \~french
 * \fn SH_RegExQuestionState::isAnswerValid
*/
bool SH_RegExpQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    SH_MessageManager::debugMessage(this->m_regexp.pattern());
    if(this->m_regexp.isValid()) {
        QString answer = givenAnswer.toString();
        SH_MessageManager::debugMessage(answer);
        QRegularExpressionMatch found = this->m_regexp.match(answer);
        SH_MessageManager::debugMessage(found.capturedTexts().join(" $$ "));
        return (found.hasMatch() && (found.captured(0) == answer));
    } else {
        return false;
    }
}

/*}*/
