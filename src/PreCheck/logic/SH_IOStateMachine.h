#ifndef IOSTATEMACHINE_H
#define IOSTATEMACHINE_H
#include <QStateMachine>
#include <QHistoryState>
#include <QtCore>
#include "SH_GenericDebugableStateMachine.h"
#include "SH_IOState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_IOStateMachine iostatemachine.h "logic/iostatemachine.h"
*/
class SH_InOutStateMachine : public SH_GenericStateMachine
{
    Q_OBJECT
public:

    /*!
 * \brief \~french
 * \fn IOStateMachine
 * \param tableName
 * \param name
 * \param parent
*/
    SH_InOutStateMachine(QString tableName, QString name="", QObject *parent = 0);

    /*!
    * \brief \~french
 * \fn ioContent
    * \return QVariantMap
    */
    QVariantMap ioContent() const;

    /*!
    * \brief \~french
 * \fn setIOcontent
    * \param ioContent
    */
    void setIOcontent(const QVariantMap &ioContent);

    /*!
    * \brief \~french
 * \fn getContentValue
    * \param field
    * \return QVariant
    */
    QVariant getContentValue(QString field);

    /*!
    * \brief \~french
 * \fn tableName
    * \return QString
    */
    QString tableName() const;

    /*!
    * \brief \~french
 * \fn setTableName
    * \param tableName
    */
    void setTableName(const QString &tableName);

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
    void sendText(QString text, bool editable=false);

    /*!
    * \fn sendText
    * \param text
    * \param editable
 */
    void resendText(QString text, bool editable=false);

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

    void displayChoiceList(QVariantList choices);
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
    * \fn ioStatesHistory
    * \return QMap<QString, QHistoryState *>
    */
    QMap<QString, QHistoryState *> ioStatesHistory() const;

    /*!
    * \brief \~french
    * \fn isERunning
    * \return bool
    */
    bool isERunning();

    /*!
    * \brief \~french
    * \var m_ioContent
    */
    QVariantMap m_ioContent;

    /*!
    * \brief \~french
    * \var m_tableName
    */
    QString m_tableName;

    /*!
    * \brief \~french
    * \var m_ioStatesHistory
    */
    QMap<QString, QHistoryState*> m_ioStatesHistory;
private:

    /*!
    * \brief \~french
    * \fn setIOStatesHistory
    * \param QMap<QString
    * \param ioStatesHistory
    */
    void setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory);
};
/*}*/
#endif /* IOSTATEMACHINE_H*/
