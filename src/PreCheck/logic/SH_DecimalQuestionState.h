#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_DecimalQuestionState
 * \headerfile decimalquestionstate.h "logic/decimalquestionstate.h"
*/
class SH_DecimalQuestionState : public SH_QuestionState
{
    Q_OBJECT
    Q_PROPERTY(qreal minimum MEMBER m_min NOTIFY minimumChanged)
    Q_PROPERTY(qreal maximum MEMBER m_max NOTIFY maximumChanged)

public:
/*!
 * \brief \~french
 * \fn DecimalQuestionState
 * \param question
 * \param name
 * \param min
 * \param max
 * \param parent
*/
    SH_DecimalQuestionState(QString question, QString name, qreal min=0, qreal max=-1, QState *parent = 0);

/*!
    * \brief \~french
 * \fn isAnswerValid
    * \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);


signals:
public slots:
private:

/*!
    * \brief \~french m_min
    */
    qreal m_min;

/*!
    * \brief \~french m_max
    */
    qreal m_max;
};
/*}*/
#endif /* DECIMALQUESTIONSTATE_H*/
