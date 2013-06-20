#ifndef STRINGQUESTIONSTATE_H
#define STRINGQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class SH_StringQuestionState stringquestionstate.h "logic/stringquestionstate.h"
*/
class SH_StringQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn SH_StringQuestionState
 \param question
 \param name
 \param minLength
 \param maxLength
 \param parent
*/
    SH_StringQuestionState(QString question, QString name, int minLength = 0, int maxLength = -1, QState *parent = 0);
/*!
 \brief

 \fn SH_isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
 \brief

 \fn SH_maxLen
 \return int
*/
int maxLen() const;
/*!
 \brief

 \fn SH_setMaxLen
 \param maxLen
*/
void setMaxLen(int maxLen);

/*!
 \brief

 \fn SH_minLen
 \return int
*/
int minLen() const;
/*!
 \brief

 \fn SH_setMinLen
 \param minLen
*/
void setMinLen(int minLen);

signals:

public slots:

private:
/*!
 * \brief m_minLen
 */
int m_minLen;
/*!
 * \brief m_maxLen
 */
int m_maxLen;

};

#endif /* STRINGQUESTIONSTATE_H*/
