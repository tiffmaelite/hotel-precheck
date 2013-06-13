
# In a project file, variables are used to hold lists of strings. In the simplest projects, these variables inform qmake about the configuration options to use, or supply filenames and paths to use in the build process.
# qmake looks for certain variables in each project file, and it uses the contents of these to determine what it should write to a Makefile.
# The contents of a variable can be read by prepending the variable name with $$. This can be used to assign the contents of one variable to another.
# Normally, variables are used to contain whitespace-separated lists of values. However, it is sometimes necessary to specify values containing spaces. These must be quoted by using double quotes.
# The quoted text is treated as a single item in the list of values held by the variable. A similar approach is used to deal with paths that contain spaces.
# To include the # character in variable assignments, it is necessary to use the contents of the built-in LITERAL_HASH variable.

# Increase compilation speed (needs ccache installed)
QMAKE_CXX = ccache g++

# Determines whether the output of the build process will be an application, a library, or a plugin
TEMPLATE = app

# General project configuration options
CONFIG += qt console thread exceptions c++11

# Qt-specific configuration options : required modules
QT += core gui quick qml sql widgets printsupport

#QStringBuilder uses expression templates and reimplements the '%' operator so that when you use '%' for string concatenation instead of '+', multiple substring concatenations will be postponed until the final result is about to be assigned to a QString.
#Let '+' automatically be performed as the QStringBuilder '%' everywhere.
DEFINES *= QT_USE_QSTRINGBUILDER

# Translation files (for QtLinguist)
TRANSLATIONS = \
precheck_fr.ts\
precheck_de.ts\
precheck_de-CH.ts
#for translations portability
CODECFORSRC = UTF-8

# Installation
# Installation path
#target.path =
# Name of the target (executable) file
#TARGET = PreCheck
# List of resources that will be installed when make install or a similar installation procedure is executed. Each item in the list is typically defined with attributes that provide information about where it will be installed.
# Note that qmake will skip files that are executable. If you need to install executable files, you can unset the files' executable flags.
#INSTALLS+=
# Directory in which the executable or binary file will be placed
#DESTDIR =
# App version
#VERSION

# Non-qml files
HEADERS += \
    models/user.h \
    models/trainee.h \
    models/company.h \
    models/checkable_sort_filter_proxy_model.h \
    models/billings_table_model.h \
    models/bills_table_model.h \
    models/bookings_table_model.h \
    models/clients_table_model.h \
    models/groups_table_model.h \
    models/rooms_table_model.h \
    models/services_table_model.h \
    views/message_manager.h \
    models/database_manager.h \
    models/sql_data_field.h \
    models/SqlDataModel.h \
    ThreadsManager.h \
    PreCheckThread.h \
    views/qquickaction.h \
    models/RestrictiveApplication.h \
    NewBillingFactory.h \
    NewBookingFactory.h \
    BillingFactory.h \
    BookingFactory.h \
    NewClientFactory.h \
    NewBillFactory.h \
    logic/genericstate.h \
    logic/iostate.h \
    logic/printingstate.h \
    logic/statementstate.h \
    logic/confirmationstate.h \
    logic/validationstate.h \
    logic/questionstate.h \
    logic/numericquestionstate.h \
    logic/stringquestionstate.h \
    logic/databasecontentquestionstate.h \
    logic/decimalquestionstate.h \
    logic/loopingstatemachine.h \
    logic/namedobject.h \
    logic/iostatemachine.h \
    logic/datequestionstate.h \
    logic/adaptdatabase.h \
    logic/billingcreationstatemachine.h

SOURCES += \
    models/user.cpp \
    models/trainee.cpp \
    models/company.cpp \
    models/billings_table_model.cpp \
    models/bills_table_model.cpp \
    models/bookings_table_model.cpp \
    models/checkable_sort_filter_proxy_model.cpp \
    models/clients_table_model.cpp \
    models/database_manager.cpp \
    models/groups_table_model.cpp \
    models/rooms_table_model.cpp \
    models/services_table_model.cpp \
    views/message_manager.cpp \
    models/sql_data_field.cpp \
    main.cpp \
    models/SqlDataModel.cpp \
    ThreadsManager.cpp \
    PreCheckThread.cpp \
    views/qquickaction.cpp \
    models/RestrictiveApplication.cpp \
    NewBillingFactory.cpp \
    NewBookingFactory.cpp \
    BillingFactory.cpp \
    BookingFactory.cpp \
    NewClientFactory.cpp \
    NewBillFactory.cpp \
    logic/genericstate.cpp \
    logic/iostate.cpp \
    logic/printingstate.cpp \
    logic/statementstate.cpp \
    logic/confirmationstate.cpp \
    logic/validationstate.cpp \
    logic/questionstate.cpp \
    logic/numericquestionstate.cpp \
    logic/stringquestionstate.cpp \
    logic/databasecontentquestionstate.cpp \
    logic/decimalquestionstate.cpp \
    logic/loopingstatemachine.cpp \
    logic/namedobject.cpp \
    logic/iostatemachine.cpp \
    logic/datequestionstate.cpp \
    logic/adaptdatabase.cpp \
    logic/billingcreationstatemachine.cpp


# QML-files as a ressource
RESOURCES += \
    views/qmlResources.qrc

# Non C++ files, including QML files
OTHER_FILES += \
    views/qml/app.qml \
    views/qml/Keyboard.qml \
    views/qml/OutputZone.qml \
    views/qml/TabZone.qml \
    views/qml/SqlDataView.qml \
    views/qml/DataDelegate.qml \
    views/qml/UpDownCheckImage.qml \
    views/qml/ServicesDelegate.qml \
    views/qml/RoomsDelegate.qml \
    views/qml/HeaderView.qml \
    views/qml/BookingsDelegate.qml \
    views/qml/BillingsDelegate.qml \
    views/qml/CalendarDialog.qml \
    views/qml/RoomsSectionsDelegate.qml \
    views/qml/ComplexGridView.qml \
    views/qml/WelcomePage.qml \
    views/qml/ConnexionPage.qml \
    views/qml/CommonPage.qml \
    views/qml/ContentView.qml \
    dbInitScript.sql \
    dbCreaScript.sql \
    views/qml/SqlTableView.qml
