#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H
#include "iostate.h"

/*!
 \brief

 \class QuestionState questionstate.h "logic/questionstate.h"
*/
class QuestionState : public IOState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn QuestionState
 \param question
 \param name
 \param parent
*/
    QuestionState(QString question, QString name, QState *parent = 0);
    /*!
     \brief

     \fn checkValidity
     \return bool
    */
    bool checkValidity();

    /*!
     \brief

     \fn givenAnswer
     \return QVariant
    */
    virtual QVariant givenAnswer() const;
    /*!
     \brief

     \fn setGivenAnswer
     \param givenAnswer
    */
    virtual void setGivenAnswer(const QVariant &givenAnswer);
    /*!
     \brief

     \fn setInput
     \param input
    */
    virtual void setInput(const QVariant &input);

    /*!
     \brief

     \fn isAnswerValid
     \param givenAnswer
     \return bool
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer) = 0;

signals:

public slots:


private:
    QVariant m_givenAnswer; /*!< TODO */
};

#endif // QUESTIONSTATE_H
