INCLUDEPATH += $$PWD
SOURCES += \
	$$PWD/qt-signal-tools/QtSignalForwarder.cpp \
	$$PWD/qt-signal-tools/QtCallback.cpp

HEADERS += \
	$$PWD/qt-signal-tools/SafeBinder.h \
	$$PWD/qt-signal-tools/QtSignalForwarder.h \
	$$PWD/qt-signal-tools/QtMetacallAdapter.h \
	$$PWD/qt-signal-tools/QtCallback.h \
	$$PWD/qt-signal-tools/FunctionUtils.h \
	$$PWD/qt-signal-tools/FunctionTraits.h

OTHER_FILES += \
	$$PWD/qt-signal-tools/README.md \
	$$PWD/QsLog_2.0b1.zip
