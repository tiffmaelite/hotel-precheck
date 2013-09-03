#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_NumericQuestionState numericquestionstate.h "logic/numericquestionstate.h"
*/
class SH_NumericQuestionState : public SH_QuestionState
{
    Q_OBJECT
    /*!
    * \property int maximum
    * \brief \~french La plus grande valeur permise
    * \details ~\french
    */
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged) //MEMBER m_maximum
    /*!
    * \property int minimum
    * \brief \~french La plus petite valeur permise
    * \details ~\french
    */
    Q_PROPERTY(int minimum READ minimum WRITE setMinimum NOTIFY minimumChanged) //MEMBER m_minimum

public:

    /*** Constructor(s) ***/

    /*!
 * \brief \~french
 * \fn NumericQuestionState
 * \param question
 * \param name
 * \param min
 * \param max
 * \param parent
*/
    SH_NumericQuestionState(QString question, QString name, int min=0, int max=-1, QState *parent = 0);

    /*** Properties Getters & Setters ***/

    /*!
    * \fn minimum
    * \brief \~french Accesseur en lecture de la propriété \a minimum
    * \details \~french Permet d'obtenir la date minimale permise
    * \return int La date minimale permise
    */
    int minimum() const { return this->m_minimum; }
    /*!
    * \fn setMinimum
    * \brief \~french Accesseur en écriture de la propriété \a minimum
    * \details \~french Permet de définir la valeur minimale permise
    * \param int minimum La nouvelle valeur minimale permise
    */
    void setMinimum(const int &minimum){ this->m_minimum = minimum; emit minimumChanged(); }

    /*!
    * \fn maximum
    * \brief \~french Accesseur en lecture de la propriété \a maximum
    * \details \~french Permet d'obtenir la valeur maximale permise
    * \return int La valeur maximale permise
    */
    int maximum() const { return this->m_maximum; }
    /*!
    * \fn setMaximum
    * \brief \~french Accesseur en écriture de la propriété \a maximum
    * \details \~french Permet de définir la valeur maximale permise
    * \param int maximum La nouvelle valeur maximale permise
    */
    void setMaximum(const int &maximum){ this->m_maximum = maximum; emit maximumChanged(); }

    /*!
 * \brief \~french
 * \fn isAnswerValid
 * \param givenAnswer
*/
    virtual bool isAnswerValid(const QVariant &givenAnswer);

signals:

    void minimumChanged();
    void maximumChanged();
public slots:
protected:
    void setAcceptedAnswer(const QVariant &givenAnswer);
private:
    /*!
 * \brief \~french this->m_min
 */
    int m_minimum;
    /*!
 * \brief \~french this->m_max
 */
    int m_maximum;
};
/*}*/
#endif /* NUMERICQUESTIONSTATE_H*/
