#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "questionstate.h"

/*!
 \brief

 \class DatabaseContentQuestionState databasecontentquestionstate.h "logic/databasecontentquestionstate.h"
*/
class DatabaseContentQuestionState : public QuestionState
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
    DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition = "", QState *parent = 0);
    /*!
     \brief

     \fn isAnswerValid
     \param givenAnswer
    */
    void isAnswerValid(const QVariant &givenAnswer);

signals:

public slots:

private:
    QString m_table; /*!< TODO */
    QString m_condition; /*!< TODO */
    QString m_field; /*!< TODO */
};

#endif // DATABASECONTENTQUESTIONSTATE_H
