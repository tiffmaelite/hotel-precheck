#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class SH_DatabaseContentQuestionState databasecontentquestionstate.h "logic/databasecontentquestionstate.h"
*/
class SH_DatabaseContentQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn SH_DatabaseContentQuestionState
 \param question
 \param name
 \param databaseTable
 \param tableField
 \param databaseCondition
 \param parent
*/
    SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition = "", QState *parent = 0);
    /*!
     \brief

     \fn SH_isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);


    /*!
     \brief
     \fn SH_setOutput TODO comment this
     \param output TODO comment this
    */
    void setOutput(const QString &output);

    /*!
         \brief
         \fn SH_rawInput TODO comment this
         \return QVariant TODO comment this
        */
    virtual QVariant rawInput() const;

    /*!
     \brief
     \fn SH_choiceList TODO comment this
     \return QMap<int, QVariant> TODO comment this
    */
    QMap<int, QVariant> choiceList();

signals:
    /*!
     \brief
     \fn SH_displayChoiceList TODO comment this
    */
    void displayChoiceList();
public slots:

private:
    /*!
     * \brief m_table
     */
    QString m_table;
    /*!
     * \brief m_condition
     */
    QString m_condition;
    /*!
     * \brief m_field
     */
    QString m_field;
    /*!
     * \brief m_choices
     */
    QMap<int, QVariant> m_choices;
    /*!
     * \brief m_choicesDisplayed
     */
    bool m_choicesDisplayed;
};

#endif /* DATABASECONTENTQUESTIONSTATE_H*/
