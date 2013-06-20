#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "SH_QuestionState.h"

/*!
 \brief

 \class DecimalQuestionState decimalquestionstate.h "logic/decimalquestionstate.h"
*/
class SH_DecimalQuestionState : public SH_QuestionState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn DecimalQuestionState
 \param question
 \param name
 \param min
 \param max
 \param parent
*/
    SH_DecimalQuestionState(QString question, QString name, qreal min=0, qreal max=-1, QState *parent = 0);
    /*!
     \brief

     \fn isAnswerValid
     \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

    /*!
     \brief

     \fn min
     \return qreal
    */
    qreal min() const;
    /*!
     \brief

     \fn setMin
     \param min
    */
    void setMin(const qreal &min);

    /*!
     \brief

     \fn max
     \return qreal
    */
    qreal max() const;
    /*!
     \brief

     \fn setMax
     \param max
    */
    void setMax(const qreal &max);

signals:

public slots:

private:
    qreal m_min; /*!< TODO */
    qreal m_max; /*!< TODO */
};

#endif // DECIMALQUESTIONSTATE_H
