#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QObject>

class MessageManager
{

public:
    static void errorMessage(QString message);
    static void successMessage(QString message);
    static QString parseMessage(QString message, QString values);

protected:
    static int errorMode;
    
};

#endif // ERRORMESSAGE_H
