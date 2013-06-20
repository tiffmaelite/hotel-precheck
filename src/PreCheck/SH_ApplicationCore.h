#ifndef RESTRICTIVEAPPLICATION_H
#define RESTRICTIVEAPPLICATION_H
#include "models/SH_User.h"
#include <QApplication>
#include "logic/SH_IOStateMachine.h"
/*!
 \brief

 \class RestrictiveApplication RestrictiveApplication.h "models/RestrictiveApplication.h"
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

 \fn RestrictiveApplication
 \param parent
*/
    SH_ApplicationCore(QObject* parent=0);
    /*!
     \brief

     \fn mode
     \return AppMode
    */
    AppMode mode() const;
    /*!
     \brief

     \fn user
     \return User
    */
    SH_User* user() const;
    //Q_INVOKABLE User* currentUser() const;
    /*!
     \brief

     \fn init
    */
    void init();
    /*!
     \brief

     \fn setMode
     \param mode
    */
    void setMode(AppMode mode);


public slots:
    /*!
         \brief
         \fn balanceLogRoutine TODO comment this
         \return bool TODO comment this
        */
    bool balanceLogRoutine();
    /*!
     \brief

     \fn userExists
     \param login
     \return bool
    */
    bool userExists(QString login);
    /*!
     \brief

     \fn setUser
     \param login
     \param pass
     \return bool
    */
    bool setUser(QString login, QString pass);
    /*!
     \brief

     \fn userLogOut
     \return bool
    */
    bool userLogOut();

    /*!
     \brief

     \fn launchBookingsThread
     \return bool
    */
    bool launchBookingsThread();
    /*!
     \brief

     \fn launchBillThread
     \return bool
    */
    bool launchBillThread();
    /*!
     \brief

     \fn launchBillingsThread
     \return bool
    */
    Q_INVOKABLE bool launchBillingsThread();
    /*!
     \brief

     \fn cancelRunningThread
     \return bool
    */
    bool cancelRunningThread();

    /*!
     \brief
     \fn receiveInput TODO comment this
     \param in TODO comment this
    */
    void receiveInput(QString in);

    /*!
     \brief
     \fn receiveValidation TODO comment this
    */
    void receiveValidation();

    /*!
     \brief
     \fn receiveConfirmation TODO comment this
    */
    void receiveConfirmation();

    /*!
     \brief

     \fn replaceInput
     \param inputName
    */
    void replaceInput(QString inputName);
    /*!
     \brief

     \fn cancelReplacement
    */
    void cancelReplacement();

signals:
    /*!
     \brief

     \fn clearAll
    */
    void clearAll();
    /*!
     \brief

     \fn userChanged
     \param name
    */
    void userChanged(QVariant name);
    /*!
     \brief

     \fn modeChanged
     \param mode
    */
    void modeChanged(QVariant mode);

    /*!
     \brief

     \fn currentFSMchanged
    */
    void currentFSMchanged();
    /*!
     \brief

     \fn sendText
     \param text
    */
    void sendText(QString text);
    /*!
     \brief

     \fn resendText
     \param text
    */
    void resendText(QString text);
    /*!
     \brief

     \fn displayCalendar
    */
    void displayCalendar();
    /*!
     \brief

     \fn openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);

protected:
    /*!
     \brief
     \fn connectRunningThread TODO comment this
     \return bool TODO comment this
    */
    bool connectRunningThread();

private:
    SH_User* m_currentUser; /*!< TODO */
    AppMode m_mode; /*!< TODO */
    SH_InOutStateMachine* m_currentFSM; /*!< TODO */
};

#endif // RESTRICTIVEAPPLICATION_H
