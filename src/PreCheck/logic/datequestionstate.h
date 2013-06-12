#ifndef DATEQUESTIONSTATE_H
#define DATEQUESTIONSTATE_H
#include "questionstate.h"

/*!
 \brief

 \class DateQuestionState datequestionstate.h "logic/datequestionstate.h"
*/
class DateQuestionState : public QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn DateQuestionState
 \param question
 \param name
 \param past
 \param future
 \param parent
*/
    DateQuestionState(QString question, QString name, bool past = true, bool future = false, QState *parent = 0);
/*!
 \brief

 \fn isAnswerValid
 \param givenAnswer
*/
void isAnswerValid(const QVariant &givenAnswer);

/*!
 \brief

 \fn getPast
 \return bool
*/
bool getPast() const;
/*!
 \brief

 \fn setPast
 \param value
*/
void setPast(bool value);

/*!
 \brief

 \fn getFuture
 \return bool
*/
bool getFuture() const;
/*!
 \brief

 \fn setFuture
 \param value
*/
void setFuture(bool value);

signals:

public slots:


private:
bool past; /*!< TODO */
bool future; /*!< TODO */
};

#endif // DATEQUESTIONSTATE_H
