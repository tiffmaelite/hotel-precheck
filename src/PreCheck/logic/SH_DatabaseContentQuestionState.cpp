#include "SH_DatabaseContentQuestionState.h"
#include "models/SH_SqlDataModel.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::DatabaseContentQuestionState
*/
SH_DatabaseContentQuestionState::SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition, bool noChoiceDisplay, QState *parent) :
    SH_QuestionState(question, name, parent), m_table(databaseTable), m_condition(databaseCondition), m_field(tableField), m_noChoiceDisplay(noChoiceDisplay)
{
    //SH_MessageManager::debugMessage(QString("multiple choice list with datas from %1!").arg(databaseTable));
    SH_SqlDataModel *sqlDatas = new SH_SqlDataModel();
    QStringList fields;
    fields << "ID" << m_field;
    fields.removeDuplicates();
    sqlDatas->fetch(m_table, m_condition, "", fields);
    QVariantMap results = sqlDatas->datas();
    QVariantList idValues = results.values("ID");
    QVariantList fieldsValues = results.values(m_field);
    for(int i = 0; i < idValues.length(); i++) {
        //SH_MessageManager::debugMessage(QString("new choice %1: %2").arg(idValues.at(i).toString()).arg(fieldsValues.at(i).toString()));
        m_choices.insert(idValues.at(i).toInt(), fieldsValues.at(i));
    }
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::isAnswerValid
*/
bool SH_DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    return m_choices.isEmpty() || m_choices.contains(givenAnswer);
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::setOutput
 */
void SH_DatabaseContentQuestionState::setOutput(const QString &output)
{
    SH_QuestionState::setOutput(output);
    if(!m_noChoiceDisplay && m_choices.size() < 8) {
        m_choicesDisplayed = true;
        emit displayChoiceList(m_choices);
    }
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::rawInput
*/
QVariant SH_DatabaseContentQuestionState::rawInput() const
{
    return m_choices.indexOf(this->givenAnswer());
}
/*!
 * \details \~french
 * \fn SH_DatabaseContentQuestionState::choiceList
*/
QVariantList SH_DatabaseContentQuestionState::choiceList() const {
    if(m_choicesDisplayed) {
        return m_choices;
    }
    return QVariantList();
}
/*}*/
