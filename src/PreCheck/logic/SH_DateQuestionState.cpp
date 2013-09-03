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
    this->setPast(past);
    this->setFuture(future);
}

/*!
 * \details \~french
 * \fn SH_DateQuestionState::isAnswerValid
*/
bool SH_DateQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QDate answer = QDate::fromString(givenAnswer.toString(),QString("dd-MM-yyyy")); //FIXME ajouter autres formats
    return (
                (answer.isValid())
                && (
                    (this->m_maximum.isValid() && answer <= this->m_maximum)
                    ||(this->m_minimum.isValid() && answer >= this->m_minimum)
                    )
                );
}

void SH_DateQuestionState::setAcceptedAnswer(const QVariant &givenAnswer) {
    this->m_acceptedAnswer = QVariant(QDate::fromString(givenAnswer.toString(),QString("dd-MM-yyyy")));
}


/*}*/
