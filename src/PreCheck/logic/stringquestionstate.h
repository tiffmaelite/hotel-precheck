#ifndef STRINGQUESTIONSTATE_H
#define STRINGQUESTIONSTATE_H
#include "questionstate.h"

/*!
 \brief

 \class StringQuestionState stringquestionstate.h "logic/stringquestionstate.h"
*/
class StringQuestionState : public QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn StringQuestionState
 \param question
 \param name
 \param minLength
 \param maxLength
 \param parent
*/
    StringQuestionState(QString question, QString name, int minLength = 0, int maxLength = -1, QState *parent = 0);
/*!
 \brief

 \fn isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
 \brief

 \fn maxLen
 \return int
*/
int maxLen() const;
/*!
 \brief

 \fn setMaxLen
 \param maxLen
*/
void setMaxLen(int maxLen);

/*!
 \brief

 \fn minLen
 \return int
*/
int minLen() const;
/*!
 \brief

 \fn setMinLen
 \param minLen
*/
void setMinLen(int minLen);

signals:

public slots:

private:
int m_minLen; /*!< TODO */
int m_maxLen; /*!< TODO */

};

#endif // STRINGQUESTIONSTATE_H
