#include "questionstate.h"

/*!
 \brief

 \fn QuestionState::QuestionState
 \param question
 \param name
 \param parent
*/
QuestionState::QuestionState(QString question, QString name, QState *parent) :
    IOState(question, name, parent)
{
}

/*!
 \brief

 \fn QuestionState::checkValidity
 \return bool
*/
bool QuestionState::checkValidity()
{
    bool ok = this->isAnswerValid(this->givenAnswer());
    if(ok) {
        IOState::setInput(this->givenAnswer());
        emit answerValid();
        emit next();
    } else {
        emit answerInvalid();
    }
    return ok;
}

/*!
 \brief

 \fn QuestionState::setInput
 \param input
*/
void QuestionState::setInput(const QVariant &input)
{
    this->setGivenAnswer(input);
}

/*!
 \brief

 \fn QuestionState::givenAnswer
 \return QVariant
*/
QVariant QuestionState::givenAnswer() const
{
    return this->m_givenAnswer;
}

/*!
 \brief

 \fn QuestionState::setGivenAnswer
 \param givenAsnwer
*/
void QuestionState::setGivenAnswer(const QVariant &givenAsnwer)
{
    this->m_givenAnswer = givenAsnwer;
}
