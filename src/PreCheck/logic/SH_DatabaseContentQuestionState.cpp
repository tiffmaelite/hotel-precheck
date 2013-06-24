#include "SH_DatabaseContentQuestionState.h"
#include "models/SH_SqlDataModel.h"

/*!
 \details \~french

 \fn SH_DatabaseContentQuestionState::DatabaseContentQuestionState

*/
SH_DatabaseContentQuestionState::SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition, QState *parent) :
    SH_QuestionState(question, name, parent), m_table(databaseTable), m_condition(databaseCondition), m_field(tableField)
{
    qDebug() << "multiple choice list with datas from " << databaseTable << "!";
    SH_SqlDataModel *sqlDatas = new SH_SqlDataModel();
    QStringList fields;
    fields << "ID" << m_field;
    sqlDatas->fetch(m_table, m_condition, "", fields);
    QVariantMap results = sqlDatas->datas();
    QVariantList idValues = results.values("ID");
    QVariantList fieldsValues = results.values(m_field);
    for(int i = 0; i < idValues.length(); i++) {
        qDebug() << "new choice " << idValues.at(i).toString() <<  ": " << fieldsValues.at(i).toString();
        m_choices.insert(idValues.at(i).toInt(), fieldsValues.at(i));
    }
}

/*!
 \details \~french

 \fn SH_DatabaseContentQuestionState::isAnswerValid

*/
bool SH_DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    qDebug() << m_choices.values();
    return m_choices.isEmpty() || m_choices.values().contains(givenAnswer);
}

/*!
 \details \~french
 \fn SH_DatabaseContentQuestionState::setOutput 
 */
void SH_DatabaseContentQuestionState::setOutput(const QString &output)
{
    SH_QuestionState::setOutput(output);
    if(m_choices.size() < 8) {
        m_choicesDisplayed = true;
        emit displayChoiceList();
    }
}

/*!
 \details \~french
 \fn SH_DatabaseContentQuestionState::rawInput 

*/
QVariant SH_DatabaseContentQuestionState::rawInput() const
{
    return m_choices.key(this->givenAnswer());
}

/*!
 \details \~french
 \fn SH_DatabaseContentQuestionState::choiceList 

*/
QMap<int, QVariant> SH_DatabaseContentQuestionState::choiceList() {
    if(m_choicesDisplayed) {
        return m_choices;
    }
    return QMap<int,QVariant>();
}
