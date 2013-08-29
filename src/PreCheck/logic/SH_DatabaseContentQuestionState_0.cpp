#include "SH_DatabaseContentQuestionState.h"
#include "models/SH_SqlDataModel.h"

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
SH_DatabaseContentQuestionState::SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition, QState *parent) :
    SH_QuestionState(question, name, parent), m_table(databaseTable), m_condition(databaseCondition), m_field(tableField)
{
    qDebug() << "multiple choice list with datas from " << databaseTable << "!";
    SH_SqlDataModel *sqlDatas = new SH_SqlDataModel();
    QStringList fields;
    fields << "ID" << this->m_field;
    sqlDatas->fetch(this->m_table, m_condition, "", fields);
    QVariantMap results = sqlDatas->datas();
    QVariantList idValues = results.values("ID");
    QVariantList fieldsValues = results.values(this->m_field);
    for(int i = 0; i < idValues.length(); i++) {
        qDebug() << "new choice " << idValues.at(i).toString() <<  ": " << fieldsValues.at(i).toString();
        this->m_choices.insert(idValues.at(i).toInt(), fieldsValues.at(i));
    }
}

/*!
 \brief

 \fn SH_DatabaseContentQuestionState::isAnswerValid
 \param givenAnswer
*/
bool SH_DatabaseContentQuestionState::isAnswerValid(const QVariant &givenAnswer)
{
    /*qDebug() << this->m_choices.values();
    return this->m_choices.isEmpty() || this->m_choices.values().contains(givenAnswer);*/
    return true;
}

/*!
 \brief
 \fn SH_DatabaseContentQuestionState::setOutput TODO comment this
 \param output TODO comment this
*/
void SH_DatabaseContentQuestionState::setOutput(const QString &output)
{
    SH_QuestionState::setOutput(output);
    if(this->m_choices.size() < 8) {
        this->m_choicesDisplayed = true;
        //emit displayChoiceList();
    }
}

/*!
 \brief
 \fn SH_DatabaseContentQuestionState::displayableInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant SH_DatabaseContentQuestionState::displayableInput() const
{
    //return this->m_choices.key(this->enteredInput());
    return QVariant();
}

/*!
 \brief
 \fn DatabaseContentQuestionState::choiceList TODO comment this
 \return QMap<int, QVariant> TODO comment this
*/
QVariantList SH_DatabaseContentQuestionState::choiceList() {
    if(this->m_choicesDisplayed) {
        return this->m_choices;
    }
    return QVariantList();
}
