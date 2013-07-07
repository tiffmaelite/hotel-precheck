#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_DecimalQuestionState
 * \headerfile decimalquestionstate.h "logic/decimalquestionstate.h"
*/
class SH_DecimalQuestionState : public SH_QuestionState
{
    Q_OBJECT

    /*!
    * \property qreal maximum
    * \brief \~french La plus grande valeur permise
    * \details ~\french
    */
    Q_PROPERTY(qreal maximum READ maximum WRITE setMaximum NOTIFY maximumChanged) //MEMBER m_max
    /*!
    * \property qreal minimum
    * \brief \~french La plus petite valeur permise
    * \details ~\french
    */
    Q_PROPERTY(qreal minimum READ minimum WRITE setMinimum NOTIFY minimumChanged) //MEMBER m_min

public:

        /*** Constructor(s) ***/
/*!
 * \brief \~french
 * \fn DecimalQuestionState
 * \param question
 * \param name
 * \param min
 * \param max
 * \param parent
*/
    SH_DecimalQuestionState(QString question, QString name, qreal min=0, qreal max=-1, QState *parent = 0);

    /*** Properties Getters & Setters ***/

    /*!
    * \fn minimum
    * \brief \~french Accesseur en lecture de la propriété \a minimum
    * \details \~french Permet d'obtenir la date minimale permise
    * \return qreal La date minimale permise
    */
    qreal minimum() const { return m_min; }
    /*!
    * \fn setMinimum
    * \brief \~french Accesseur en écriture de la propriété \a minimum
    * \details \~french Permet de définir la valeur minimale permise
    * \param qreal minimum La nouvelle valeur minimale permise
    */
    void setMinimum(const qreal &minimum){ m_min = minimum; emit minimumChanged(); }

    /*!
    * \fn maximum
    * \brief \~french Accesseur en lecture de la propriété \a maximum
    * \details \~french Permet d'obtenir la valeur maximale permise
    * \return qreal La valeur maximale permise
    */
    qreal maximum() const { return m_max; }
    /*!
    * \fn setMaximum
    * \brief \~french Accesseur en écriture de la propriété \a maximum
    * \details \~french Permet de définir la valeur maximale permise
    * \param qreal maximum La nouvelle valeur maximale permise
    */
    void setMaximum(const qreal &maximum){ m_max = maximum; emit maximumChanged(); }


        /*** Overwritten methods ***/

/*!
    * \brief \~french
 * \fn isAnswerValid
    * \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);


    /*** Signals methods ***/
signals:
    void minimumChanged();
    void maximumChanged();
    /*** Slots ***/
protected slots:

public slots:

private slots:



private:

    /*** Properties private members ***/

/*!
    * \brief \~french m_min
    */
    qreal m_min;

/*!
    * \brief \~french m_max
    */
    qreal m_max;
};
/*}*/
#endif /* DECIMALQUESTIONSTATE_H*/
