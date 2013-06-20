#ifndef REGEXQUESTIONSTATE_H
#define REGEXQUESTIONSTATE_H
#include "SH_StringQuestionState.h"

/*!
 * \brief The SH_RegExpQuestionState class
 */
class SH_RegExpQuestionState : public SH_StringQuestionState
{
    Q_OBJECT
public:
/*!
 \brief
 \fn SH_RegExQuestionState TODO comment this
 \param question TODO comment this
 \param name TODO comment this
 \param regex TODO comment this
 \param parent TODO comment this
*/
    SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex = QRegularExpression(), QState *parent = 0);

    /*!
     \brief

     \fn SH_isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);
    /*!
     \brief
     \fn SH_regexp TODO comment this
     \return QRegularExpression TODO comment this
    */
    QRegularExpression regexp() const;
    /*!
     \brief
     \fn SH_setRegexp TODO comment this
     \param regexp TODO comment this
    */
    void setRegexp(const QRegularExpression &regexp);

signals:

public slots:


private:
    /*!
     * \brief m_regexp
     */
    QRegularExpression m_regexp;
};

#endif /* REGEXQUESTIONSTATE_H*/
