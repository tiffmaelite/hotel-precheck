#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class SH_DecimalQuestionState
\headerfile decimalquestionstate.h "logic/decimalquestionstate.h"
*/
class SH_DecimalQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn SH_DecimalQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_DecimalQuestionState(QString question, QString name, qreal min=0, qreal max=-1, QState *parent = 0);
    /*!
     \brief

     \fn SH_isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

    /*!
     \brief

     \fn SH_min
     \return qreal
    */
    qreal min() const;
    /*!
     \brief

     \fn SH_setMin
     \param min
    */
    void setMin(const qreal &min);

    /*!
     \brief

     \fn SH_max
     \return qreal
    */
    qreal max() const;
    /*!
     \brief

     \fn SH_setMax
     \param max
    */
    void setMax(const qreal &max);

signals:

public slots:

private:
    /*!
     * \brief m_min
     */
    qreal m_min;
    /*!
     * \brief m_max
     */
    qreal m_max;
};

#endif /* DECIMALQUESTIONSTATE_H*/
