#include <QtWidgets/QApplication>
#include <QtQml>
#include <QtQuick>
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
#include "models/offers_table_model.h"
#include "models/user.h"
#include "models/RestrictiveApplication.h"
#include "views/qquickaction.h"
#include "ThreadsManager.h"

int main(int argc, char *argv[])
{
    try
    {
        qDebug() << "\n";

        QApplication app(argc, argv);

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
        qmlRegisterType<OffersTableModel>("PreCheck", 1, 0, "OffersModel");
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

        QObject * connexionPage = window->findChild<QObject *>("Connexion");
        QObject * welcomePage = window->findChild<QObject *>("Welcome");
        QObject * commonPage = window->findChild<QObject *>("Common");
        QObject * tabsZone = commonPage->findChild<QObject *>("TabView");
        QObject * displayZone = commonPage->findChild<QObject *>("RightOutput");

        ThreadsManager* threadManager = ThreadsManager::getInstance();
        QObject::connect(appManager, SIGNAL(userLoggedIn()), connexionPage, SLOT(userLoggedIn()), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(badPassword()), connexionPage, SLOT(badPassword()), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(userNotFound()), connexionPage, SLOT(userNotFound()), Qt::DirectConnection);
        QObject::connect(connexionPage, SIGNAL(checkUsername(QString)), appManager, SLOT(userExists(QString)), Qt::DirectConnection);
        QObject::connect(connexionPage, SIGNAL(logIn(QString,QString)), appManager, SLOT(setUser(QString,QString)), Qt::DirectConnection);
        QObject::connect(appManager, SIGNAL(userLoggedOut()), welcomePage, SLOT(userLoggedOut()), Qt::DirectConnection);
        QObject::connect(welcomePage, SIGNAL(logOut()), appManager, SLOT(userLogOut()), Qt::DirectConnection);
        QObject::connect(commonPage, SIGNAL(selected(QString)), threadManager, SIGNAL(sendInput(QString)), Qt::QueuedConnection);
        QObject::connect(commonPage, SIGNAL(cancelProcess()), threadManager, SLOT(cancelRunningThread()), Qt::QueuedConnection);
        QObject::connect(commonPage, SIGNAL(validate()), threadManager, SIGNAL(validateInput()), Qt::DirectConnection);
        QObject::connect(commonPage, SIGNAL(confirm()), threadManager, SIGNAL(confirmInput()), Qt::DirectConnection);
        QObject::connect(commonPage, SIGNAL(replace(QString)), threadManager, SIGNAL(replaceInput(QString)), Qt::DirectConnection);
        QObject::connect(commonPage, SIGNAL(cancelReplace()), threadManager, SIGNAL(cancelReplacement()), Qt::DirectConnection);
        QObject::connect(threadManager, SIGNAL(openTab(QVariant)), tabsZone, SLOT(openTab(QVariant)), Qt::DirectConnection);
        QObject::connect(tabsZone, SIGNAL(newBilling()), threadManager, SLOT(launchBillingsThread()), Qt::DirectConnection);
        QObject::connect(tabsZone, SIGNAL(newBooking()), threadManager, SLOT(launchBookingsThread()), Qt::DirectConnection);
        QObject::connect(tabsZone, SIGNAL(newSelling(int)), threadManager, SLOT(launchBillThread(int)), Qt::DirectConnection);
        QObject::connect(tabsZone, SIGNAL(otherService()), threadManager, SLOT(customService()), Qt::DirectConnection);
        QObject::connect(tabsZone, SIGNAL(otherServiceNoName()), threadManager, SLOT(customServiceWithoutName()), Qt::DirectConnection);
        QObject::connect(threadManager, SIGNAL(sendText(QVariant)), displayZone, SLOT(displayText(QVariant)), Qt::QueuedConnection);
        QObject::connect(threadManager, SIGNAL(displayCalendar()), displayZone, SLOT(displayCalendar()), Qt::QueuedConnection);

        window->show();

        return app.exec();
    }
    catch (const std::exception &e)
    {
        MessageManager::errorMessage(e.what());
    }
}

