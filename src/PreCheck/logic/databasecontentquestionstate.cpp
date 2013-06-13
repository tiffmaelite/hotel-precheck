#include "databasecontentquestionstate.h"
#include "models/SqlDataModel.h"

/*!
 \brief

 \fn DatabaseContentQuestionState::DatabaseContentQuestionState
 \param question
 \param name
 \param databaseTable
 \param tableField
 \param databaseCondition
 \param parent
*/
DatabaseContentQuestionState::DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition, QState *parent) :
    QuestionState(question, name, parent), m_table(databaseTable), m_condition(databaseCondition), m_field(tableField)
{
    SqlDataModel *sqlDatas = new SqlDataModel();
    QStringList fields;
    fields << "ID" << m_field;
    sqlDatas->fetch(m_table, m_condition, "", fields);
    QVariantMap results = sqlDatas->datas();
    QVariantList idValues = results.values("ID");
    QVariantList fieldsValues = results.values(m_field);
    for(int i = 0; i < idValues.length(); i++) {
        m_choices.insert(idValues.at(i).toInt(), fieldsValues.at(i));
    }
}

/*!
 \brief

 \fn DatabaseContentQuestionState::isAnswerValid
 \param givenAnswer
*/
bool DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    return m_choices.values().contains(givenAnswer);
}

/*!
 \brief
 \fn DatabaseContentQuestionState::setOutput TODO comment this
 \param output TODO comment this
*/
void DatabaseContentQuestionState::setOutput(const QString &output)
{
    QuestionState::setOutput(output);
    if(m_choices.size() < 8) {
        m_choicesDisplayed = true;
        emit displayChoiceList();
    }
}

/*!
 \brief
 \fn DatabaseContentQuestionState::rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant DatabaseContentQuestionState::rawInput() const
{
    return m_choices.key(this->givenAnswer());
}

/*!
 \brief
 \fn DatabaseContentQuestionState::choiceList TODO comment this
 \return QMap<int, QVariant> TODO comment this
*/
QMap<int, QVariant> DatabaseContentQuestionState::choiceList() {
    if(m_choicesDisplayed) {
        return m_choices;
    }
    return QMap<int,QVariant>();
}
