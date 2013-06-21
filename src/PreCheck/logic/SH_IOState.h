#ifndef IOSTATE_H
#define IOSTATE_H
#include "SH_GenericDebugableState.h"
#include <QtCore>

/*!
\brief \~french 

 \class SH_IOState iostate.h "logic/iostate.h"
*/
class SH_InOutState : public SH_GenericState
{
    Q_OBJECT
public:
    /*!
\brief \~french 

 \fn SH_IOState
 \param output
 \param name
 \param parent
*/
    SH_InOutState(QString output, QString name, QState *parent = 0);

    /*!
    \brief \~french 

     \fn SH_input
     \return QVariant
    */
    virtual QVariant input() const;

    /*!
    \brief \~french 

     \fn SH_rawInput
     \return QVariant
    */
    virtual QVariant rawInput() const;

    /*!
    \brief \~french 

     \fn SH_output
     \return QString
    */
    virtual QString output() const;


    /*!
    \brief \~french 

     \fn SH_onExit
     \param event
    */
    void onExit(QEvent *event);

    /*!
    \brief \~french 
     \fn SH_visibility TODO comment this
     \return bool TODO comment this
    */
    bool visibility();

    /*!
    \brief \~french 
     \fn SH_display TODO comment this
     \param canDisplay TODO comment this
    */
    void display(bool canDisplay);

signals:
    /*!
    \brief \~french 

     \fn SH_sendOutput
     \param output
    */
    void sendOutput(QVariant output);
    /*!
    \brief \~french 

     \fn SH_resendInput
     \param input
    */
    void resendInput(QVariant input);

public slots:
    /*!
    \brief \~french 

     \fn SH_setInput
     \param input
    */
    virtual void setInput(const QVariant &input);
    /*!
    \brief \~french 

     \fn SH_setOutput
     \param output
    */
    virtual void setOutput(const QString &output);


    /*!
    \brief \~french 
     \fn SH_setVisibility TODO comment this
     \param isVisible TODO comment this
    */
    virtual void setVisibility(bool isVisible);

private:
    /*!
     *\brief \~french  m_input
     */
    QVariant m_input;
    /*!
     *\brief \~french  m_output
     */
    QString m_output;
    /*!
     *\brief \~french  m_isVisible
     */
    bool m_isVisible;
    /*!
     *\brief \~french  m_display
     */
    bool m_display;
};

#endif /* IOSTATE_H*/
