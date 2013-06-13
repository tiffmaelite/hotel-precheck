#include "datequestionstate.h"

/*!
 \brief

 \fn DateQuestionState::DateQuestionState
 \param question
 \param name
 \param past
 \param future
 \param parent
*/
DateQuestionState::DateQuestionState(QString question, QString name, bool past, bool future, QState *parent) :
    QuestionState(question, name, parent), m_past(past), m_future(future)
{
}

/*!
 \brief

 \fn DateQuestionState::isAnswerValid
 \param givenAnswer
*/
bool DateQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QDate answer = givenAnswer.toDateTime().date();
    if(answer.isValid()) {
        return ((m_future && answer >= QDate::currentDate()) || (m_past && answer <= QDate::currentDate()));
    } else {
        return false;
    }
}

/*!
 \brief

 \fn DateQuestionState::getPast
 \return bool
*/
bool DateQuestionState::getPast() const
{
    return m_past;
}

/*!
 \brief

 \fn DateQuestionState::setPast
 \param value
*/
void DateQuestionState::setPast(bool value)
{
    m_past = value;
}

/*!
 \brief

 \fn DateQuestionState::getFuture
 \return bool
*/
bool DateQuestionState::getFuture() const
{
    return m_future;
}

/*!
 \brief

 \fn DateQuestionState::setFuture
 \param value
*/
void DateQuestionState::setFuture(bool value)
{
    m_future = value;
}

/*!
 \brief
 \fn DateQuestionState::rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant DateQuestionState::rawInput() const
{
    return QVariant(input().toDate().toString()); //TODO set format
}
