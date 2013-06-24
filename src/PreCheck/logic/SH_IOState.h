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

 \fn IOState
 \param output
 \param name
 \param parent
*/
    SH_InOutState(QString output, QString name, QState *parent = 0);

    /*!
    \brief \~french 

     \fn input
     \return QVariant
    */
    virtual QVariant input() const;

    /*!
    \brief \~french 

     \fn rawInput
     \return QVariant
    */
    virtual QVariant rawInput() const;

    /*!
    \brief \~french 

     \fn output
     \return QString
    */
    virtual QString output() const;


    /*!
    \brief \~french 

     \fn onExit
     \param event
    */
    void onExit(QEvent *event);

    /*!
    \brief \~french 
     \fn visibility 
     \return bool 
    */
    bool visibility();

    /*!
    \brief \~french 
     \fn display 
     \param canDisplay 
    */
    void display(bool canDisplay);

signals:
    /*!
    \brief \~french 

     \fn sendOutput
     \param output
    */
    void sendOutput(QVariant output);
    /*!
    \brief \~french 

     \fn resendInput
     \param input
    */
    void resendInput(QVariant input);

public slots:
    /*!
    \brief \~french 

     \fn setInput
     \param input
    */
    virtual void setInput(const QVariant &input);
    /*!
    \brief \~french 

     \fn setOutput
     \param output
    */
    virtual void setOutput(const QString &output);


    /*!
    \brief \~french 
     \fn setVisibility 
     \param isVisible 
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
