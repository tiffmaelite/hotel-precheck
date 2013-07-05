#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_NumericQuestionState numericquestionstate.h "logic/numericquestionstate.h"
*/
class SH_NumericQuestionState : public SH_QuestionState
{
    Q_OBJECT
    Q_PROPERTY(int minimum MEMBER m_min NOTIFY minimumChanged)
    Q_PROPERTY(int maximum MEMBER m_max NOTIFY maximumChanged)
public:
/*!
 * \brief \~french
 * \fn NumericQuestionState
 * \param question
 * \param name
 * \param min
 * \param max
 * \param parent
*/
    SH_NumericQuestionState(QString question, QString name, int min=0, int max=-1, QState *parent = 0);
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
int m_min;
/*!
 * \brief \~french m_max
 */
int m_max;
};
/*}*/
#endif /* NUMERICQUESTIONSTATE_H*/
