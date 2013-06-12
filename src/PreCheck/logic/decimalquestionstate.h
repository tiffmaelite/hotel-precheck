#ifndef DECIMALQUESTIONSTATE_H
#define DECIMALQUESTIONSTATE_H
#include "questionstate.h"

class DecimalQuestionState : public QuestionState
{
    Q_OBJECT
public:
    DecimalQuestionState(QString question, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // DECIMALQUESTIONSTATE_H
