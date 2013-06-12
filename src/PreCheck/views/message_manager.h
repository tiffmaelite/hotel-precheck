#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QObject>

/*!
 \brief

 \class MessageManager message_manager.h "views/message_manager.h"
*/
class MessageManager: QObject
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

     \fn errorMessage
     \param message
     \param title
    */
    static void errorMessage(QString message, QString title = "Erreur");
    /*!
     \brief

     \fn successMessage
     \param message
     \param title
    */
    static void successMessage(QString message, QString title ="Réussite");
    /*!
     \brief

     \fn infoMessage
     \param message
     \param title
    */
    static void infoMessage(QString message,QString title ="Info");

protected:
    static ErrorMode errorMode; /*!< TODO */

};

#endif // ERRORMESSAGE_H
