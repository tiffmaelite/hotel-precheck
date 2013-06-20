#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QObject>

/*!
 \brief

 \class SH_MessageManager message_manager.h "views/message_manager.h"
*/
class SH_MessageManager: QObject
{
    Q_OBJECT

    Q_ENUMS(ErrorMode)

public:
    /*!
     \brief

     \enum ErrorMode
    */
    enum ErrorMode { ERROR, TEST, DEBUG, DEBUG_VERBOSE, RELEASE };

    /*!
     \brief

     \fn SH_errorMessage
     \param message
     \param title
    */
    static void errorMessage(QString message, QString title = "Erreur");
    /*!
     \brief

     \fn SH_successMessage
     \param message
     \param title
    */
    static void successMessage(QString message, QString title ="Réussite");
    /*!
     \brief

     \fn SH_infoMessage
     \param message
     \param title
    */
    static void infoMessage(QString message,QString title ="Info");

};

#endif /* ERRORMESSAGE_H*/
