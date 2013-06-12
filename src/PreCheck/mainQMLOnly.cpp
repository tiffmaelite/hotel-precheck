#include <QtWidgets/QApplication>
#include <QtQml>
#include <QtQuick>
#include "models/billings_table_model.h"

int mainQmlOnly(int argc, char *argv[])
{
    qDebug() << "\n";
    QApplication app(argc, argv);

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

    QQmlEngine engine;

    qmlRegisterType<BillingsTableModel>("PreCheck", 1, 0, "Billings");

    QQmlComponent component(&engine);
    //component.loadUrl(QUrl("../src/PreCheck/views/qml/app.qml"));
    component.loadUrl(QUrl("qrc:/qml/app.qml"));
    if ( !component.isReady() ) {
        qWarning("%s", qPrintable(component.errorString()));
        return -1;
    }
    QObject *topLevel = component.create();
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    if ( !window ) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }

    QObject::connect(&engine, SIGNAL(quit()), &app, SLOT(quit()));

    window->show();
    //window->showFullScreen();

    return app.exec();
}
