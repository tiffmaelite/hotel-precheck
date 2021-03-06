#include "SH_DecimalQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DecimalQuestionState::DecimalQuestionState
*/
SH_DecimalQuestionState::SH_DecimalQuestionState(QString question, QString name, qreal min, qreal max, QState *parent) :
    SH_QuestionState(question, name, parent), m_minimum(min), m_maximum(max)
{
}
/*!
 * \details \~french
 * \fn SH_DecimalQuestionState::isAnswerValid
*/
bool SH_DecimalQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    bool ok;
    qreal answer = givenAnswer.toReal(&ok);
    if(ok) {
        return ((this->m_maximum <= this->m_minimum || answer <= this->m_maximum) && answer >= this->m_minimum);
    } else {
        return false;
    }
}

void SH_DecimalQuestionState::setAcceptedAnswer(const QVariant &givenAnswer) {
    this->m_acceptedAnswer = QVariant(givenAnswer.toDouble());
}

/*}*/
