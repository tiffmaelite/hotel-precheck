#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H
#include "SH_IOState.h"
#include "SH_MessageManager.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_QuestionState
\headerfile questionstate.h "logic/questionstate.h"
*/
class SH_QuestionState : public SH_InOutState
{
    Q_OBJECT
public:
    /*!
 * \brief \~french
 * \fn QuestionState
 * \param question
 * \param name
 * \param parent
*/
    SH_QuestionState(QString question, QString name, QState *parent = 0);

    virtual QVariant checkedInput();

    virtual QVariant displayableInput();

    /*!
    * \brief \~french
    * \fn isAnswerValid
    * \param givenAnswer
    * \return bool
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer) = 0;
signals:

    /*!
    * \brief \~french answerValid
    */
    void answerValid();

    /*!
    * \brief \~french answerInvalid
    */
    void answerInvalid();
public slots:

    /*!
    * \brief \~french
    * \fn checkValidity
    * \return bool
    */
    bool checkValidity(const QVariant &givenAnswer);

private:

    /*!
    * \brief \~french this->m_givenAnswer
    */
    QVariant m_acceptedAnswer;
};
/*}*/
#endif /* QUESTIONSTATE_H*/
