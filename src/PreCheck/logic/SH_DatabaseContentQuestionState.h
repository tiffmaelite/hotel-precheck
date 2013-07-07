#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "SH_QuestionState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_DatabaseContentQuestionState databasecontentquestionstate.h "logic/databasecontentquestionstate.h"
*/
class SH_DatabaseContentQuestionState : public SH_QuestionState
{
    Q_OBJECT

    /*!
    * \property QString table
    * \brief \~french La table de base de données dans laquelle se trouvent les choix permis
    * \details ~\french Si la valeur de la propriété contient un ".", on considèrera que ce qui précède ce caractère est le nom
    *  de la base de données et ce qui le suit le nom de la table dans cette base de données
    */
    Q_PROPERTY(QString table READ tableName WRITE setTableName NOTIFY tableNameChanged) //MEMBER m_table
    /*!
    * \property QString field
    * \brief \~french Le champ de la table indiquée par la propriété \a table dont les différentes valeurs représenteront les choix permis
    * \details ~\french
    */
    Q_PROPERTY(QString field READ tableField WRITE setTableField NOTIFY tableFieldChanged) //MEMBER m_field
    /*!
    * \property QString condition
    * \brief \~french La condition à appliquer sur la table indiquée par la propriété \a table pour obtenir les choix permis
    * \details ~\french
    */
    Q_PROPERTY(QString condition READ tableCondition WRITE setTableCondition NOTIFY tableConditionChanged) //MEMBER m_condition
    /*!
    * \property QVariantList choiceList
    * \brief \~french La liste des choix permis dans cet état
    * \details ~\french
    */
    Q_PROPERTY(QVariantList choiceList READ choiceList) //MEMBER m_choices


public:

    /*** Constructor(s) ***/

    /*!
    * \brief \~french
    * \fn DatabaseContentQuestionState
    * \param question
    * \param name
    * \param databaseTable
    * \param tableField
    * \param databaseCondition
    * \param parent
    */
    SH_DatabaseContentQuestionState(QString question, QString name, QString databaseTable, QString tableField, QString databaseCondition = "", QState *parent = 0);

    /*** Properties Getters & Setters ***/

    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString tableName() const { return m_table; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setTableName(const QString &table){ m_table = table; emit tableNameChanged();}

    /*!
    * \fn tableField
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString tableField() const { return m_field; }
    /*!
    * \fn setTableField
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString field La nouvelle liste de choix de l'état
    */
    void setTableField(const QString &field){ m_field = field; emit tableFieldChanged(); }

    /*!
    * \fn tableCondition
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString tableCondition() const { return m_condition; }
    /*!
    * \fn setTableCondition
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString condition La nouvelle liste de choix de l'état
    */
    void setTableCondition(const QString &condition){ m_condition = condition; emit tableConditionChanged(); }

    /*!
    * \fn choiceList
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QVariantList La liste de choix de l'état
    */
    QVariantList choiceList() const;


    /*** Overwritten methods ***/

    /*!
    * \brief \~french
    * \fn isAnswerValid
    * \param givenAnswer
    */
    virtual bool isAnswerValid(const QVariant &givenAnswer);

    /*!
    * \brief \~french
    * \fn setOutput
    * \param output
    */
    void setOutput(const QString &output);

    /*!
    * \brief \~french
    * \fn rawInput
    * \return QVariant
    */
    virtual QVariant rawInput() const;


    /*** Signals methods ***/
signals:

    /*!
    * \brief \~french
    * \fn displayChoiceList
    */
    void displayChoiceList(QVariantList choices);
    void tableNameChanged();
    void tableFieldChanged();
    void tableConditionChanged();

    /*** Slots ***/
protected slots:

public slots:

private slots:



private:

    /*** Properties private members ***/

    /*!
    * \brief \~french m_table
    */
    QString m_table;

    /*!
    * \brief \~french m_condition
    */
    QString m_condition;

    /*!
    * \brief \~french m_field
    */
    QString m_field;

    /*!
    * \brief \~french m_choices
    */
    QVariantList m_choices;

    /*!
    * \brief \~french m_choicesDisplayed
    */
    bool m_choicesDisplayed;
};
/*}*/
#endif /* DATABASECONTENTQUESTIONSTATE_H*/
