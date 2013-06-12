#ifndef NUMERICQUESTIONSTATE_H
#define NUMERICQUESTIONSTATE_H
#include "questionstate.h"

class NumericQuestionState : public QuestionState
{
    Q_OBJECT
public:
    NumericQuestionState(QString question, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // NUMERICQUESTIONSTATE_H
