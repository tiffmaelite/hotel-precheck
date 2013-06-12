#ifndef DATEQUESTIONSTATE_H
#define DATEQUESTIONSTATE_H
#include "questionstate.h"

class DateQuestionState : public QuestionState
{
    Q_OBJECT
public:
    DateQuestionState(QString question, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // DATEQUESTIONSTATE_H
