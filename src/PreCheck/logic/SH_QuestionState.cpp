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
    connect(this, &SH_InOutState::inputChanged, this, &SH_QuestionState::checkValidity);
}

void SH_QuestionState::setAcceptedAnswer(const QVariant &givenAnswer) {
    this->m_acceptedAnswer = givenAnswer;
}

/*!
 * \details \~french
 * \fn SH_QuestionState::checkValidity
*/
bool SH_QuestionState::checkValidity(const QVariant &givenAnswer)
{
    bool ok = false;
    if(this->isRunning()) {
        ok = this->isAnswerValid(givenAnswer);
        if(ok) {
            if(this->m_acceptedAnswer != givenAnswer) {
                this->setAcceptedAnswer(givenAnswer);
                SH_MessageManager::debugMessage(QString("%1 is a VALID answer for question '%2'!").arg(this->m_acceptedAnswer.toString()).arg(this->output()));
                emit displayableInputChanged();
            } else {
                SH_MessageManager::debugMessage(QString("%1 is still a VALID answer for question '%2'!").arg(givenAnswer.toString()).arg(this->output()));
            }
            emit answerValid();
            emit goNext();
        } else {
            SH_MessageManager::debugMessage(QString("%1 is an INvalid :-( answer for question '%2'").arg(givenAnswer.toString()).arg(this->output()));
            emit answerInvalid();
        }
    }
    return ok;
}

QVariant SH_QuestionState::displayableInput()
{
    SH_MessageManager::debugMessage(QString("displayableInput: %1 !").arg(this->m_acceptedAnswer.toString()));
    return this->checkedInput();
}

QVariant SH_QuestionState::checkedInput()
{
    return this->m_acceptedAnswer;
}

/*}*/
