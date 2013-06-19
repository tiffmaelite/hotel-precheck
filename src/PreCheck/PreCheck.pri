#INCLUDEPATH += $$PWD

# Translation files (for QtLinguist)
TRANSLATIONS = \
precheck_fr.ts\
precheck_de.ts\
precheck_de-CH.ts
#for translations portability
CODECFORSRC = UTF-8


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
    views/qquickaction.h \
    models/RestrictiveApplication.h \
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
    logic/clientcreation.h \
    logic/billingcreation.h \
    logic/adaptdatabasestate.h \
    logic/addresscreation.h \
    logic/servicecharging.h \
    logic/fileselectionstate.h \
    logic/regexquestionstate.h \
    logging/QsLogDest.h \
    logging/QsLog.h \
    logging/QsLogLevel.h \
    logging/QsLogDisableForThisFile.h \
    logging/QsLogDestFile.h \
    logging/QsLogDestConsole.h

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
    models/SqlDataModel.cpp \
    views/qquickaction.cpp \
    models/RestrictiveApplication.cpp \
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
    logic/clientcreation.cpp \
    logic/billingcreation.cpp \
    logic/adaptdatabasestate.cpp \
    logic/addresscreation.cpp \
    logic/servicecharging.cpp \
    logic/fileselectionstate.cpp \
    logic/regexquestionstate.cpp \
    main.cpp \
    logging/QsLogDest.cpp \
    logging/QsLog.cpp \
    logging/QsLogDestFile.cpp \
    logging/QsLogDestConsole.cpp

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
    views/qml/SqlTableView.qml \
    ../Database/PreCheckDB.fbd \
    ../Database/dbInitScript.sql \
    ../Database/dbCreaScript.sql \
    ../Database/4_dbCrea_procedures.sql \
    ../Database/3_dbCrea_View_ServicesInfos.sql \
    ../Database/3_dbCrea_View_RoomsInfos.sql \
    ../Database/3_dbCrea_View_BillingsInfos.sql \
    ../Database/2_dbCrea_constraints.sql \
    ../Database/1_dbCrea_Users.sql \
    ../Database/1_dbCrea_Trainees.sql \
    ../Database/1_dbCrea_Taxes.sql \
    ../Database/1_dbCrea_ServicesTypes.sql \
    ../Database/1_dbCrea_ServicesFields.sql \
    ../Database/1_dbCrea_ServicesFamilies.sql \
    ../Database/1_dbCrea_ServicesDetails.sql \
    ../Database/1_dbCrea_Services.sql \
    ../Database/1_dbCrea_RoomsTypes.sql \
    ../Database/1_dbCrea_Rooms.sql \
    ../Database/1_dbCrea_Reports.sql \
    ../Database/1_dbCrea_Nationalities.sql \
    ../Database/1_dbCrea_Groups.sql \
    ../Database/1_dbCrea_Clients.sql \
    ../Database/1_dbCrea_ChargedServices.sql \
    ../Database/1_dbCrea_Bookings.sql \
    ../Database/1_dbCrea_BillsTypes.sql \
    ../Database/1_dbCrea_Bills.sql \
    ../Database/1_dbCrea_BillingsTypes.sql \
    ../Database/1_dbCrea_BillingsGroups.sql \
    ../Database/1_dbCrea_BillingsClients.sql \
    ../Database/1_dbCrea_Billings.sql \
    ../Database/1_dbCrea_BalanceLog.sql \
    ../Database/1_dbCrea_Addresses.sql \
    ../Database/0_dbCrea_general.sql \
    ../Database/install_script.sh \
    ../Database/PreCheckCreaError.log \
    ../Database/PreCheckCrea.log
