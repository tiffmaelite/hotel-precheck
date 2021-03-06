#include "SH_DatabaseContentQuestionState.h"
#include "models/SH_SqlDataModel.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::DatabaseContentQuestionState
*/
SH_DatabaseContentQuestionState::SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition, bool noChoiceDisplay, QRegularExpression condition, QState *parent) :
    SH_QuestionState(question, name, parent), m_table(databaseTable), m_condition(databaseCondition), m_field(tableField), m_noChoiceDisplay(noChoiceDisplay), m_regexcondition(condition)
{
    SH_MessageManager::debugMessage(QString("multiple choice list with datas from %1!").arg(databaseTable));
    SH_SqlDataModel *sqlDatas = new SH_SqlDataModel();
    QStringList fields;
    fields << "ID" << this->m_field;
    fields.removeDuplicates();
    sqlDatas->fetchQuery(this->m_table, m_condition, "", fields);
    sqlDatas->fetch();
    QMultiMap<QString, QVariant> results = sqlDatas->datas();
    QVariantList idValues = results.values("ID");
    QVariantList fieldsValues = results.values(this->m_field);
    if(idValues.size() == fieldsValues.size()) {
        for(int i = 0; i < idValues.size(); i++) {
            SH_MessageManager::debugMessage(QString("new choice %1: %2").arg(idValues.at(i).toString()).arg(fieldsValues.at(i).toString()));
            this->m_choices.insert(idValues.at(i).toInt(), fieldsValues.at(i));
        }
    }
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::isAnswerValid
*/
bool SH_DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    /*if(this->m_choices.isEmpty()) {
    } else {*/
    return (this->m_choices.contains(givenAnswer) || this->m_choices.contains(QVariant(givenAnswer.toString().toLower())) || this->m_choices.contains(QVariant(givenAnswer.toString().toUpper())));
    /*}*/
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::setOutput
 */
void SH_DatabaseContentQuestionState::setOutput(const QString &output)
{
    SH_QuestionState::setOutput(output);
    if(!this->m_noChoiceDisplay && this->m_choices.size() < 8) {
        this->m_choicesDisplayed = true;
        emit displayChoiceList(this->m_choices);
    }
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::displayableInput
*/
QVariant SH_DatabaseContentQuestionState::displayableInput() {
    return this->input();
}

void SH_DatabaseContentQuestionState::setAcceptedAnswer(const QVariant &givenAnswer) {
    if(this->m_regexcondition.match(givenAnswer.toString()).isValid() || this->m_regexcondition.match(givenAnswer.toString().toLower()).isValid() || this->m_regexcondition.match(givenAnswer.toString().toUpper()).isValid()) {
        this->m_acceptedAnswer = givenAnswer;
    }
}

QVariant SH_DatabaseContentQuestionState::checkedInput()
{
    if(this->isAnswerValid(this->m_acceptedAnswer)) {
        return QVariant(this->m_choices.indexOf(this->m_acceptedAnswer));
    } else {
        return this->displayableInput();
    }
}


/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::choiceList
*/
QVariantList SH_DatabaseContentQuestionState::choiceList() {
    if(this->m_choicesDisplayed) {
        return this->m_choices;
    }
    return QVariantList();
}
/*}*/
