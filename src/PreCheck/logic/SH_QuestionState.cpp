#include "SH_QuestionState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_QuestionState::QuestionState
*/
SH_QuestionState::SH_QuestionState(QString question, QString name, QState *parent) :
    SH_InOutState(question, name, parent)
{
}
/*!
 * \details \~french
 * \fn SH_QuestionState::checkValidity
*/
bool SH_QuestionState::checkValidity()
{
    bool ok = false;
    if(isRunning()) {
        ok = this->isAnswerValid(this->givenAnswer());
        if(ok) {
            SH_MessageManager::infoMessage(QString("%1 is a VALID answer for question '%2'!").arg(this->givenAnswer().toString()).arg(this->output()));
            SH_InOutState::setInput(this->givenAnswer());
            emit answerValid();
            emit goNext();
        } else {
            SH_MessageManager::infoMessage(QString("%1 is an INvalid :-( answer for question '%2'").arg(this->givenAnswer().toString()).arg(this->output()));
            emit answerInvalid();
        }
    }
    return ok;
}
/*!
 * \details \~french
 * \fn SH_QuestionState::setInput
*/
void SH_QuestionState::setInput(const QVariant &input)
{
    if(input != this->givenAnswer()) {
        this->setGivenAnswer(input);
    }
}

/*!
 * \details \~french
 * \fn SH_QuestionState::setGivenAnswer
*/
void SH_QuestionState::setGivenAnswer(const QVariant &givenAnswer)
{
    if(givenAnswer != this->givenAnswer()) {
        this->m_givenAnswer = givenAnswer;
        emit givenAnswerChanged();
        this->checkValidity();
    }
}
/*}*/
