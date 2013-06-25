#include "SH_DateQuestionState.h"
#include "SH_MessageManager.h"

/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DateQuestionState::DateQuestionState
*/
SH_DateQuestionState::SH_DateQuestionState(QString question, QString name, bool past, bool future, QState *parent) :
    SH_QuestionState(question+" (au format jj-mm-aaaa)", name, parent), m_maximum(QDate()), m_minimum(QDate())
{
    setPast(past);
    setFuture(future);
}

void SH_DateQuestionState::setMinimumDate(QDate after)
{
    m_minimum = after;
}

void SH_DateQuestionState::setMaximumDate(QDate before)
{
    m_maximum = before;
}

/*!
 * \details \~french
 * \fn SH_DateQuestionState::isAnswerValid
*/
bool SH_DateQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QDate answer = QDate::fromString(givenAnswer.toString(),QString("dd-MM-yyyy")); //FIXME ajouter autres formats
    if(answer.isValid()) {
        SH_MessageManager::debugMessage("date conforme");
        if(m_maximum.isValid()) {
            SH_MessageManager::debugMessage(QString("date max (%1) valide").arg(m_maximum.toString()));
            if(answer <= m_maximum) {
                SH_MessageManager::debugMessage(QString("%1 avant date max").arg(answer.toString()));
            }
        }
        if(m_minimum.isValid()) {
            SH_MessageManager::debugMessage(QString("date min (%1) valide").arg(m_minimum.toString()));
            if(answer >= m_maximum) {
                SH_MessageManager::debugMessage(QString("%1 avant après min").arg(answer.toString()));
            }
        }
    }
    return (
                (answer.isValid())
                && ((m_maximum.isValid() && answer <= m_maximum)||(m_minimum.isValid() && answer >= m_minimum))
                );
}
/*!
 * \details \~french
 * \fn SH_DateQuestionState::getPast
*/
bool SH_DateQuestionState::isPast() const
{
    return (m_maximum.isValid() && m_maximum >= QDate::currentDate());
}
/*!
 * \details \~french
 * \fn SH_DateQuestionState::setPast
*/
void SH_DateQuestionState::setPast(bool value)
{
    if(value) {
        setMaximumDate(QDate::currentDate());
    } else{
        setMaximumDate(QDate());
    }
}
/*!
 * \details \~french
 * \fn SH_DateQuestionState::getFuture
*/
bool SH_DateQuestionState::isFuture() const
{
    return (m_minimum.isValid() && m_minimum <= QDate::currentDate());
}
/*!
 * \details \~french
 * \fn SH_DateQuestionState::setFuture
*/
void SH_DateQuestionState::setFuture(bool value)
{
    if(value) {
        setMinimumDate(QDate::currentDate());
    } else{
        setMinimumDate(QDate());
    }
}
/*!
 * \details \~french
 * \fn SH_DateQuestionState::rawInput
*/
QVariant SH_DateQuestionState::rawInput() const
{
    return QVariant(input().toDate().toString());
    /*TODO set format*/
}
/*}*/
