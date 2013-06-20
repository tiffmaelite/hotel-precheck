#ifndef RESTRICTIVEAPPLICATION_H
#define RESTRICTIVEAPPLICATION_H
#include "models/SH_User.h"
#include <QApplication>
#include "logic/SH_IOStateMachine.h"
/*!
 \brief

 \class SH_RestrictiveApplication RestrictiveApplication.h "models/RestrictiveApplication.h"
*/
class SH_ApplicationCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SH_User* currentUser READ user NOTIFY userChanged)
    Q_PROPERTY(AppMode currentMode READ mode WRITE setMode NOTIFY modeChanged)

    Q_ENUMS(AppMode)

public:
    /*!
     \brief

     \enum AppMode
    */
    enum AppMode { CONNEXION, ACCUEIL, RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };
    /*!
 \brief

 \fn SH_RestrictiveApplication
 \param parent
*/
    SH_ApplicationCore(QObject* parent=0);
    /*!
     \brief

     \fn SH_mode
     \return AppMode
    */
    AppMode mode() const;
    /*!
     \brief

     \fn SH_user
     \return User
    */
    SH_User* user() const;
    /*Q_INVOKABLE User* currentUser() const;*/
    /*!
     \brief

     \fn SH_init
    */
    void init();
    /*!
     \brief

     \fn SH_setMode
     \param mode
    */
    void setMode(AppMode mode);


public slots:
    /*!
         \brief
         \fn SH_balanceLogRoutine TODO comment this
         \return bool TODO comment this
        */
    bool balanceLogRoutine();
    /*!
     \brief

     \fn SH_userExists
     \param login
     \return bool
    */
    bool userExists(QString login);
    /*!
     \brief

     \fn SH_setUser
     \param login
     \param pass
     \return bool
    */
    bool setUser(QString login, QString pass);
    /*!
     \brief

     \fn SH_userLogOut
     \return bool
    */
    bool userLogOut();

    /*!
     \brief

     \fn SH_launchBookingsThread
     \return bool
    */
    bool launchBookingsThread();
    /*!
     \brief

     \fn SH_launchBillThread
     \return bool
    */
    bool launchBillThread();
    /*!
     \brief

     \fn SH_launchBillingsThread
     \return bool
    */
    Q_INVOKABLE bool launchBillingsThread();
    /*!
     \brief

     \fn SH_cancelRunningThread
     \return bool
    */
    bool cancelRunningThread();

    /*!
     \brief
     \fn SH_receiveInput TODO comment this
     \param in TODO comment this
    */
    void receiveInput(QString in);

    /*!
     \brief
     \fn SH_receiveValidation TODO comment this
    */
    void receiveValidation();

    /*!
     \brief
     \fn SH_receiveConfirmation TODO comment this
    */
    void receiveConfirmation();

    /*!
     \brief

     \fn SH_replaceInput
     \param inputName
    */
    void replaceInput(QString inputName);
    /*!
     \brief

     \fn SH_cancelReplacement
    */
    void cancelReplacement();

signals:
    /*!
     \brief

     \fn SH_clearAll
    */
    void clearAll();
    /*!
     \brief

     \fn SH_userChanged
     \param name
    */
    void userChanged(QVariant name);
    /*!
     \brief

     \fn SH_modeChanged
     \param mode
    */
    void modeChanged(QVariant mode);

    /*!
     \brief

     \fn SH_currentFSMchanged
    */
    void currentFSMchanged();
    /*!
     \brief

     \fn SH_sendText
     \param text
    */
    void sendText(QString text);
    /*!
     \brief

     \fn SH_resendText
     \param text
    */
    void resendText(QString text);
    /*!
     \brief

     \fn SH_displayCalendar
    */
    void displayCalendar();
    /*!
     \brief

     \fn SH_openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);

protected:
    /*!
     \brief
     \fn SH_connectRunningThread TODO comment this
     \return bool TODO comment this
    */
    bool connectRunningThread();

private:
    /*!
     * \brief m_currentUser
     */
    SH_User* m_currentUser;
    /*!
     * \brief m_mode
     */
    AppMode m_mode;
    /*!
     * \brief m_currentFSM
     */
    SH_InOutStateMachine* m_currentFSM;
};

#endif /* RESTRICTIVEAPPLICATION_H*/
