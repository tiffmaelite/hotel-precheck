INCLUDEPATH += $$PWD
SOURCES += \
    ../../libs/qt-signal-tools/QtSignalForwarder.cpp \
    ../../libs/qt-signal-tools/QtCallback.cpp

HEADERS += \
    ../../libs/qt-signal-tools/SafeBinder.h \
    ../../libs/qt-signal-tools/QtSignalForwarder.h \
    ../../libs/qt-signal-tools/QtMetacallAdapter.h \
    ../../libs/qt-signal-tools/QtCallback.h \
    ../../libs/qt-signal-tools/FunctionUtils.h \
    ../../libs/qt-signal-tools/FunctionTraits.h

OTHER_FILES += \
    ../../libs/qt-signal-tools/README.md \
    ../../libs/QsLog_2.0b1.zip
