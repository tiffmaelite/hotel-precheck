#ifndef RESTRICTIVEAPPLICATION_H
#define RESTRICTIVEAPPLICATION_H
#include "models/SH_User.h"
#include <QApplication>
#include "logic/SH_IOStateMachine.h"
/*!
\brief \~french La classe SH_ApplicationCore est la classe principale du coeur de l'application; c'est avec elle exclusivement que communique l'interface graphique

 \class SH_ApplicationCore
\headerfile RestrictiveApplication.h "models/RestrictiveApplication.h"
*/
class SH_ApplicationCore : public QObject
{
    Q_OBJECT
    /*!
      \brief \~french L'utilisateur actuellement connecté (un objet SH_USer invalide si aucun utilisateur n'est connecté)
      \property currentUser
      */
    Q_PROPERTY(SH_User* currentUser READ user NOTIFY userChanged)
    /*!
      \brief \~french Le mode actuel de l'application
      \property currentMode
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
    \brief \~french Construit un objet SH_ApplicationCore
 \fn ApplicationCore
 \param parent L'objet parent
    */
    SH_ApplicationCore(QObject* parent=0);

    /*!
    \brief \~french Retourne le mode actuel de l'application
     \fn mode
     \return AppMode
    */
    AppMode mode() const;

    /*!
    \brief \~french retourne l'utilisateur actuellement connecté
     \fn user
     \return User
    */
    SH_User* user() const;

    /*!
    \brief \~french Initialise l'application avec un utilisateur invalide, et le mode \a CONNEXION
     \fn init
    */
    void init();

    /*!
    \brief \~french Modifie le mode dans lequel se trouve l'application
     \fn setMode
     \param mode Le nouveau mode de l'application
    */
    void setMode(AppMode mode);


public slots:
    /*!
        \brief \~french
         \fn balanceLogRoutine
         \return bool
        */
    bool balanceLogRoutine();

    /*!
    \brief \~french Vérifie s'il existe un utilisateur avec le pseudo fourni
     \fn userExists
     \param login Le nom d'utilisateur pour lequel il faut effectuer une vérification
     \return bool
    */
    bool userExists(QString login);

    /*!
    \brief \~french Modifie l'utilisateur actuel
     \fn setUser
     \param login Le nom d'utilisateur du nouvel utilisateur
     \param pass Le mot de passe du nouvel utilisateur
     \return bool Retourne \a true si un utilisateur correspondant aux pseudo et mot de passe fournis a été trouvé et que l'utilisateur actuel a pu être modifié avec cet utilisateur; \a false sinon
    */
    bool setUser(QString login, QString pass);

    /*!
    \brief \~french "Déconnecte" l'utilisateur actuel, et le remplace par un utilisateur invalide
     \fn userLogOut
     \return bool Retourne \a true si le changement a réussi, \a false sinon
    */
    bool userLogOut();

    /*!
    \brief \~french
     \fn launchBookingsThread
     \return bool
    */
    bool launchBookingsThread();

    /*!
    \brief \~french
     \fn launchBillThread
     \return bool
    */
    bool launchBillThread();

    /*!
    \brief \~french
     \fn launchBillingsThread
     \return bool
    */
    bool launchBillingsThread();

    /*!
    \brief \~french
     \fn cancelRunningThread
     \return bool
    */
    bool cancelRunningThread();

    /*!
    \brief \~french
     \fn receiveInput
     \param in
    */
    void receiveInput(QString in);

    /*!
    \brief \~french
     \fn receiveValidation
    */
    void receiveValidation();

    /*!
    \brief \~french
     \fn receiveConfirmation
    */
    void receiveConfirmation();

    /*!
    \brief \~french
     \fn replaceInput
     \param inputName
    */
    void replaceInput(QString inputName);

    /*!
    \brief \~french
     \fn cancelReplacement
    */
    void cancelReplacement();

signals:
    /*!
    \brief \~french
     \fn clearAll
    */
    void clearAll();

    /*!
    \brief \~french
     \fn userChanged
     \param name
    */
    void userChanged(QVariant name);

    /*!
    \brief \~french

     \fn modeChanged
     \param mode
    */
    void modeChanged(QVariant mode);

    /*!
    \brief \~french

     \fn currentFSMchanged
    */
    void currentFSMchanged();

    /*!
    \brief \~french
     \fn sendText
     \param text
    */
    void sendText(QString text);

    /*!
    \brief \~french
     \fn resendText
     \param text
    */
    void resendText(QString text);

    /*!
    \brief \~french
     \fn displayCalendar
    */
    void displayCalendar();

    /*!
    \brief \~french
     \fn openTab
     \param tabPos
    */
    void openTab(QVariant tabPos);

protected:
    /*!
    \brief \~french
     \fn connectRunningThread
     \return bool
    */
    bool connectRunningThread();

private:
    /*!
     *\brief \~french
     *\var m_currentUser
     */
    SH_User* m_currentUser;
    /*!
     *\brief \~french
     *\var m_mode
     */
    AppMode m_mode;
    /*!
     *\brief \~french
     *\var m_currentFSM
     */
    SH_InOutStateMachine* m_currentFSM;
};

#endif /* RESTRICTIVEAPPLICATION_H*/
