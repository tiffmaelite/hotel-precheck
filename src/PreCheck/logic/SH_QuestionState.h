#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H
#include "SH_IOState.h"

/*!
\brief \~french 

 \class SH_QuestionState
\headerfile questionstate.h "logic/questionstate.h"
*/
class SH_QuestionState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn SH_QuestionState
 \param question
 \param name
 \param parent
*/
    SH_QuestionState(QString question, QString name, QState *parent = 0);
    /*!
    \brief \~french 

     \fn SH_checkValidity
     \return bool
    */
    bool checkValidity();

    /*!
    \brief \~french 

     \fn SH_givenAnswer
     \return QVariant
    */
    virtual QVariant givenAnswer() const;
    /*!
    \brief \~french 

     \fn SH_setGivenAnswer
     \param givenAnswer
    */
    virtual void setGivenAnswer(const QVariant &givenAnswer);
    /*!
    \brief \~french 

     \fn SH_setInput
     \param input
    */
    virtual void setInput(const QVariant &input);

    /*!
    \brief \~french 

     \fn SH_isAnswerValid
     \param givenAnswer
     \return bool
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer) = 0;

signals:
    /*!
     *\brief \~french  answerValid
     */
    void answerValid();
    /*!
     *\brief \~french  answerInvalid
     */
    void answerInvalid();

public slots:


private:
    /*!
     *\brief \~french  m_givenAnswer
     */
    QVariant m_givenAnswer;
};

#endif /* QUESTIONSTATE_H*/
