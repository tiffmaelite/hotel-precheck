#include "SH_DateQuestionState.h"

/*!
 \details

 \fn SH_DateQuestionState::DateQuestionState

*/
SH_DateQuestionState::SH_DateQuestionState(QString question, QString name, bool past, bool future, QState *parent) :
    SH_QuestionState(question+" (au format jj-mm-aaaa)", name, parent), m_past(past), m_future(future)
{
}

/*!
 \details

 \fn SH_DateQuestionState::isAnswerValid

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
 \details

 \fn SH_DateQuestionState::getPast

*/
bool SH_DateQuestionState::getPast() const
{
    return m_past;
}

/*!
 \details

 \fn SH_DateQuestionState::setPast

*/
void SH_DateQuestionState::setPast(bool value)
{
    m_past = value;
}

/*!
 \details

 \fn SH_DateQuestionState::getFuture

*/
bool SH_DateQuestionState::getFuture() const
{
    return m_future;
}

/*!
 \details

 \fn SH_DateQuestionState::setFuture

*/
void SH_DateQuestionState::setFuture(bool value)
{
    m_future = value;
}

/*!
 \details
 \fn SH_DateQuestionState::rawInput TODO comment this

*/
QVariant SH_DateQuestionState::rawInput() const
{
    return QVariant(input().toDate().toString()); /*TODO set format*/
}
