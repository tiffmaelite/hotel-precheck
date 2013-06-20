#ifndef IOSTATEMACHINE_H
#define IOSTATEMACHINE_H

#include <QStateMachine>
#include <QHistoryState>
#include <QtCore>
#include "SH_NamedObject.h"
#include "SH_IOState.h"

/*!
 \brief

 \class SH_IOStateMachine iostatemachine.h "logic/iostatemachine.h"
*/
class SH_InOutStateMachine : public QStateMachine, SH_NamedObject
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn SH_IOStateMachine
 \param tableName
 \param name
 \param parent
*/
    SH_InOutStateMachine(QString tableName, QString name="", QObject *parent = 0);

    /*!
     \brief

     \fn SH_toString
     \return QString
    */
    QString toString();

    /*!
     \brief

     \fn SH_ioContent
     \return QVariantMap
    */
    QVariantMap ioContent() const;
    /*!
     \brief

     \fn SH_setIOcontent
     \param ioContent
    */
    void setIOcontent(const QVariantMap &ioContent);
    /*!
     \brief

     \fn SH_getContentValue
     \param field
     \return QVariant
    */
    QVariant getContentValue(QString field);

    /*!
     \brief

     \fn SH_tableName
     \return QString
    */
    QString tableName() const;
    /*!
     \brief

     \fn SH_setTableName
     \param tableName
    */
    void setTableName(const QString &tableName);

    /*!
     \brief

     \fn SH_setIOStateHistory
     \param state
     \param field
    */
    void setIOStateHistory(QHistoryState *state, QString field);
    /*!
     \brief

     \fn SH_historyValue
     \param field
     \return QHistoryState
    */
    QHistoryState* historyValue(QString field);

signals: /*messagers à envoyer ou transmettre*/
    /*!
     \brief

     \fn SH_next
    */
    void next();
    /*!
     \brief

     \fn SH_clearAll
    */
    void clearAll();
    /*!
     \brief

     \fn SH_sendText
     \param text
     \param editable
    */
    void sendText(QString text, bool editable=false);
    /*!
    \fn SH_sendText
    \param text
    \param editable
   */
    void resendText(QString text, bool editable=false);
    /*!
     \brief

     \fn SH_receiveInput
     \param input
    */
    void receiveInput(QString input);
    /*!
     \brief

     \fn SH_confirmInput
    */
    void confirmInput();
    /*!
     \brief

     \fn SH_validateInput
    */
    void validateInput();
    /*!
     \brief

     \fn SH_replaceInput
     \param field
    */
    void replaceInput(QString field);
    /*!
     \brief

     \fn SH_cancelReplacement
    */
    void cancelReplacement();
    /*!
     \brief

     \fn SH_displayCalendar
    */
    void displayCalendar();

    /*!
     \brief
     \fn SH_displayFileDialog TODO comment this
    */
    void displayFileDialog();

public slots: /*réception de messagers*/
    /*!
     \brief

     \fn SH_setContentValue
     \param content
     \param field
    */
    void setContentValue(QVariant content, QString field);
    /*!
     \brief

     \fn SH_addIOState
     \param state
     \param field
    */
    void addIOState(SH_InOutState *state, QString field);

    /*!
     \brief

     \fn SH_addIOStateMachine
     \param fsm
    */
    void addIOStateMachine(SH_InOutStateMachine* fsm);
    /*!
     \brief

     \fn SH_addChildrenNextTransition
     \param previousState
     \param nextState
    */
    void addChildrenNextTransition(QAbstractState* previousState, QAbstractState *nextState);

protected:
    /*!
     \brief

     \fn SH_ioStatesHistory
     \return QMap<QString, QHistoryState *>
    */
    QMap<QString, QHistoryState *> ioStatesHistory() const;
    /*!
     * \brief m_ioContent
     */
    QVariantMap m_ioContent;
    /*!
     * \brief m_tableName
     */
    QString m_tableName;
    /*!
     * \brief m_ioStatesHistory
     */
    QMap<QString, QHistoryState*> m_ioStatesHistory;


private:
    /*!
     \brief

     \fn SH_setIOStatesHistory
     \param QMap<QString
     \param ioStatesHistory
    */
    void setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory);
};

#endif /* IOSTATEMACHINE_H*/
