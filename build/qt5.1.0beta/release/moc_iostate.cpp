/****************************************************************************
** Meta object code from reading C++ file 'iostate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/logic/iostate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iostate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IOState_t {
    QByteArrayData data[8];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IOState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IOState_t qt_meta_stringdata_IOState = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 10),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 6),
QT_MOC_LITERAL(4, 27, 11),
QT_MOC_LITERAL(5, 39, 5),
QT_MOC_LITERAL(6, 45, 8),
QT_MOC_LITERAL(7, 54, 9)
    },
    "IOState\0sendOutput\0\0output\0resendInput\0"
    "input\0setInput\0setOutput\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       4,    1,   37,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a,
       7,    1,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void IOState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOState *_t = static_cast<IOState *>(_o);
        switch (_id) {
        case 0: _t->sendOutput((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->resendInput((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->setInput((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 3: _t->setOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IOState::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOState::sendOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (IOState::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOState::resendInput)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject IOState::staticMetaObject = {
    { &GenericState::staticMetaObject, qt_meta_stringdata_IOState.data,
      qt_meta_data_IOState,  qt_static_metacall, 0, 0}
};


const QMetaObject *IOState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IOState.stringdata))
        return static_cast<void*>(const_cast< IOState*>(this));
    return GenericState::qt_metacast(_clname);
}

int IOState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericState::qt_metacall(_c, _id, _a);
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
void IOState::sendOutput(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IOState::resendInput(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
