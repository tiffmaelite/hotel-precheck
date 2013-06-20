#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class DatabaseContentQuestionState databasecontentquestionstate.h "logic/databasecontentquestionstate.h"
*/
class SH_DatabaseContentQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn DatabaseContentQuestionState
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

     \fn isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);


    /*!
     \brief
     \fn setOutput TODO comment this
     \param output TODO comment this
    */
    void setOutput(const QString &output);

    /*!
         \brief
         \fn rawInput TODO comment this
         \return QVariant TODO comment this
        */
    virtual QVariant rawInput() const;

    /*!
     \brief
     \fn choiceList TODO comment this
     \return QMap<int, QVariant> TODO comment this
    */
    QMap<int, QVariant> choiceList();

signals:
    /*!
     \brief
     \fn displayChoiceList TODO comment this
    */
    void displayChoiceList();
public slots:

private:
    QString m_table; /*!< TODO */
    QString m_condition; /*!< TODO */
    QString m_field; /*!< TODO */
    QMap<int, QVariant> m_choices; /*!< TODO */
    bool m_choicesDisplayed;/*!< TODO */
};

#endif // DATABASECONTENTQUESTIONSTATE_H
