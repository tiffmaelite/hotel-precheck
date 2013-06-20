#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H
#include "SH_IOState.h"

/*!
 \brief

 \class SH_QuestionState
\headerfile questionstate.h "logic/questionstate.h"
*/
class SH_QuestionState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn SH_QuestionState
 \param question
 \param name
 \param parent
*/
    SH_QuestionState(QString question, QString name, QState *parent = 0);
    /*!
     \brief

     \fn SH_checkValidity
     \return bool
    */
    bool checkValidity();

    /*!
     \brief

     \fn SH_givenAnswer
     \return QVariant
    */
    virtual QVariant givenAnswer() const;
    /*!
     \brief

     \fn SH_setGivenAnswer
     \param givenAnswer
    */
    virtual void setGivenAnswer(const QVariant &givenAnswer);
    /*!
     \brief

     \fn SH_setInput
     \param input
    */
    virtual void setInput(const QVariant &input);

    /*!
     \brief

     \fn SH_isAnswerValid
     \param givenAnswer
     \return bool
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer) = 0;

signals:
    /*!
     * \brief answerValid
     */
    void answerValid();
    /*!
     * \brief answerInvalid
     */
    void answerInvalid();

public slots:


private:
    /*!
     * \brief m_givenAnswer
     */
    QVariant m_givenAnswer;
};

#endif /* QUESTIONSTATE_H*/
