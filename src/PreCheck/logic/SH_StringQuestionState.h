#ifndef STRINGQUESTIONSTATE_H
#define STRINGQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_StringQuestionState stringquestionstate.h "logic/stringquestionstate.h"
*/
class SH_StringQuestionState : public SH_QuestionState
{
    Q_OBJECT
    Q_PROPERTY(int minimumLength READ minimumLength WRITE setMinimumLength NOTIFY minimumLengthChanged) //MEMBER m_minLen
    Q_PROPERTY(int maximumLength READ maximumLength WRITE setMaximumLength NOTIFY maximumLengthChanged) //MEMBER m_maxLen
public:
/*!
 * \brief \~french
 * \fn StringQuestionState
 * \param question
 * \param name
 * \param minLength
 * \param maxLength
 * \param parent
*/
    SH_StringQuestionState(QString question, QString name, int minLength = 0, int maxLength = -1, QState *parent = 0);
/*!
 * \brief \~french
 * \fn isAnswerValid
 * \param givenAnswer
*/
virtual bool isAnswerValid(const QVariant &givenAnswer);

    int minimumLength() const { return m_minLen; }
    void setMinimumLength(int minLen) { m_minLen = minLen; emit minimumLengthChanged(); }

    int maximumLength() const { return m_maxLen; }
    void setMaximumLength(int maxLen) { m_maxLen = maxLen; emit maximumLengthChanged(); }

signals:
    void maximumLengthChanged();
    void minimumLengthChanged();
public slots:
private:
    /*!
 * \brief \~french m_minLen
 */
int m_minLen;
/*!
 * \brief \~french m_maxLen
 */
int m_maxLen;
};
/*}*/
#endif /* STRINGQUESTIONSTATE_H*/
