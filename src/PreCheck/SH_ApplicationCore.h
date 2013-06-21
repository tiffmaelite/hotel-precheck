#ifndef RESTRICTIVEAPPLICATION_H
#define RESTRICTIVEAPPLICATION_H
#include "models/SH_User.h"
#include <QApplication>
#include "logic/SH_IOStateMachine.h"
/*!
\brief \~french  \~french Classe principale du coeur de l'application, avec laquelle communique l'interface graphique

 \class SH_ApplicationCore
\headerfile RestrictiveApplication.h "models/RestrictiveApplication.h"
*/
class SH_ApplicationCore : public QObject
{
    Q_OBJECT
    /*!
      \property currentUser
      \brief \~french
      */
    Q_PROPERTY(SH_User* currentUser READ user NOTIFY userChanged)
    /*!
      \property currentMode
      \brief \~french
      */
    Q_PROPERTY(AppMode currentMode READ mode WRITE setMode NOTIFY modeChanged)

    Q_ENUMS(AppMode)

public:
    /*!
    \brief \~french Énumération des modes possibles de l'application

     \enum AppMode
     */
    /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::CONNEXION
     \brief \~french Mode de l'application qui ne contient que le formulaire de connexion
     */
    /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::ACCUEIL
     \brief \~french Mode central de l'application qui permet d'accéder aux autres modes auxquels l'utilisateur a accès
     /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::RECEPTION
     \brief \~french Mode de l'application qui regroupe les interfaces liées aux activités d'un réceptionniste
     */
    /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::MANAGEMENT_X
     \brief \~french Mode de l'application qui regroupe les interfaces liées aux activités d'un responsable X (en lecture seulement) du service
     */
    /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::MANAGEMENT_Z
     \brief \~french Mode de l'application qui regroupe les interfaces liées aux activités d'un responsable Z (lecture et modifications) du service
     */
    /*!
     \value SH_ApplicationCore::AppMode SH_ApplicationCore::ADMINISTRATION
          \brief \~french Mode de l'application qui regroupe les interfaces liées aux activités d'un technicien en charge de paramétrer l'application ou de modifier ses données (comptes utilisateurs, chambres...)
    */
    enum AppMode { CONNEXION, ACCUEIL, RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };

    /*!
    \brief \~french

 \fn SH_ApplicationCore
 \param parent
    */
    SH_ApplicationCore(QObject* parent=0);

    /*!
    \brief \~french

     \fn SH_mode
     \return AppMode
    */
    AppMode mode() const;

    /*!
    \brief \~french

     \fn SH_user
     \return User
    */
    SH_User* user() const;
    /*Q_INVOKABLE User* currentUser() const;*/
    /*!
    \brief \~french

     \fn SH_init
    */
    void init();
    /*!
    \brief \~french

     \fn SH_setMode
     \param mode
    */
    void setMode(AppMode mode);


public slots:
    /*!
        \brief \~french
         \fn SH_balanceLogRoutine TODO comment this
         \return bool TODO comment this
        */
    bool balanceLogRoutine();
    /*!
    \brief \~french

     \fn SH_userExists
     \param login
     \return bool
    */
    bool userExists(QString login);
    /*!
    \brief \~french

     \fn SH_setUser
     \param login
     \param pass
     \return bool
    */
    bool setUser(QString login, QString pass);
    /*!
    \brief \~french

     \fn SH_userLogOut
     \return bool
    */
    bool userLogOut();

    /*!
    \brief \~french

     \fn SH_launchBookingsThread
     \return bool
    */
    bool launchBookingsThread();
    /*!
    \brief \~french

     \fn SH_launchBillThread
     \return bool
    */
    bool launchBillThread();
    /*!
    \brief \~french

     \fn SH_launchBillingsThread
     \return bool
    */
    Q_INVOKABLE bool launchBillingsThread();
    /*!
    \brief \~french

     \fn SH_cancelRunningThread
     \return bool
    */
    bool cancelRunningThread();

    /*!
    \brief \~french
     \fn SH_receiveInput TODO comment this
     \param in TODO comment this
    */
    void receiveInput(QString in);

    /*!
    \brief \~french
     \fn SH_receiveValidation TODO comment this
    */
    void receiveValidation();

    /*!
    \brief \~french
     \fn SH_receiveConfirmation TODO comment this
    */
    void receiveConfirmation();

    /*!
    \brief \~french

     \fn SH_replaceInput
     \param inputName
    */
    void replaceInput(QString inputName);
    /*!
    \brief \~french

     \fn SH_cancelReplacement
    */
    void cancelReplacement();

signals:
    /*!
    \brief \~french

     \fn SH_clearAll
    */
    void clearAll();
    /*!
    \brief \~french

     \fn SH_userChanged
     \param name
    */
    void userChanged(QVariant name);
    /*!
    \brief \~french

     \fn SH_modeChanged
     \param mode
    */
    void modeChanged(QVariant mode);

    /*!
    \brief \~french

     \fn SH_currentFSMchanged
    */
    void currentFSMchanged();
    /*!
    \brief \~french

     \fn SH_sendText
     \param text
    */
    void sendText(QString text);
    /*!
    \brief \~french

     \fn SH_resendText
     \param text
    */
    void resendText(QString text);
    /*!
    \brief \~french

     \fn SH_displayCalendar
    */
    void displayCalendar();
    /*!
    \brief \~french

     \fn SH_openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);

protected:
    /*!
    \brief \~french
     \fn SH_connectRunningThread TODO comment this
     \return bool TODO comment this
    */
    bool connectRunningThread();

private:
    /*!
     *\brief \~french  m_currentUser
     */
    SH_User* m_currentUser;
    /*!
     *\brief \~french  m_mode
     */
    AppMode m_mode;
    /*!
     *\brief \~french  m_currentFSM
     */
    SH_InOutStateMachine* m_currentFSM;
};

#endif /* RESTRICTIVEAPPLICATION_H*/
