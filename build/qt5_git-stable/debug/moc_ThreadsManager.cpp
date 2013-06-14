/****************************************************************************
** Meta object code from reading C++ file 'ThreadsManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/ThreadsManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadsManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadsManager_t {
    QByteArrayData data[22];
    char stringdata[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ThreadsManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ThreadsManager_t qt_meta_stringdata_ThreadsManager = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 20),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 8),
QT_MOC_LITERAL(4, 46, 4),
QT_MOC_LITERAL(5, 51, 15),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 6),
QT_MOC_LITERAL(8, 82, 9),
QT_MOC_LITERAL(9, 92, 9),
QT_MOC_LITERAL(10, 102, 13),
QT_MOC_LITERAL(11, 116, 12),
QT_MOC_LITERAL(12, 129, 12),
QT_MOC_LITERAL(13, 142, 9),
QT_MOC_LITERAL(14, 152, 17),
QT_MOC_LITERAL(15, 170, 13),
QT_MOC_LITERAL(16, 184, 24),
QT_MOC_LITERAL(17, 209, 20),
QT_MOC_LITERAL(18, 230, 16),
QT_MOC_LITERAL(19, 247, 6),
QT_MOC_LITERAL(20, 254, 20),
QT_MOC_LITERAL(21, 275, 19)
    },
    "ThreadsManager\0runningThreadChanged\0"
    "\0sendText\0text\0displayCalendar\0openTab\0"
    "tabPos\0sendInput\0inputText\0validateInput\0"
    "confirmInput\0replaceInput\0inputName\0"
    "cancelReplacement\0customService\0"
    "customServiceWithoutName\0launchBookingsThread\0"
    "launchBillThread\0userId\0launchBillingsThread\0"
    "cancelRunningThread\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadsManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x05,
       3,    1,   90,    2, 0x05,
       5,    0,   93,    2, 0x05,
       6,    1,   94,    2, 0x05,
       8,    1,   97,    2, 0x05,
      10,    0,  100,    2, 0x05,
      11,    0,  101,    2, 0x05,
      12,    1,  102,    2, 0x05,
      14,    0,  105,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      15,    0,  106,    2, 0x0a,
      16,    0,  107,    2, 0x0a,
      17,    0,  108,    2, 0x0a,
      18,    1,  109,    2, 0x0a,
      20,    0,  112,    2, 0x0a,
      21,    0,  113,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Int,   19,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void ThreadsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadsManager *_t = static_cast<ThreadsManager *>(_o);
        switch (_id) {
        case 0: _t->runningThreadChanged(); break;
        case 1: _t->sendText((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->displayCalendar(); break;
        case 3: _t->openTab((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 4: _t->sendInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->validateInput(); break;
        case 6: _t->confirmInput(); break;
        case 7: _t->replaceInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->cancelReplacement(); break;
        case 9: _t->customService(); break;
        case 10: _t->customServiceWithoutName(); break;
        case 11: { bool _r = _t->launchBookingsThread();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->launchBillThread((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->launchBillingsThread();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->cancelRunningThread();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::runningThreadChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ThreadsManager::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::sendText)) {
                *result = 1;
            }
        }
        {
            typedef void (ThreadsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::displayCalendar)) {
                *result = 2;
            }
        }
        {
            typedef void (ThreadsManager::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::openTab)) {
                *result = 3;
            }
        }
        {
            typedef void (ThreadsManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::sendInput)) {
                *result = 4;
            }
        }
        {
            typedef void (ThreadsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::validateInput)) {
                *result = 5;
            }
        }
        {
            typedef void (ThreadsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::confirmInput)) {
                *result = 6;
            }
        }
        {
            typedef void (ThreadsManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::replaceInput)) {
                *result = 7;
            }
        }
        {
            typedef void (ThreadsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadsManager::cancelReplacement)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject ThreadsManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadsManager.data,
      qt_meta_data_ThreadsManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *ThreadsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadsManager.stringdata))
        return static_cast<void*>(const_cast< ThreadsManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ThreadsManager::runningThreadChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ThreadsManager::sendText(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadsManager::displayCalendar()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ThreadsManager::openTab(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadsManager::sendInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ThreadsManager::validateInput()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void ThreadsManager::confirmInput()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void ThreadsManager::replaceInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ThreadsManager::cancelReplacement()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
