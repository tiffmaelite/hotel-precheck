#ifndef IOSTATEMACHINE_H
#define IOSTATEMACHINE_H

#include <QStateMachine>
#include <QHistoryState>
#include <QtCore>
#include "namedobject.h"
#include "iostate.h"

class IOStateMachine : public QStateMachine, NamedObject
{
    Q_OBJECT
public:
    IOStateMachine(QString tableName, QString name="", QObject *parent = 0);

    QString toString();

    QVariantMap ioContent() const;
    void setIOcontent(const QVariantMap &ioContent);
    QVariant getContentValue(QString field);

    QString tableName() const;
    void setTableName(const QString &tableName);

    void setIOStateHistory(QHistoryState *state, QString field);
    QHistoryState* historyValue(QString field);

signals: //messagers à envoyer ou transmettre
    void next();
    void sendText(QVariant text, bool editable=false);
    void receiveInput(QString input);
    void confirmInput();
    void validateInput();
    void replaceInput(QString field);
    void cancelReplacement();
    void displayCalendar();

public slots: //réception de messagers
    void setContentValue(QVariant content, QString field);
    void addIOState(IOState *state, QString field);
    void addIOStateMachine(IOStateMachine* fsm);
    void addChildrenNextTransition(GenericState* previousState, GenericState* nextState);

protected:
    QMap<QString, QHistoryState *> ioStatesHistory() const;

    QVariantMap m_ioContent;
    QString m_tableName;
    QMap<QString, QHistoryState*> m_ioStatesHistory;


private:
    void setIOStatesHistory(const QMap<QString, QHistoryState *> &ioStatesHistory);
};

#endif // IOSTATEMACHINE_H
