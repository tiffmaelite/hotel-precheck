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

     \fn rawInput
     \return QVariant
    */
    virtual QVariant rawInput() const;

    /*!
     \brief

     \fn output
     \return QString
    */
    virtual QString output() const;
    /*!

    /*!
     \brief

     \fn onExit
     \param event
    */
    void onExit(QEvent *event);

    /*!
     \brief
     \fn visibility TODO comment this
     \return bool TODO comment this
    */
    bool visibility();

    /*!
     \brief
     \fn display TODO comment this
     \param canDisplay TODO comment this
    */
    void display(bool canDisplay);

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


    /*!
     \brief
     \fn setVisibility TODO comment this
     \param isVisible TODO comment this
    */
    virtual void setVisibility(bool isVisible);

private:
    QVariant m_input; /*!< TODO */
    QString m_output; /*!< TODO */
    bool m_isVisible; /*!< TODO */
    bool m_display;
};

#endif // IOSTATE_H
