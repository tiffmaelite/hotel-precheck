/****************************************************************************
** Meta object code from reading C++ file 'NewBillingFactory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/NewBillingFactory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewBillingFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewBillingFactory_t {
    QByteArrayData data[7];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewBillingFactory_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewBillingFactory_t qt_meta_stringdata_NewBillingFactory = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 15),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 12),
QT_MOC_LITERAL(4, 48, 4),
QT_MOC_LITERAL(5, 53, 12),
QT_MOC_LITERAL(6, 66, 13)
    },
    "NewBillingFactory\0displayCalendar\0\0"
    "receiveInput\0text\0confirmInput\0"
    "validateInput\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewBillingFactory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a,
       5,    0,   38,    2, 0x0a,
       6,    0,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewBillingFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewBillingFactory *_t = static_cast<NewBillingFactory *>(_o);
        switch (_id) {
        case 0: _t->displayCalendar(); break;
        case 1: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->confirmInput(); break;
        case 3: _t->validateInput(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewBillingFactory::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewBillingFactory::displayCalendar)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NewBillingFactory::staticMetaObject = {
    { &PreCheckThread::staticMetaObject, qt_meta_stringdata_NewBillingFactory.data,
      qt_meta_data_NewBillingFactory,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewBillingFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewBillingFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewBillingFactory.stringdata))
        return static_cast<void*>(const_cast< NewBillingFactory*>(this));
    return PreCheckThread::qt_metacast(_clname);
}

int NewBillingFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PreCheckThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NewBillingFactory::displayCalendar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
