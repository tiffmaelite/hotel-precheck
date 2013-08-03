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
                && (
                    (m_maximum.isValid() && answer <= m_maximum)
                    ||(m_minimum.isValid() && answer >= m_minimum)
                    )
                );
}


/*!
 * \details \~french
 * \fn SH_DateQuestionState::rawInput
*/
QVariant SH_DateQuestionState::rawInput() const
{
    return QVariant(input().toDate().toString());
    /*TODO set date format*/
}


/*}*/