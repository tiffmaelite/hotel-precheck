#include "SH_QuestionState.h"

/*!
 \details \~french

 \fn SH_QuestionState::QuestionState

*/
SH_QuestionState::SH_QuestionState(QString question, QString name, QState *parent) :
    SH_InOutState(question, name, parent)
{
}

/*!
 \details \~french

 \fn SH_QuestionState::checkValidity

*/
bool SH_QuestionState::checkValidity()
{
    bool ok = this->isAnswerValid(this->givenAnswer());
    if(ok) {
        qDebug() << this->givenAnswer() << " answer valid !";
        qDebug() << this->givenAnswer();
        SH_InOutState::setInput(this->givenAnswer());
        emit answerValid();
        emit goNext();
    } else {
        qDebug() << this->givenAnswer() << " answer invalid :-(";
        qDebug() << this->givenAnswer();
        emit answerInvalid();
    }
    return ok;
}

/*!
 \details \~french

 \fn SH_QuestionState::setInput

*/
void SH_QuestionState::setInput(const QVariant &input)
{
    qDebug() << "new answer " << input.toString();
    this->setGivenAnswer(input);
}

/*!
 \details \~french

 \fn SH_QuestionState::givenAnswer

*/
QVariant SH_QuestionState::givenAnswer() const
{
    return this->m_givenAnswer;
}

/*!
 \details \~french

 \fn SH_QuestionState::setGivenAnswer

*/
void SH_QuestionState::setGivenAnswer(const QVariant &givenAsnwer)
{
    this->m_givenAnswer = givenAsnwer;
    this->checkValidity();
}
