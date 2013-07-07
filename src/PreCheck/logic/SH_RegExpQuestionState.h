#ifndef REGEXQUESTIONSTATE_H
#define REGEXQUESTIONSTATE_H
#include "SH_StringQuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french The SH_RegExpQuestionState class
 */
class SH_RegExpQuestionState : public SH_StringQuestionState
{
    Q_OBJECT
    Q_PROPERTY(QRegularExpression regexp READ regexp WRITE setRegexp NOTIFY regexpChanged) //MEMBER m_regexp
public:
/*!
 * \brief \~french
 * \fn RegExQuestionState
 * \param question
 * \param name
 * \param regex
 * \param parent
*/
    SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex = QRegularExpression(), QState *parent = 0);

/*!
    * \brief \~french
 * \fn isAnswerValid
    * \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

    void setRegexp(QRegularExpression regexp) { m_regexp = regexp; emit regexpChanged(); }

    QRegularExpression regexp() const { return m_regexp; }

signals:
    void regexpChanged();
public slots:
private:

/*!
    * \brief \~french m_regexp
    */
    QRegularExpression m_regexp;
};
/*}*/
#endif /* REGEXQUESTIONSTATE_H*/
