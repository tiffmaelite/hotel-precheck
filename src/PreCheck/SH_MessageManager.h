#ifndef SH_MessageManager_H
#define SH_MessageManager_H

#include <QObject>


/*namespace SimplHotel
{*/

/*!
 * \brief \~french
 * \class SH_MessageManager
 * \headerfile message_manager.h "views/message_manager.h"
*/
class SH_MessageManager: QObject
{
    Q_OBJECT

    Q_ENUMS(ErrorMode)

public:

    /*!
    * \brief \~french
    * \enum ErrorMode
    */
    enum ErrorMode { ERROR, TEST, DEBUG, DEBUG_VERBOSE, RELEASE };


    /*!
    * \brief \~french
    * \fn errorMessage
    * \param message
    * \param title
    */
    static void errorMessage(QString message, QString title = "Erreur");

    /*!
    * \brief \~french
    * \fn successMessage
    * \param message
    * \param title
    */
    static void successMessage(QString message, QString title ="Réussite");

    /*!
    * \brief \~french
    * \fn infoMessage
    * \param message
    * \param title
    */
    static void infoMessage(QString message,QString title ="Info");


    /*!
    * \brief \~french
    * \fn debugMessage
    * \param message
    * \param title
    */
    static void debugMessage(QString message, QString title = "Trace");
};

/*}*/
#endif /* SH_MessageManager_H*/
