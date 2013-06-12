#ifndef STATEMENTSTATE_H
#define STATEMENTSTATE_H
#include "iostate.h"

class StatementState : public IOState
{
    Q_OBJECT
public:
    StatementState(QString output, QString name, QState *parent = 0);

    void setInput(const QVariant &input);
    void onEntry(QEvent *event);

signals:

public slots:

};

#endif // STATEMENTSTATE_H
