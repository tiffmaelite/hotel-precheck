#include <QtWidgets/QApplication>
#include <QtQml>
#include <QtQuick>
#include <QProgressDialog>
#include "SH_MessageManager.h"
#include "SH_ApplicationCore.h"
#include "models/SH_ExtendedSqlProxyModel.h"
#include "models/SH_RoomsTableModel.h"
#include "models/SH_SqlDataField.h"
#include "models/SH_BillingsTableModel.h"
#include "models/SH_BillsTableModel.h"
#include "models/SH_BookingsTableModel.h"
#include "models/SH_RoomsTableModel.h"
#include "models/SH_ClientsTableModel.h"
#include "models/SH_ServicesTableModel.h"
#include "models/SH_GroupsTableModel.h"
#include "models/SH_User.h"
#include "views/SH_ExtendedQQmlAction.h"
#include "logging/QsLog.h"
#include "logging/QsLogDest.h"


const int iterations = 20;


/*!
 \details
 \fn SH_statusChanged TODO comment this
 \param status TODO comment this
*/
void statusChanged(QQmlComponent* component, QQmlComponent::Status status) {
    if (status == QQmlComponent::Error) {
        foreach (const QQmlError &error, component->errors()) {
            const QByteArray file = error.url().toEncoded();
            QMessageLogger(file.constData(), error.line(), 0).debug() << error.description();
        }
    }
}

/*!
 \details
 \fn SH_exportlog TODO comment this
 \param type TODO comment this
 \param msg TODO comment this
*/
void exportlog(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QFile file(QApplication::applicationDirPath()+"/"+qAppName()+".log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.write(QString("[").toUtf8()+QDateTime::currentDateTime().toString().toUtf8()+QString("] ").toUtf8());
    QString typeName;
    switch (type) {
    case QtDebugMsg:
        typeName = QObject::tr("Debug");
        break;
    case QtWarningMsg:
        typeName = QObject::tr("Warning");
        break;
    }
    file.write(QObject::tr("%1: %2\r\n").arg(typeName).arg(msg).toUtf8());
}


/*!
 \details
 \fn SH_enableLogging TODO comment this
*/
/*!
 * \details enableLogging
 * \param sLogPath
 */
void enableLogging(const QString sLogPath)
{
    /* init the logging mechanism*/
    QsLogging::Logger& logger = QsLogging::Logger::instance();
    logger.setLoggingLevel(QsLogging::TraceLevel);

    QsLogging::DestinationPtr fileDestination(
                QsLogging::DestinationFactory::MakeFileDestination(sLogPath, true, 512, 2) );
    QsLogging::DestinationPtr debugDestination(
                QsLogging::DestinationFactory::MakeDebugOutputDestination() );
    logger.addDestination(debugDestination);
    logger.addDestination(fileDestination);

    logger.setLoggingLevel(QsLogging::OffLevel); /*truning logging off*/


    /*qInstallMessageHandler(exportlog);*/

    /* QLOG_INFO() << "Here is some information";

        QLOG_TRACE() << "Here's a" << QString::fromUtf8("trace") << "message";
        QLOG_DEBUG() << "Here's a" << static_cast<int>(QsLogging::DebugLevel) << "message";
        QLOG_WARN()  << "Uh-oh!";
        qDebug() << "This message won't be picked up by the logger";
        QLOG_ERROR() << "An example error has occurred";
        qWarning() << "Neither will this one";
        QLOG_FATAL() << "Fatal error example!";*/
}




/*!
 \details
 \fn SH_spin TODO comment this
 \param iteration TODO comment this
*/
void spin(int &iteration)
{
    const int work = 1000 * 1000 * 40;
    volatile int v = 0;
    for (int j = 0; j < work; ++j)
        ++v;

    qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
}

/*!
 \details
 \fn SH_main TODO comment this
 \param argc TODO comment this
 \param argv TODO comment this
 \return int TODO comment this
*/
int main(int argc, char **argv)
{
    try
    {
        qDebug();  /* Un simple retour à la ligne pour un affichage propre dans la console*/

        QApplication app(argc, argv);

        const QString sLogPath(QDir::cleanPath(app.applicationDirPath()+"/../../../src/PreCheck/debugLog.txt"));
        qDebug() << app.applicationDirPath();
        qDebug() << QDir::cleanPath(app.applicationDirPath()+"/../../../src/PreCheck/debugLog.txt");
        enableLogging(sLogPath);

        QString appName = QString(QObject::tr("precheck"));
        QString locale = QLocale::system().name();
        QTranslator translator;
        if (!QFile::exists(appName + "_" + locale + ".qm"))
        {
            locale = locale.section('_', 0, 0);
        }
        if (QFile::exists(appName + "_" + locale + ".qm"))
        {
            translator.load(appName + "_" + locale);
            app.installTranslator(&translator);
        }

        QQmlEngine engine;

        qmlRegisterUncreatableType<SH_ApplicationCore>("PreCheck", 1, 0, "AppMode","pour enum AppMode");
        qmlRegisterType<SH_User>("PreCheck", 1, 0, "User");
        SH_ApplicationCore* appManager = new SH_ApplicationCore();
        engine.rootContext()->setContextProperty("SH_App", appManager);

        qmlRegisterType<SH_RoomsTableModel>("PreCheck", 1, 0, "SH_RoomsModel");
        qmlRegisterType<SH_BillingsTableModel>("PreCheck", 1, 0, "SH_BillingsModel");
        qmlRegisterType<SH_BillsTableModel>("PreCheck", 1, 0, "SH_BillsModel");
        qmlRegisterType<SH_BookingsTableModel>("PreCheck", 1, 0, "SH_BookingsModel");
        qmlRegisterType<SH_ServicesTableModel>("PreCheck", 1, 0, "SH_ServicesModel");
        qmlRegisterType<SH_ClientsTableModel>("PreCheck", 1, 0, "SH_ClientsModel");
        qmlRegisterType<SH_GroupsTableModel>("PreCheck", 1, 0, "SH_GroupsModel");
        qmlRegisterType<SH_SqlDataFields>("PreCheck", 1, 0, "SH_SqlDataField");
        qmlRegisterType<SH_ExtendedQQmlAction>("PreCheck", 1, 0, "SH_ComplexAction");

        QQmlComponent component(&engine);
        component.loadUrl(QUrl("qrc:/qml/SH_app.qml"));
        if (!component.isReady())
        {
            qWarning("%s", qPrintable(component.errorString()));
            return -1;
        }
        QObject *topLevel = component.create();
        QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
        if (!window)
        {
            qWarning("Error: Your root item has to be a Window.");
            return -1;
        }
        QObject::connect(&engine, SIGNAL(quit()), &app, SLOT(quit()));


        QObject * commonPage = window->findChild<QObject *>("Common");
        QObject * tabsZone = commonPage->findChild<QObject *>("TabView");
        QObject * displayZone = commonPage->findChild<QObject *>("RightOutput");

        QObject::connect(appManager, SIGNAL(openTab(QVariant)), tabsZone, SLOT(openTab(QVariant)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString)), displayZone, SIGNAL(displayNewFixed(QString)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString)), displayZone, SIGNAL(replace(QString)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(clearAll()), displayZone, SLOT(clearAll()), Qt::QueuedConnection);
        /*QObject::connect(appManager, SIGNAL(displayCalendar()), displayZone, SLOT(displayCalendar()), Qt::DirectConnection);*/

        window->show();
        QLOG_INFO() << "Program built with Qt" << QT_VERSION_STR << "running on" << qVersion();
        return app.exec();

    }
    catch (const std::exception &e)
    {
        SH_MessageManager::errorMessage(e.what());
    }
}
