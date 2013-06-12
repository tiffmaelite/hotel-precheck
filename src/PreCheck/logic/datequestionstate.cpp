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
void DateQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QDate answer = givenAnswer.toDateTime().date();
    if(answer.isValid()) {
        return ((future && answer >= QDate::currentDate()) || (past && answer <= QDate::currentDate()));
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
    return past;
}

/*!
 \brief

 \fn DateQuestionState::setPast
 \param value
*/
void DateQuestionState::setPast(bool value)
{
    past = value;
}

/*!
 \brief

 \fn DateQuestionState::getFuture
 \return bool
*/
bool DateQuestionState::getFuture() const
{
    return future;
}

/*!
 \brief

 \fn DateQuestionState::setFuture
 \param value
*/
void DateQuestionState::setFuture(bool value)
{
    future = value;
}
