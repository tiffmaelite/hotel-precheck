#ifndef IOSTATEMACHINE_H
#define IOSTATEMACHINE_H
#include <QStateMachine>
#include <QHistoryState>
#include <QtCore>
#include "SH_GenericDebugableStateMachine.h"
#include "SH_MessageManager.h"
#include "SH_IOState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_IOStateMachine iostatemachine.h "logic/iostatemachine.h"
*/
class SH_InOutStateMachine : public SH_GenericStateMachine
{
    typedef QMap<QString, QHistoryState *> QHistoryStateMap;

    Q_OBJECT
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName NOTIFY tableNameChanged) //MEMBER m_tableName
    Q_PROPERTY(QVariantMap ioContent READ ioContent WRITE setIOcontent NOTIFY ioContentChanged) //MEMBER m_ioContent
    Q_PROPERTY(QStringList statesList READ statesList) //MEMBER m_fieldsList
    Q_PROPERTY(QString currentStateField READ currentStateField)
    Q_PROPERTY(QHistoryStateMap ioStatesHistory READ ioStatesHistory WRITE setIOStatesHistory NOTIFY ioStatesHistoryChanged) //MEMBER m_ioStatesHistory

public:

    /*!
 * \brief \~french
 * \fn IOStateMachine
 * \param tableName
 * \param name
 * \param parent
*/
    SH_InOutStateMachine(QString tableName, QString name="", QObject *parent = 0);


    QString tableName() const { return this->m_tableName; }
    QString fieldName() { return this->tableName(); }
    void setTableName(const QString &name) { this->m_tableName = name; emit tableNameChanged();}

    QVariantMap ioContent() const { SH_MessageManager::debugMessage("ioContent !"); if(this->m_ioContent.isEmpty()) { SH_MessageManager::debugMessage("ioContent is empty"); } return this->m_ioContent; }
    void setIOcontent(const QVariantMap &content) { this->m_ioContent = content; emit ioContentChanged();}

    QHistoryStateMap ioStatesHistory() const { return this->m_ioStatesHistory; }
    void setIOStatesHistory(const QHistoryStateMap &name) { this->m_ioStatesHistory = name; emit ioStatesHistoryChanged();}

    /*QMap<QString, QHistoryState *> ioStatesHistory() const { return this->m_ioStatesHistory; }
    void setIOStatesHistory(const QMap<QString, QHistoryState *> &name) { this->m_ioStatesHistory = name; emit ioStatesHistoryChanged();}*/

    /*!
    * \brief \~french
 * \fn getContentValue
    * \param field
    * \return QVariant
    */
    QVariant getContentValue(QString field);

    Q_INVOKABLE QString currentStateField();

    /*!
    * \brief \~french
 * \fn setIOStateHistory
    * \param state
    * \param field
    */
    void setIOStateHistory(QHistoryState *state, QString field);

    /*!
    * \brief \~french
 * \fn historyValue
    * \param field
    * \return QHistoryState
    */
    QHistoryState* historyValue(QString field);

    QStringList statesList();


    QString previousStateField();

signals:
    /*signaux : messagers à envoyer ou transmettre*/

    /*!
    * \brief \~french
 * \fn clearAll
    */
    void clearAll();

    /*!
    * \brief \~french
 * \fn sendText
    * \param text
    * \param editable
    */
    void sendText(QString text, int row, int column);
    void sendTextForRow(QString text, int row);
    void sendTextAuto(QString text);

    /*!
    * \brief \~french
    * \fn resendText
    * \param text
    */
    void resendText(QString text,int row, int column);
    void resendTextForRow(QString text, int row);
    void resendTextAuto(QString text);

    /*!
    * \brief \~french
 * \fn receiveInput
    * \param input
    */
    void receiveInput(QString input);

    /*!
    * \brief \~french
    * \fn confirmInput
    */
    void confirmInput();

    /*!
    * \brief \~french
    * \fn validateInput
    */
    void validateInput();

    /*!
    * \brief \~french
    * \fn replaceInput
    * \param field
    */
    void replaceInput(QString field);

    /*!
    * \brief \~french
    * \fn cancelReplacement
    */
    void cancelReplacement();

    /*!
    * \brief \~french
    * \fn displayCalendar
    */
    void displayCalendar();

    /*!
    * \brief \~french
    * \fn displayFileDialog
    */
    void displayFileDialog();

    void displayChoiceList(QVariantList choices, int row);

    void displayProgressBar(qreal filledPercentage);

    void tableNameChanged();
    void ioContentChanged();
    void ioStatesHistoryChanged();
public slots:
    /*connecteurs : récepteurs de signaux*/

    /*!
    * \brief \~french
    * \fn setContentValue
    * \param content
    * \param field
    */
    void setContentValue(QVariant content, QString field);

    virtual void addState(QAbstractState *state);

    /*!
    * \brief \~french
    * \fn addState
    * \param state
    * \param field
    * \overrides
    */
    virtual void addState(SH_InOutState *astate, QString field="");
    /*!
        * \brief \~french
        * \fn addIOState
        * \param state
        * \param field
        * \overrides
        */
    void addIOState(SH_InOutState *state, QString field="");

    virtual void addState(SH_InOutStateMachine *astate, QString table="");
    /*!
    * \brief \~french
    * \fn addStateMachine
    * \param fsm
    */
    void addStateMachine(SH_InOutStateMachine* fsm, QString table="");

    /*!
    * \brief \~french
    * \fn addChildrenNextTransition
    * \param previousState
    * \param nextState
    */
    virtual void setStatesNextTransition(QAbstractState* previousState, QAbstractState *nextState);

    /*!
    * \brief
    * \fn addChildrenReplaceTransition
    * \param previousState
    * \param nextState
    */
    virtual void addChildrenReplaceTransition(QAbstractState *previousState, QAbstractState *nextState);
protected:


    /*!
    * \brief \~french
    * \fn isERunning
    * \return bool
    */
    bool isERunning();

    QStringList m_statesList;

    /*!
    * \brief \~french
    * \var this->m_ioContent
    */
    QVariantMap m_ioContent;

    /*!
    * \brief \~french
    * \var this->m_tableName
    */
    QString m_tableName;

    /*!
    * \brief \~french
    * \var this->m_ioStatesHistory
    */
    QMap<QString, QHistoryState *> m_ioStatesHistory;
};
/*}*/
#endif /* IOSTATEMACHINE_H*/
