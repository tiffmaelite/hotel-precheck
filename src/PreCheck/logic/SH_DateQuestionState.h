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

    /*!
    * \property QDate maximumDate
    * \brief \~french La plus grande date permise
    * \details ~\french
    */
    Q_PROPERTY(QDate maximumDate READ maximumDate WRITE setMaximumDate NOTIFY maximumDateChanged) //MEMBER m_maximum
    /*!
    * \property QDate minimumDate
    * \brief \~french La plus petite date permise
    * \details ~\french
    */
    Q_PROPERTY(QDate minimumDate READ minimumDate WRITE setMinimumDate NOTIFY minimumDateChanged) //MEMBER m_minimum
    /*!
    * \property QDate minimumDate
    * \brief \~french La plus petite date permise
    * \details ~\french
    */
    Q_PROPERTY(bool isPast READ isPast WRITE setPast STORED false)
    /*!
    * \property QDate minimumDate
    * \brief \~french La plus petite date permise
    * \details ~\french
    */
    Q_PROPERTY(bool isFuture READ isFuture WRITE setFuture STORED false)

public:

    /*** Constructor(s) ***/

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

    /*** Properties Getters & Setters ***/

    /*!
    * \fn minimumDate
    * \brief \~french Accesseur en lecture de la propriété \a minimumDate
    * \details \~french Permet d'obtenir la date minimale permise
    * \return QDate La date minimale permise
    */
    QDate minimumDate() const { return this->m_minimum; }
    /*!
    * \fn setMinimumDate
    * \brief \~french Accesseur en écriture de la propriété \a minimumDate
    * \details \~french Permet de définir la date minimale permise
    * \param QDate minimumDate La nouvelle date minimale permise
    */
    void setMinimumDate(const QDate &minimumDate){ this->m_minimum = minimumDate; emit minimumDateChanged(); }

    /*!
    * \fn maximumDate
    * \brief \~french Accesseur en lecture de la propriété \a maximumDate
    * \details \~french Permet d'obtenir la date maximale permise
    * \return QDate La date maximale permise
    */
    QDate maximumDate() const { return this->m_maximum; }
    /*!
    * \fn setMaximumDate
    * \brief \~french Accesseur en écriture de la propriété \a maximumDate
    * \details \~french Permet de définir la date maximale permise
    * \param QDate minimumDate La nouvelle date maximale permise
    */
    void setMaximumDate(const QDate &maximumDate){ this->m_maximum = maximumDate; emit maximumDateChanged(); }

    /*!
 * \brief \~french
 * \fn getPast
 * \return bool
*/
    bool isPast() const { return (this->m_maximum.isValid() && this->m_maximum >= QDate::currentDate()); }

    /*!
 * \brief \~french
 * \fn setPast
 * \param value
*/
    void setPast(bool past) { setMaximumDate(past ? QDate::currentDate() : QDate()); }

    /*!
 * \brief \~french
 * \fn getFuture
 * \return bool
*/
    bool isFuture() const { return (this->m_minimum.isValid() && this->m_minimum >= QDate::currentDate()); }

    /*!
 * \brief \~french
 * \fn setFuture
 * \param value
*/
    void setFuture(bool future) { setMinimumDate(future ? QDate::currentDate() : QDate()); }

    /*** Overwritten methods ***/

    /*!
 * \brief \~french
 * \fn isAnswerValid
 * \param givenAnswer
*/
    virtual bool isAnswerValid(const QVariant &givenAnswer);


    /*** Signals methods ***/
signals:
    void minimumDateChanged();
    void maximumDateChanged();

    /*** Slots ***/
protected slots:

public slots:

private slots:



private:

    /*** Properties private members ***/
    QDate m_maximum;
    QDate m_minimum;
};
/*}*/
#endif /* DATEQUESTIONSTATE_H*/
