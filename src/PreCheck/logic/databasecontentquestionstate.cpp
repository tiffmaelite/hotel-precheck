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
    sqlDatas->datas();
}

/*!
 \brief

 \fn DatabaseContentQuestionState::isAnswerValid
 \param givenAnswer
*/
void DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{

}
