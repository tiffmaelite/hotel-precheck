#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
\brief \~french 

 \class SH_DecimalQuestionState
\headerfile decimalquestionstate.h "logic/decimalquestionstate.h"
*/
class SH_DecimalQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
\brief \~french 

 \fn DecimalQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_DecimalQuestionState(QString question, QString name, qreal min=0, qreal max=-1, QState *parent = 0);
    /*!
    \brief \~french 

     \fn isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

    /*!
    \brief \~french 

     \fn min
     \return qreal
    */
    qreal min() const;
    /*!
    \brief \~french 

     \fn setMin
     \param min
    */
    void setMin(const qreal &min);

    /*!
    \brief \~french 

     \fn max
     \return qreal
    */
    qreal max() const;
    /*!
    \brief \~french 

     \fn setMax
     \param max
    */
    void setMax(const qreal &max);

signals:

public slots:

private:
    /*!
     *\brief \~french  m_min
     */
    qreal m_min;
    /*!
     *\brief \~french  m_max
     */
    qreal m_max;
};

#endif /* DECIMALQUESTIONSTATE_H*/
