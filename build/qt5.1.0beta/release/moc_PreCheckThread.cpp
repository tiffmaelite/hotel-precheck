/****************************************************************************
** Meta object code from reading C++ file 'PreCheckThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/PreCheckThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PreCheckThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PreCheckThread_t {
    QByteArrayData data[12];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PreCheckThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PreCheckThread_t qt_meta_stringdata_PreCheckThread = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 7),
QT_MOC_LITERAL(5, 38, 6),
QT_MOC_LITERAL(6, 45, 12),
QT_MOC_LITERAL(7, 58, 12),
QT_MOC_LITERAL(8, 71, 13),
QT_MOC_LITERAL(9, 85, 12),
QT_MOC_LITERAL(10, 98, 5),
QT_MOC_LITERAL(11, 104, 17)
    },
    "PreCheckThread\0sendText\0\0text\0openTab\0"
    "tabPos\0receiveInput\0confirmInput\0"
    "validateInput\0replaceInput\0field\0"
    "cancelReplacement\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreCheckThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       4,    1,   52,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   55,    2, 0x0a,
       7,    0,   58,    2, 0x0a,
       8,    0,   59,    2, 0x0a,
       9,    1,   60,    2, 0x0a,
      11,    0,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void PreCheckThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PreCheckThread *_t = static_cast<PreCheckThread *>(_o);
        switch (_id) {
        case 0: _t->sendText((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->openTab((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->confirmInput(); break;
        case 4: _t->validateInput(); break;
        case 5: _t->replaceInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->cancelReplacement(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PreCheckThread::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PreCheckThread::sendText)) {
                *result = 0;
            }
        }
        {
            typedef void (PreCheckThread::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PreCheckThread::openTab)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PreCheckThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PreCheckThread.data,
      qt_meta_data_PreCheckThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *PreCheckThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreCheckThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PreCheckThread.stringdata))
        return static_cast<void*>(const_cast< PreCheckThread*>(this));
    return QThread::qt_metacast(_clname);
}

int PreCheckThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PreCheckThread::sendText(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PreCheckThread::openTab(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
