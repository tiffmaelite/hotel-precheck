#ifndef IOSTATEMACHINE_H
#define IOSTATEMACHINE_H

#include <QStateMachine>
#include <QHistoryState>
#include <QtCore>
#include "namedobject.h"
#include "iostate.h"

/*!
 \brief

 \class IOStateMachine iostatemachine.h "logic/iostatemachine.h"
*/
class IOStateMachine : public QStateMachine, NamedObject
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn IOStateMachine
 \param tableName
 \param name
 \param parent
*/
    IOStateMachine(QString tableName, QString name="", QObject *parent = 0);

    /*!
     \brief

     \fn toString
     \return QString
    */
    QString toString();

    /*!
     \brief

     \fn ioContent
     \return QVariantMap
    */
    QVariantMap ioContent() const;
    /*!
     \brief

     \fn setIOcontent
     \param ioContent
    */
    void setIOcontent(const QVariantMap &ioContent);
    /*!
     \brief

     \fn getContentValue
     \param field
     \return QVariant
    */
    QVariant getContentValue(QString field);

    /*!
     \brief

     \fn tableName
     \return QString
    */
    QString tableName() const;
    /*!
     \brief

     \fn setTableName
     \param tableName
    */
    void setTableName(const QString &tableName);

    /*!
     \brief

     \fn setIOStateHistory
     \param state
     \param field
    */
    void setIOStateHistory(QHistoryState *state, QString field);
    /*!
     \brief

     \fn historyValue
     \param field
     \return QHistoryState
    */
    QHistoryState* historyValue(QString field);

signals: //messagers à envoyer ou transmettre
    /*!
     \brief

     \fn next
    */
    void next();
    /*!
     \brief

     \fn clearAll
    */
    void clearAll();
    /*!
     \brief

     \fn sendText
     \param text
     \param editable
    */
    void sendText(QString text, bool editable=false);
    /*!
    \fn sendText
    \param text
    \param editable
   */
    void resendText(QString text, bool editable=false);
    /*!
     \brief

     \fn receiveInput
     \param input
    */
    void receiveInput(QString input);
    /*!
     \brief

     \fn confirmInput
    */
    void confirmInput();
    /*!
     \brief

     \fn validateInput
    */
    void validateInput();
    /*!
     \brief

     \fn replaceInput
     \param field
    */
    void replaceInput(QString field);
    /*!
     \brief

     \fn cancelReplacement
    */
    void cancelReplacement();
    /*!
     \brief

     \fn displayCalendar
    */
    void displayCalendar();

    /*!
     \brief
     \fn displayFileDialog TODO comment this
    */
    void displayFileDialog();

public slots: //réception de messagers
    /*!
     \brief

     \fn setContentValue
     \param content
     \param field
    */
    void setContentValue(QVariant content, QString field);
    /*!
     \brief

     \fn addIOState
     \param state
     \param field
    */
    void addIOState(IOState *state, QString field);

    /*!
     \brief

     \fn addIOStateMachine
     \param fsm
    */
    void addIOStateMachine(IOStateMachine* fsm);
    /*!
     \brief

     \fn addChildrenNextTransition
     \param previousState
     \param nextState
    */
    void addChildrenNextTransition(QAbstractState* previousState, QAbstractState *nextState);

protected:
    /*!
     \brief

     \fn ioStatesHistory
     \return QMap<QString, QHistoryState *>
    */
    QMap<QString, QHistoryState *> ioStatesHistory() const;

    QVariantMap m_ioContent; /*!< TODO */
    QString m_tableName; /*!< TODO */
    QMap<QString, QHistoryState*> m_ioStatesHistory; /*!< TODO */


private:
    /*!
     \brief

     \fn setIOStatesHistory
     \param QMap<QString
     \param ioStatesHistory
    */
    void setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory);
};

#endif // IOSTATEMACHINE_H
