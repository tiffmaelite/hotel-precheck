#include <QtGui>
#include <exception>
#include <QDebug>
#include <QtWidgets/QApplication>
#include "views/appQtOnly.h"


int mainQtOnly(int argc, char *argv[])
{
    try {
        qDebug() << "\n";
        //obligatoire en Qt avant de créer une application
        QApplication app(argc, argv);

        //initialisation/création de l'application (qui n'a donc pas de parent)
        PreCheckQtApp *appMainWindow = new PreCheckQtApp(0);

        QString appName = QString(QObject::tr("precheck"));
        QString locale = QLocale::system().name();
        QTranslator translator;
        if(!QFile::exists(appName+"_"+locale+".qm")) {
            locale = locale.section('_', 0, 0);
        }
        if(QFile::exists(appName+"_"+locale+".qm")) {
            translator.load(appName +"_"+ locale);
            app.installTranslator(&translator);
        }

        appMainWindow->fill();
        //lancement de l'application
        appMainWindow->centerAndResize();

        //exécution réelle de l'application
        return app.exec();
    }
    catch(std::exception &exception)
    {
        qDebug() << "ERREUR !";
        return 1;
    }
}
