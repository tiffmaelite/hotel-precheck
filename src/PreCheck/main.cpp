#include <QtWidgets/QApplication>
#include <QtQml>
#include <QtQuick>
#include <QProgressDialog>
#include "views/message_manager.h"
#include "models/checkable_sort_filter_proxy_model.h"
#include "models/rooms_table_model.h"
#include "models/sql_data_field.h"
#include "models/billings_table_model.h"
#include "models/bills_table_model.h"
#include "models/bookings_table_model.h"
#include "models/rooms_table_model.h"
#include "models/clients_table_model.h"
#include "models/services_table_model.h"
#include "models/groups_table_model.h"
#include "models/user.h"
#include "models/RestrictiveApplication.h"
#include "views/qquickaction.h"
#include "logging/QsLog.h"
#include "logging/QsLogDest.h"


const int iterations = 20;


/*!
 \brief
 \fn statusChanged TODO comment this
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
 \brief
 \fn exportlog TODO comment this
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
 \brief
 \fn enableLogging TODO comment this
*/
void enableLogging(const QString sLogPath)
{
    // init the logging mechanism
    QsLogging::Logger& logger = QsLogging::Logger::instance();
    logger.setLoggingLevel(QsLogging::TraceLevel);

    QsLogging::DestinationPtr fileDestination(
                QsLogging::DestinationFactory::MakeFileDestination(sLogPath, true, 512, 2) );
    QsLogging::DestinationPtr debugDestination(
                QsLogging::DestinationFactory::MakeDebugOutputDestination() );
    logger.addDestination(debugDestination);
    logger.addDestination(fileDestination);

    /*logger.setLoggingLevel(QsLogging::OffLevel);
    for (int i = 0;i < 10000000;++i) {
        QLOG_ERROR() << QString::fromUtf8("logging is turned off");
    }*/

    qInstallMessageHandler(exportlog);
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
 \brief
 \fn spin TODO comment this
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
 \brief
 \fn main TODO comment this
 \param argc TODO comment this
 \param argv TODO comment this
 \return int TODO comment this
*/
int main(int argc, char **argv)
{
    try
    {
        qDebug();  // Un simple retour à la ligne pour un affichage propre dans la console

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

        qmlRegisterUncreatableType<RestrictiveApplication>("PreCheck", 1, 0, "AppMode","pour enum AppMode");
        qmlRegisterType<User>("PreCheck", 1, 0, "User");
        RestrictiveApplication* appManager = new RestrictiveApplication();
        engine.rootContext()->setContextProperty("App", appManager);

        //qmlRegisterInterface<CheckableSortFilterProxyModel>("PreCheck", 1, 0, "ProxyModel");
        qmlRegisterType<RoomsTableModel>("PreCheck", 1, 0, "RoomsModel");
        qmlRegisterType<BillingsTableModel>("PreCheck", 1, 0, "BillingsModel");
        qmlRegisterType<BillsTableModel>("PreCheck", 1, 0, "BillsModel");
        qmlRegisterType<BookingsTableModel>("PreCheck", 1, 0, "BookingsModel");
        qmlRegisterType<ServicesTableModel>("PreCheck", 1, 0, "ServicesModel");
        qmlRegisterType<ClientsTableModel>("PreCheck", 1, 0, "ClientsModel");
        qmlRegisterType<GroupsTableModel>("PreCheck", 1, 0, "GroupsModel");
        qmlRegisterType<SqlDataFields>("PreCheck", 1, 0, "SqlDataFields");
        qmlRegisterType<QQQuickAction>("PreCheck", 1, 0, "ComplexAction");

        QQmlComponent component(&engine);
        component.loadUrl(QUrl("qrc:/qml/app.qml"));
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
        QObject::connect(appManager, SIGNAL(sendText(QString)), displayZone, SIGNAL(displayNewFixed(QString)), Qt::QueuedConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString)), displayZone, SIGNAL(replace(QString)), Qt::QueuedConnection);
        QObject::connect(appManager, SIGNAL(clearAll()), displayZone, SLOT(clearAll()), Qt::QueuedConnection);
        //QObject::connect(appManager, SIGNAL(displayCalendar()), displayZone, SLOT(displayCalendar()), Qt::QueuedConnection);

        window->show();
        QLOG_INFO() << "Program built with Qt" << QT_VERSION_STR << "running on" << qVersion();
        return app.exec();

    }
    catch (const std::exception &e)
    {
        MessageManager::errorMessage(e.what());
    }
}
