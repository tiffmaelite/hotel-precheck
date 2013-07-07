#ifndef IOSTATE_H
#define IOSTATE_H
#include "SH_GenericDebugableState.h"
#include <QtCore>
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_IOState iostate.h "logic/iostate.h"
*/
class SH_InOutState : public SH_GenericState
{
    Q_OBJECT
    Q_PROPERTY(QVariant rawIntput READ rawInput NOTIFY rawInputChanged)
    Q_PROPERTY(QVariant intput READ input WRITE setInput NOTIFY inputChanged) //MEMBER m_input
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged) //MEMBER m_output
    Q_PROPERTY(bool visibility READ visibility WRITE setVisibility NOTIFY visibilityChanged) //MEMBER m_isVisible
    Q_PROPERTY(bool display READ display WRITE enableDisplay NOTIFY displayChanged) //MEMBER m_display

public:

    /*!
 * \brief \~french
 * \fn IOState
 * \param output
 * \param name
 * \param parent
*/
    SH_InOutState(QString output, QString name, QState *parent = 0);

    QString output() const { return m_output; }

    QVariant input() const { return m_input; }

    bool visibility() const { return m_isVisible; }

    /*!
    * \brief \~french
 * \fn rawInput
    * \return QVariant
    */
    virtual QVariant rawInput() const { return input(); }


    /*!
    * \brief \~french
    * \fn display
    * \return canDisplay
    */
    bool display() { return m_display; }

    void emitSendOutput();

    void emitResendInput();

    void enableDisplay(bool canDisplay) { m_display=canDisplay; emitSendOutput(); }

signals:

    /*!
    * \brief \~french
    * \fn sendOutput
    * \param output
    */
    void sendOutput(QVariant output);

    /*!
    * \brief \~french
    * \fn resendInput
    * \param input
    */
    void resendInput(QVariant input);
    void visibilityChanged();
    void inputChanged();
    void outputChanged();
    void rawInputChanged();
    void displayChanged();
public slots:

    /*!
    * \brief \~french
 * \fn setInput
    * \param input
    */
    virtual void setInput(const QVariant &input);

    /*!
    * \brief \~french
 * \fn setOutput
    * \param output
    */
    virtual void setOutput(const QString &output);

    /*!
    * \brief \~french
    * \fn setVisibility
    * \param isVisible
    */
    virtual void setVisibility(bool isVisible);
private:

    /*!
    * \brief \~french m_input
    */
    QVariant m_input;

    /*!
    * \brief \~french m_output
    */
    QString m_output;

    /*!
    * \brief \~french m_isVisible
    */
    bool m_isVisible;

    /*!
    * \brief \~french m_display
    */
    bool m_display;
};
/*}*/
#endif /* IOSTATE_H*/
