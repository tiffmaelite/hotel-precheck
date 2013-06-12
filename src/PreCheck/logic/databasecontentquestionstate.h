#ifndef DATABASECONTENTQUESTIONSTATE_H
#define DATABASECONTENTQUESTIONSTATE_H
#include "questionstate.h"

class DatabaseContentQuestionState : public QuestionState
{
    Q_OBJECT
public:
    DatabaseContentQuestionState(QString question, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // DATABASECONTENTQUESTIONSTATE_H
