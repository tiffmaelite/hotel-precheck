/****************************************************************************
** Meta object code from reading C++ file 'NewBillFactory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/NewBillFactory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewBillFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewBillFactory_t {
    QByteArrayData data[8];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewBillFactory_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewBillFactory_t qt_meta_stringdata_NewBillFactory = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 4),
QT_MOC_LITERAL(4, 34, 13),
QT_MOC_LITERAL(5, 48, 24),
QT_MOC_LITERAL(6, 73, 12),
QT_MOC_LITERAL(7, 86, 13)
    },
    "NewBillFactory\0receiveInput\0\0text\0"
    "customService\0customServiceWithoutName\0"
    "confirmInput\0validateInput\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewBillFactory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       4,    0,   42,    2, 0x0a,
       5,    0,   43,    2, 0x0a,
       6,    0,   44,    2, 0x0a,
       7,    0,   45,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewBillFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewBillFactory *_t = static_cast<NewBillFactory *>(_o);
        switch (_id) {
        case 0: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->customService(); break;
        case 2: _t->customServiceWithoutName(); break;
        case 3: _t->confirmInput(); break;
        case 4: _t->validateInput(); break;
        default: ;
        }
    }
}

const QMetaObject NewBillFactory::staticMetaObject = {
    { &PreCheckThread::staticMetaObject, qt_meta_stringdata_NewBillFactory.data,
      qt_meta_data_NewBillFactory,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewBillFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewBillFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewBillFactory.stringdata))
        return static_cast<void*>(const_cast< NewBillFactory*>(this));
    return PreCheckThread::qt_metacast(_clname);
}

int NewBillFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PreCheckThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
