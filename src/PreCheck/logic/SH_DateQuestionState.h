#ifndef DATEQUESTIONSTATE_H
#define DATEQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_DateQuestionState datequestionstate.h "logic/datequestionstate.h"
*/
class SH_DateQuestionState : public SH_QuestionState
{
    Q_OBJECT
    Q_PROPERTY(QDate maximumDate MEMBER m_maximum NOTIFY maximumDateChanged)
    Q_PROPERTY(QDate minimumDate MEMBER m_minimum NOTIFY minimumDateChanged)

public:
    /*!
 * \brief \~french
 * \fn DateQuestionState
 * \param question
 * \param name
 * \param past
 * \param future
 * \param parent
*/
    SH_DateQuestionState(QString question, QString name, bool past = true, bool future = false, QState *parent = 0);

    /*!
 * \brief \~french
 * \fn isAnswerValid
 * \param givenAnswer
*/
    virtual bool isAnswerValid(const QVariant &givenAnswer);
    /*!
 * \brief \~french
 * \fn getPast
 * \return bool
*/
    bool isPast() const;
    /*!
 * \brief \~french
 * \fn setPast
 * \param value
*/
    void setPast(bool value);
    /*!
 * \brief \~french
 * \fn getFuture
 * \return bool
*/
    bool isFuture() const;
    /*!
 * \brief \~french
 * \fn setFuture
 * \param value
*/
    void setFuture(bool value);
    /*!
 * \brief \~french
 * \fn rawInput
 * \return QVariant
*/
    QVariant rawInput() const;

signals:
public slots:

private:
    QDate m_maximum;
    QDate m_minimum;
};
/*}*/
#endif /* DATEQUESTIONSTATE_H*/
