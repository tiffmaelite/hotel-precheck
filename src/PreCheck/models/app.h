#include <QObject>

#ifndef APP_H
#define APP_H

class App : public QObject
{
    Q_OBJECT

    Q_ENUMS(AppMode)
public:
    enum AppMode { CONNEXION, RECEPTION, MANAGEMENT_X, MANAGEMENT_Z, ADMINISTRATION };
};

#endif // APP_H
