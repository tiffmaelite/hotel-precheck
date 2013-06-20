#ifndef IOSTATE_H
#define IOSTATE_H
#include "SH_GenericDebugableState.h"
#include <QtCore>

/*!
 \brief

 \class SH_IOState iostate.h "logic/iostate.h"
*/
class SH_InOutState : public SH_GenericState
{
    Q_OBJECT
public:
    /*!
 \brief

 \fn SH_IOState
 \param output
 \param name
 \param parent
*/
    SH_InOutState(QString output, QString name, QState *parent = 0);

    /*!
     \brief

     \fn SH_input
     \return QVariant
    */
    virtual QVariant input() const;

    /*!
     \brief

     \fn SH_rawInput
     \return QVariant
    */
    virtual QVariant rawInput() const;

    /*!
     \brief

     \fn SH_output
     \return QString
    */
    virtual QString output() const;


    /*!
     \brief

     \fn SH_onExit
     \param event
    */
    void onExit(QEvent *event);

    /*!
     \brief
     \fn SH_visibility TODO comment this
     \return bool TODO comment this
    */
    bool visibility();

    /*!
     \brief
     \fn SH_display TODO comment this
     \param canDisplay TODO comment this
    */
    void display(bool canDisplay);

signals:
    /*!
     \brief

     \fn SH_sendOutput
     \param output
    */
    void sendOutput(QVariant output);
    /*!
     \brief

     \fn SH_resendInput
     \param input
    */
    void resendInput(QVariant input);

public slots:
    /*!
     \brief

     \fn SH_setInput
     \param input
    */
    virtual void setInput(const QVariant &input);
    /*!
     \brief

     \fn SH_setOutput
     \param output
    */
    virtual void setOutput(const QString &output);


    /*!
     \brief
     \fn SH_setVisibility TODO comment this
     \param isVisible TODO comment this
    */
    virtual void setVisibility(bool isVisible);

private:
    /*!
     * \brief m_input
     */
    QVariant m_input;
    /*!
     * \brief m_output
     */
    QString m_output;
    /*!
     * \brief m_isVisible
     */
    bool m_isVisible;
    /*!
     * \brief m_display
     */
    bool m_display;
};

#endif /* IOSTATE_H*/
