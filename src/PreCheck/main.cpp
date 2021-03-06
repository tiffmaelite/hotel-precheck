#include <QtWidgets/QApplication>
#include <QtQml>
#include <QtQuick>
#include <QProgressDialog>
#include "SH_MessageManager.h"
#include "SH_ApplicationCore.h"
#include "models/SH_ExtendedSqlProxyModel.h"
#include "models/SH_RoomsTableModel.h"
#include "models/SH_VATTableModel.h"
#include "models/SH_SqlDataField.h"
#include "models/SH_BillingsTableModel.h"
#include "models/SH_BillsTableModel.h"
#include "models/SH_BookingsTableModel.h"
#include "models/SH_RoomsTableModel.h"
#include "models/SH_ClientsTableModel.h"
#include "models/SH_ServicesTableModel.h"
#include "models/SH_GroupsTableModel.h"
#include "models/SH_User.h"
#include "models/SH_UsersTableModel.h"
#include "models/SH_TraineesTableModel.h"
#include "models/SH_ReportsTableModel.h"
#include "models/SH_ReportsTypesTableModel.h"
#include "views/SH_ExtendedQQmlAction.h"
#include "../../libs/QsLog_2.0.b1/QsLog.h"
#include "../../libs/QsLog_2.0.b1/QsLogDest.h"


using namespace std;
//using namespace SimplHotel;

const int iterations = 20;

void initSettings(SH_ApplicationCore *app) {
    //valid colornames can be found at: http://www.w3.org/TR/SVG/types.html#ColorKeywords
    app->replaceSetting("backgroundColor", "whitesmoke", "globalGUI");
    app->replaceSetting("backgroundColor", "white", "outputZone");
    //app->writeSetting("backgroundColor",  QColor("whitesmoke"), "globalGUI");
    //app->writeSetting("backgroundColor", QColor("white"), "outputZone");
    //TODO continuer l'initialisation de la configuration avec toutes les valeurs par défaut
}


/*!
 * \details \~french
 * \fn SH_statusChanged
 * \param status
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
 * \details \~french
 * \fn SH_exportlog
 * \param type
 * \param msg
*/
void exportlog(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    Q_UNUSED(context);
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
    case QtFatalMsg:
    case QtCriticalMsg:
        break;
    }
    file.write(QObject::tr("%1: %2\r\n").arg(typeName).arg(msg).toUtf8());
}


/*!
 * \details \~french
 * \fn SH_enableLogging
*/
/*!
 * * \details \~french enableLogging
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

    logger.setLoggingLevel(QsLogging::OffLevel);
    /*turning logging off*/



    /*qInstallMessageHandler(exportlog);*/


    /* QLOG_INFO() << "Here is some information";

    QLOG_TRACE() << "Here's a" << QString::fromUtf8("trace") << "message";
    QLOG_DEBUG() << "Here's a" << static_cast<int>(QsLogging::DebugLevel) << "message";
    QLOG_WARN() << "Uh-oh!";
    qDebug() << "This message won't be picked up by the logger";
    QLOG_ERROR() << "An example error has occurred";
    qWarning() << "Neither will this one";
    QLOG_FATAL() << "Fatal error example!";*/
}




/*!
 * \details \~french
 * \fn SH_spin
 * \param iteration
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
 * \details \~french
 * \fn SH_main
 * \param argc
 * \param argv
 * \return int
*/
int main(int argc, char **argv)
{
    try
    {
        qDebug();
        /* Un simple retour à la ligne pour un affichage propre dans la console*/

        QApplication app(argc, argv);

        const QString sLogPath(QDir::cleanPath(app.applicationDirPath()+"/../../../src/PreCheck/debugLog.txt"));
        enableLogging(sLogPath);

        QString appName = QString(QObject::tr("PreCheck"));
        QString devName = QString("SimplHotel");
        QCoreApplication::setOrganizationName(devName);
        QCoreApplication::setApplicationName(appName);



        QString locale = QLocale::system().name();
        QTranslator translator;
        if (!QFile::exists(appName.toLower() + "_" + locale + ".qm"))
        {
            locale = locale.section('_', 0, 0);
        }
        if (QFile::exists(appName.toLower() + "_" + locale + ".qm"))
        {
            translator.load(appName.toLower() + "_" + locale);
            app.installTranslator(&translator);
        }

        QQmlEngine engine;


        /*qmlRegisterUncreatableType<SimplHotel::SH_ApplicationCore>("PreCheck", 1, 0, "AppMode","pour enum AppMode");
        qmlRegisterType<SimplHotel::SH_User>("PreCheck", 1, 0, "User");
        SimplHotel::SH_ApplicationCore* appManager = new SimplHotel::SH_ApplicationCore();*/
        qmlRegisterUncreatableType<SH_ApplicationCore>("PreCheck", 1, 0, "AppMode","pour enum AppMode");
        qmlRegisterType<SH_User>("PreCheck", 1, 0, "User");


        SH_ApplicationCore* appManager = new SH_ApplicationCore();
        QString iniFile = QString(QDir::cleanPath(app.applicationDirPath()+"/../../../src/PreCheck/PreCheck.ini"));
        appManager->setSettings(iniFile); // system-wide location for the application
        initSettings(appManager);

        engine.rootContext()->setContextProperty("App", appManager);


        qmlRegisterType<SH_VATTableModel>("PreCheck", 1, 0, "SH_VATModel");
        qmlRegisterType<SH_UsersTableModel>("PreCheck", 1, 0, "SH_UsersListModel");
        qmlRegisterType<SH_TraineesTableModel>("PreCheck", 1, 0, "SH_TraineesListModel");
        qmlRegisterType<SH_ReportsTypesTableModel>("PreCheck", 1, 0, "SH_ReportsTypesModel");
        qmlRegisterType<SH_ReportsTableModel>("PreCheck", 1, 0, "SH_ReportsModel");
        /*qmlRegisterType<SimplHotel::SH_RoomsTableModel>("PreCheck", 1, 0, "SH_RoomsModel");
        qmlRegisterType<SimplHotel::SH_BillingsTableModel>("PreCheck", 1, 0, "SH_BillingsModel");
        qmlRegisterType<SimplHotel::SH_BillsTableModel>("PreCheck", 1, 0, "SH_BillsModel");
        qmlRegisterType<SimplHotel::SH_BookingsTableModel>("PreCheck", 1, 0, "SH_BookingsModel");
        qmlRegisterType<SimplHotel::SH_ServicesTableModel>("PreCheck", 1, 0, "SH_ServicesModel");
        qmlRegisterType<SimplHotel::SH_ClientsTableModel>("PreCheck", 1, 0, "SH_ClientsModel");
        qmlRegisterType<SimplHotel::SH_GroupsTableModel>("PreCheck", 1, 0, "SH_GroupsModel");
        qmlRegisterType<SimplHotel::SH_SqlDataFields>("PreCheck", 1, 0, "SH_SqlDataField");
        qmlRegisterType<SimplHotel::SH_ExtendedQQmlAction>("PreCheck", 1, 0, "SH_ComplexAction");*/
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

        //window->setColor(appManager->readSetting("backgroundColor","global GUI").value<QColor>());

        QObject * commonPage = window->findChild<QObject *>("Common");
        QObject * tabsZone = commonPage->findChild<QObject *>("TabView");
        QObject * displayZone = commonPage->findChild<QObject *>("RightOutput");

        QObject::connect(appManager, SIGNAL(openTab(QVariant)), tabsZone, SLOT(openTab(QVariant)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString, int, int)), displayZone, SIGNAL(display(QString, int, int)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString, int)), displayZone, SIGNAL(displayTextAt(QString, int)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(sendText(QString)), displayZone, SIGNAL(displayText(QString)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(resendText(QString, int, int)), displayZone, SIGNAL(replace(QString, int, int)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(resendText(QString, int)), displayZone, SIGNAL(replaceTextAt(QString, int)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(resendText(QString)), displayZone, SIGNAL(replaceText(QString)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(clearAll()), displayZone, SIGNAL(clearAll()), Qt::QueuedConnection);
        QObject::connect(appManager, SIGNAL(displayFileDialog()), commonPage, SLOT(displayFileDialog()), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(displayProgressBar(qreal)), displayZone, SIGNAL(displayProgressBar(qreal)), Qt::DirectConnection);
                QObject::connect(appManager, SIGNAL(displayChoiceList(QVariant, int)), displayZone, SIGNAL(displaySqlDatasAt(QVariant, int)), Qt::DirectConnection);
        /*QObject::connect(appManager, SIGNAL(displayCalendar()), displayZone, SLOT(displayCalendar()), Qt::DirectConnection);*/

        QObject::connect(&engine, SIGNAL(quit()), &app, SLOT(quit()));


        QLOG_INFO() << "Program built with Qt" << QT_VERSION_STR << "running on" << qVersion();
        window->show();
        return app.exec();

    }
    catch (const std::exception &e)
    {

        /*SimplHotel::SH_MessageManager::errorMessage(e.what());*/
        SH_MessageManager::errorMessage(e.what());
    }
}
