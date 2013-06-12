#ifndef IOSTATE_H
#define IOSTATE_H
#include "genericstate.h"
#include <QtCore>

/*!
 \brief

 \class IOState iostate.h "logic/iostate.h"
*/
class IOState : public GenericState
{
    Q_OBJECT
public:
/*!
 \brief

 \fn IOState
 \param output
 \param name
 \param parent
*/
    IOState(QString output, QString name, QState *parent = 0);

    /*!
     \brief

     \fn input
     \return QVariant
    */
    virtual QVariant input() const;
    /*!
     \brief

     \fn output
     \return QString
    */
    virtual QString output() const;
    /*!
     \brief

     \fn onEntry
     \param event
    */
    void onEntry(QEvent *event);
    /*!
     \brief

     \fn onExit
     \param event
    */
    void onExit(QEvent *event);

signals:
    /*!
     \brief

     \fn sendOutput
     \param output
    */
    void sendOutput(QVariant output);
    /*!
     \brief

     \fn resendInput
     \param input
    */
    void resendInput(QVariant input);

public slots:
    /*!
     \brief

     \fn setInput
     \param input
    */
    virtual void setInput(const QVariant &input);
    /*!
     \brief

     \fn setOutput
     \param output
    */
    virtual void setOutput(const QString &output);

private:
    QVariant m_input; /*!< TODO */
    QString m_output; /*!< TODO */
};

#endif // IOSTATE_H
