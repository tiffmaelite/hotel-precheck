#ifndef STRINGQUESTIONSTATE_H
#define STRINGQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
\brief \~french 

 \class SH_StringQuestionState stringquestionstate.h "logic/stringquestionstate.h"
*/
class SH_StringQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn StringQuestionState
 \param question
 \param name
 \param minLength
 \param maxLength
 \param parent
*/
    SH_StringQuestionState(QString question, QString name, int minLength = 0, int maxLength = -1, QState *parent = 0);
/*!
\brief \~french 

 \fn isAnswerValid
 \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

/*!
\brief \~french 

 \fn maxLen
 \return int
*/
int maxLen() const;
/*!
\brief \~french 

 \fn setMaxLen
 \param maxLen
*/
void setMaxLen(int maxLen);

/*!
\brief \~french 

 \fn minLen
 \return int
*/
int minLen() const;
/*!
\brief \~french 

 \fn setMinLen
 \param minLen
*/
void setMinLen(int minLen);

signals:

public slots:

private:
/*!
 *\brief \~french  m_minLen
 */
int m_minLen;
/*!
 *\brief \~french  m_maxLen
 */
int m_maxLen;

};

#endif /* STRINGQUESTIONSTATE_H*/
