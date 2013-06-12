#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H
#include "iostate.h"

class QuestionState : public IOState
{
    Q_OBJECT
public:
    QuestionState(QString question, QString name, QState *parent = 0);
    bool checkValidity();

    virtual QVariant givenAnswer() const;
    virtual void setGivenAnswer(const QVariant &givenAnswer);
    virtual void setInput(const QVariant &input);

    virtual bool isAnswerValid(const QVariant &givenAnswer) = 0;

signals:

public slots:


private:
    QVariant m_givenAnswer;
};

#endif // QUESTIONSTATE_H
