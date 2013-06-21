#INCLUDEPATH += $$PWD

# Translation files (for QtLinguist)
TRANSLATIONS = \
precheck_fr.ts\
precheck_de.ts\
precheck_de-CH.ts
#for translations portability
CODECFORSRC = UTF-8


# Non-qml files
HEADERS *= \
    logging/QsLogDest.h \
    logging/QsLog.h \
    logging/QsLogLevel.h \
    logging/QsLogDisableForThisFile.h \
    logging/QsLogDestFile.h \
    logging/QsLogDestConsole.h \
    SH_MessageManager.h \
    SH_DatabaseManager.h \
    SH_ApplicationCore.h \
    views/SH_ExtendedQQmlAction.h \
    models/SH_User.h \
    models/SH_Trainee.h \
    models/SH_SqlDataModel.h \
    models/SH_SqlDataField.h \
    models/SH_ServicesTableModel.h \
    models/SH_RoomsTableModel.h \
    models/SH_GroupsTableModel.h \
    models/SH_ExtendedSqlProxyModel.h \
    models/SH_Company.h \
    models/SH_ClientsTableModel.h \
    models/SH_BookingsTableModel.h \
    models/SH_BillsTableModel.h \
    models/SH_BillingsTableModel.h \
    logic/SH_StringQuestionState.h \
    logic/SH_ValidationState.h \
    logic/SH_StatementState.h \
    logic/SH_ServiceCharging.h \
    logic/SH_RegExpQuestionState.h \
    logic/SH_QuestionState.h \
    logic/SH_PrintingState.h \
    logic/SH_NumericQuestionState.h \
    logic/SH_NamedObject.h \
    logic/SH_LoopingIOStateMachine.h \
    logic/SH_IOState.h \
    logic/SH_IOStateMachine.h \
    logic/SH_GenericDebugableState.h \
    logic/SH_FileSelectionState.h \
    logic/SH_DecimalQuestionState.h \
    logic/SH_DateQuestionState.h \
    logic/SH_DatabaseContentQuestionState.h \
    logic/SH_ConfirmationState.h \
    logic/SH_ClientCreation.h \
    logic/SH_BillingCreation.h \
    logic/SH_AddressCreation.h \
    logic/SH_AdaptDatabaseState.h

SOURCES *= \
    main.cpp \
    logging/QsLogDest.cpp \
    logging/QsLog.cpp \
    logging/QsLogDestFile.cpp \
    logging/QsLogDestConsole.cpp \
    SH_MessageManager.cpp \
    SH_DatabaseManager.cpp \
    SH_ApplicationCore.cpp \
    views/SH_ExtendedQQmlAction.cpp \
    models/SH_BillingsTableModel.cpp \
    models/SH_BillsTableModel.cpp \
    models/SH_BookingsTableModel.cpp \
    models/SH_ClientsTableModel.cpp \
    models/SH_ExtendedProxyModel.cpp \
    models/SH_Company.cpp \
    models/SH_RoomsTableModel.cpp \
    models/SH_GroupsTableModel.cpp \
    models/SH_ServicesTableModel.cpp \
    models/SH_SqlDataModel.cpp \
    models/SH_SqlDataField.cpp \
    models/SH_Trainee.cpp \
    models/SH_User.cpp \
    logic/SH_AdaptDatabaseState.cpp \
    logic/SH_AddressCreation.cpp \
    logic/SH_BillingCreation.cpp \
    logic/SH_ConfirmationState.cpp \
    logic/SH_ClientCreation.cpp \
    logic/SH_DateQuestionState.cpp \
    logic/SH_DatabaseContentQuestionState.cpp \
    logic/SH_IOState.cpp \
    logic/SH_DecimalQuestionState.cpp \
    logic/SH_FileSelectionState.cpp \
    logic/SH_GenericDebugableState.cpp \
    logic/SH_LoopingIOStateMachine.cpp \
    logic/SH_PrintingState.cpp \
    logic/SH_RegExpQuestionState.cpp \
    logic/SH_IOStateMachine.cpp \
    logic/SH_NumericQuestionState.cpp \
    logic/SH_NamedObject.cpp \
    logic/SH_ServiceCharging.cpp \
    logic/SH_QuestionState.cpp \
    logic/SH_StringQuestionState.cpp \
    logic/SH_StatementState.cpp \
    logic/SH_ValidationState.cpp

# QML-files as a ressource
RESOURCES *= \
    views/qmlResources.qrc

# Non C++ files, including QML files
OTHER_FILES *= \
    debugLog.txt \
    views/qml/SH_BillingsDelegate.qml \
    views/qml/SH_TriStateCheckImage.qml \
    views/qml/SH_SqlTableView.qml \
    views/qml/SH_WelcomePage.qml \
    views/qml/SH_TabZone.qml \
    views/qml/SH_SqlDataView.qml \
    views/qml/SH_ServicesDelegate.qml \
    views/qml/SH_RoomsSectionsDelegate.qml \
    views/qml/SH_RoomsDelegate.qml \
    views/qml/SH_OutputZone.qml \
    views/qml/SH_Keyboard.qml \
    views/qml/SH_HeaderView.qml \
    views/qml/SH_DataDelegate.qml \
    views/qml/SH_ContentView.qml \
    views/qml/SH_ConnexionPage.qml \
    views/qml/SH_CommonPage.qml \
    views/qml/SH_CalendarDialog.qml \
    views/qml/SH_BookingsDelegate.qml \
    views/qml/SH_app.qml \
    ../../doc/DoxygenConfigFile \
    ../../doc/DoxyAssistConfigFile.xml
