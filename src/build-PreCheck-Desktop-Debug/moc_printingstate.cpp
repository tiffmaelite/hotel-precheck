/****************************************************************************
** Meta object code from reading C++ file 'printingstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PreCheck/logic/printingstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printingstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrintingState_t {
    QByteArrayData data[4];
    char stringdata[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PrintingState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PrintingState_t qt_meta_stringdata_PrintingState = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 13)
    },
    "PrintingState\0printStarted\0\0printFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintingState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x05,
       3,    0,   25,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PrintingState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintingState *_t = static_cast<PrintingState *>(_o);
        switch (_id) {
        case 0: _t->printStarted(); break;
        case 1: _t->printFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PrintingState::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintingState::printStarted)) {
                *result = 0;
            }
        }
        {
            typedef void (PrintingState::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintingState::printFinished)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PrintingState::staticMetaObject = {
    { &GenericState::staticMetaObject, qt_meta_stringdata_PrintingState.data,
      qt_meta_data_PrintingState,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrintingState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintingState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintingState.stringdata))
        return static_cast<void*>(const_cast< PrintingState*>(this));
    return GenericState::qt_metacast(_clname);
}

int PrintingState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PrintingState::printStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PrintingState::printFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
