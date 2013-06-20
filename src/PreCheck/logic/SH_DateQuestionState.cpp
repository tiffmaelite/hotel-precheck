#include "SH_DateQuestionState.h"

/*!
 \brief

 \fn DateQuestionState::DateQuestionState
 \param question
 \param name
 \param past
 \param future
 \param parent
*/
SH_DateQuestionState::SH_DateQuestionState(QString question, QString name, bool past, bool future, QState *parent) :
    SH_QuestionState(question+" (au format jj-mm-aaaa)", name, parent), m_past(past), m_future(future)
{
}

/*!
 \brief

 \fn DateQuestionState::isAnswerValid
 \param givenAnswer
*/
bool SH_DateQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    QDate answer = QDate::fromString(givenAnswer.toString(),QString("dd-MM-yyyy"));
    if(answer.isValid()) {
        qDebug() << "date conforme";
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
bool SH_DateQuestionState::getPast() const
{
    return m_past;
}

/*!
 \brief

 \fn DateQuestionState::setPast
 \param value
*/
void SH_DateQuestionState::setPast(bool value)
{
    m_past = value;
}

/*!
 \brief

 \fn DateQuestionState::getFuture
 \return bool
*/
bool SH_DateQuestionState::getFuture() const
{
    return m_future;
}

/*!
 \brief

 \fn DateQuestionState::setFuture
 \param value
*/
void SH_DateQuestionState::setFuture(bool value)
{
    m_future = value;
}

/*!
 \brief
 \fn DateQuestionState::rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant SH_DateQuestionState::rawInput() const
{
    return QVariant(input().toDate().toString()); //TODO set format
}
