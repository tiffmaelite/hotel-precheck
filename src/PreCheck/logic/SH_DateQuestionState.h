#ifndef DATEQUESTIONSTATE_H
#define DATEQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class DateQuestionState datequestionstate.h "logic/datequestionstate.h"
*/
class SH_DateQuestionState : public SH_QuestionState
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
    SH_DateQuestionState(QString question, QString name, bool past = true, bool future = false, QState *parent = 0);
/*!
 \brief

 \fn isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

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

/*!
 \brief
 \fn rawInput TODO comment this
 \return QVariant TODO comment this
*/
QVariant rawInput() const;
signals:

public slots:


private:
bool m_past; /*!< TODO */
bool m_future; /*!< TODO */
};

#endif // DATEQUESTIONSTATE_H
