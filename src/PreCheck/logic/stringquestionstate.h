#ifndef STRINGQUESTIONSTATE_H
#define STRINGQUESTIONSTATE_H
#include "questionstate.h"

class StringQuestionState : public QuestionState
{
    Q_OBJECT
public:
    StringQuestionState(QString question, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // STRINGQUESTIONSTATE_H
