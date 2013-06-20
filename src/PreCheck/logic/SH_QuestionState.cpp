#include "SH_QuestionState.h"

/*!
 \brief

 \fn QuestionState::QuestionState
 \param question
 \param name
 \param parent
*/
SH_QuestionState::SH_QuestionState(QString question, QString name, QState *parent) :
    SH_InOutState(question, name, parent)
{
}

/*!
 \brief

 \fn QuestionState::checkValidity
 \return bool
*/
bool SH_QuestionState::checkValidity()
{
    bool ok = this->isAnswerValid(this->givenAnswer());
    if(ok) {
        qDebug() << this->givenAnswer() << " answer valid !";
        qDebug() << this->givenAnswer();
        SH_InOutState::setInput(this->givenAnswer());
        emit answerValid();
        emit next();
    } else {
        qDebug() << this->givenAnswer() << " answer invalid :-(";
        qDebug() << this->givenAnswer();
        emit answerInvalid();
    }
    return ok;
}

/*!
 \brief

 \fn QuestionState::setInput
 \param input
*/
void SH_QuestionState::setInput(const QVariant &input)
{
    qDebug() << "new answer " << input.toString();
    this->setGivenAnswer(input);
}

/*!
 \brief

 \fn QuestionState::givenAnswer
 \return QVariant
*/
QVariant SH_QuestionState::givenAnswer() const
{
    return this->m_givenAnswer;
}

/*!
 \brief

 \fn QuestionState::setGivenAnswer
 \param givenAsnwer
*/
void SH_QuestionState::setGivenAnswer(const QVariant &givenAsnwer)
{
    this->m_givenAnswer = givenAsnwer;
    this->checkValidity();
}
