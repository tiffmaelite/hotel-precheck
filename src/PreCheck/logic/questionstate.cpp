#include "questionstate.h"

QuestionState::QuestionState(QString question, QString name, QState *parent) :
    IOState(question, name, parent)
{
}

bool QuestionState::checkValidity()
{
    bool ok = this->isAnswerValid(this->givenAnswer());
    if(ok) {
        IOState::setInput(this->givenAnswer());
        emit this->next();
    }
    return ok;
}

void QuestionState::setInput(const QVariant &input)
{
    this->setGivenAnswer(input);
}

QVariant QuestionState::givenAnswer() const
{
    return this->m_givenAnswer;
}

void QuestionState::setGivenAnswer(const QVariant &givenAsnwer)
{
    this->m_givenAnswer = givenAsnwer;
}
