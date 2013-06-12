#ifndef IOSTATE_H
#define IOSTATE_H
#include "genericstate.h"
#include <QtCore>

class IOState : public GenericState
{
    Q_OBJECT
public:
    IOState(QString output, QString name, QState *parent = 0);

    virtual QVariant input() const;
    virtual QString output() const;
    void onEntry(QEvent *event);
    void onExit(QEvent *event);

signals:
    void sendOutput(QVariant output);
    void resendInput(QVariant input);

public slots:
    virtual void setInput(const QVariant &input);
    virtual void setOutput(const QString &output);

private:
    QVariant m_input;
    QString m_output;
};

#endif // IOSTATE_H
