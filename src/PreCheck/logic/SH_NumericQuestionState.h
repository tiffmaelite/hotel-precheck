#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class NumericQuestionState numericquestionstate.h "logic/numericquestionstate.h"
*/
class SH_NumericQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn NumericQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_NumericQuestionState(QString question, QString name, int min=0, int max=-1, QState *parent = 0);
/*!
 \brief

 \fn isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
 \brief

 \fn min
 \return int
*/
int min() const;
/*!
 \brief

 \fn setMin
 \param min
*/
void setMin(int min);

/*!
 \brief

 \fn max
 \return int
*/
int max() const;
/*!
 \brief

 \fn setMax
 \param max
*/
void setMax(int max);

signals:

public slots:


private:
int m_min; /*!< TODO */
int m_max; /*!< TODO */
};

#endif // NUMERICQUESTIONSTATE_H
