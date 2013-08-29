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
    Q_PROPERTY(QString fieldName READ fieldName WRITE setField) //MEMBER m_field
    Q_PROPERTY(QVariant displayableInput READ displayableInput NOTIFY displayableInputChanged)
    Q_PROPERTY(QVariant checkedInput READ checkedInput NOTIFY enteredInputChanged)
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

    QString output() { return this->m_output; }

    QVariant input() { return this->m_input; }


    bool visibility() { return this->m_isVisible; }

    QString fieldName() { return this->m_field; }

    void setField(QString field) { this->m_field = field; }

    /*!
    * \brief \~french
 * \fn displayableInput
    * \return QVariant
    */
    virtual QVariant displayableInput() = 0;

    virtual QVariant checkedInput() = 0;


    /*!
    * \brief \~french
    * \fn display
    * \return canDisplay
    */
    bool display() { return this->m_display; }

    void emitSendOutput();

    void emitResendInput();

    void enableDisplay(bool canDisplay) { this->m_display=canDisplay; emit displayChanged(); }

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
    void inputChanged(QVariant newInput);
    void outputChanged(QString newOutput);
    void displayableInputChanged();
    void displayChanged();
    void enteredInputChanged();

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
    * \brief \~french this->m_input
    */
    QVariant m_input;

    /*!
    * \brief \~french this->m_output
    */
    QString m_output;

    /*!
    * \brief \~french this->m_isVisible
    */
    bool m_isVisible;

    /*!
    * \brief \~french this->m_display
    */
    bool m_display;

    QString m_field;
};
/*}*/
#endif /* IOSTATE_H*/
