#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_DatabaseContentQuestionState databasecontentquestionstate.h "logic/databasecontentquestionstate.h"
*/
class SH_DatabaseContentQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:

/*!
 * \brief \~french
 * \fn DatabaseContentQuestionState
 * \param question
 * \param name
 * \param databaseTable
 * \param tableField
 * \param databaseCondition
 * \param parent
*/
    SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition = "", QState *parent = 0);

/*!
    * \brief \~french
 * \fn isAnswerValid
    * \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
    * \brief \~french
    * \fn setOutput
    * \param output
    */
    void setOutput(const QString &output);

/*!
    * \brief \~french
    * \fn rawInput
    * \return QVariant
    */
    virtual QVariant rawInput() const;

/*!
    * \brief \~french
    * \fn choiceList
    * \return QMap<int, QVariant>
    */
    QVariantList choiceList();
signals:

/*!
    * \brief \~french
    * \fn displayChoiceList
    */
    void displayChoiceList(QVariantList choices);
public slots:
private:

/*!
    * \brief \~french m_table
    */
    QString m_table;

/*!
    * \brief \~french m_condition
    */
    QString m_condition;

/*!
    * \brief \~french m_field
    */
    QString m_field;

/*!
    * \brief \~french m_choices
    */
    QVariantList m_choices;

/*!
    * \brief \~french m_choicesDisplayed
    */
    bool m_choicesDisplayed;
};
/*}*/
#endif /* DATABASECONTENTQUESTIONSTATE_H*/
