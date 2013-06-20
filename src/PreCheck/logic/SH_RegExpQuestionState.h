#ifndef REGEXQUESTIONSTATE_H
#define REGEXQUESTIONSTATE_H
#include "SH_StringQuestionState.h"

class SH_RegExpQuestionState : public SH_StringQuestionState
{
    Q_OBJECT
public:
/*!
 \brief
 \fn RegExQuestionState TODO comment this
 \param question TODO comment this
 \param name TODO comment this
 \param regex TODO comment this
 \param parent TODO comment this
*/
    SH_RegExpQuestionState(QString question, QString name, QRegularExpression regex = QRegularExpression(), QState *parent = 0);

    /*!
     \brief

     \fn isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);
    /*!
     \brief
     \fn regexp TODO comment this
     \return QRegularExpression TODO comment this
    */
    QRegularExpression regexp() const;
    /*!
     \brief
     \fn setRegexp TODO comment this
     \param regexp TODO comment this
    */
    void setRegexp(const QRegularExpression &regexp);

signals:

public slots:


private:
    QRegularExpression m_regexp;
};

#endif // REGEXQUESTIONSTATE_H
