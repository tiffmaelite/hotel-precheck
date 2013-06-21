#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QObject>

/*!
\brief \~french 

 \class SH_MessageManager message_manager.h "views/message_manager.h"
*/
class SH_MessageManager: QObject
{
    Q_OBJECT

    Q_ENUMS(ErrorMode)

public:
    /*!
    \brief \~french 

     \enum ErrorMode
    */
    enum ErrorMode { ERROR, TEST, DEBUG, DEBUG_VERBOSE, RELEASE };

    /*!
    \brief \~french 

     \fn SH_errorMessage
     \param message
     \param title
    */
    static void errorMessage(QString message, QString title = "Erreur");
    /*!
    \brief \~french 

     \fn SH_successMessage
     \param message
     \param title
    */
    static void successMessage(QString message, QString title ="Réussite");
    /*!
    \brief \~french 

     \fn SH_infoMessage
     \param message
     \param title
    */
    static void infoMessage(QString message,QString title ="Info");

};

#endif /* ERRORMESSAGE_H*/
