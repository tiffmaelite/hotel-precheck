/****************************************************************************
** Meta object code from reading C++ file 'genericstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PreCheck/logic/genericstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genericstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GenericState_t {
    QByteArrayData data[3];
    char stringdata[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GenericState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GenericState_t qt_meta_stringdata_GenericState = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 4),
QT_MOC_LITERAL(2, 18, 0)
    },
    "GenericState\0next\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenericState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GenericState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenericState *_t = static_cast<GenericState *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenericState::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericState::next)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GenericState::staticMetaObject = {
    { &QState::staticMetaObject, qt_meta_stringdata_GenericState.data,
      qt_meta_data_GenericState,  qt_static_metacall, 0, 0}
};


const QMetaObject *GenericState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenericState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GenericState.stringdata))
        return static_cast<void*>(const_cast< GenericState*>(this));
    if (!strcmp(_clname, "NamedObject"))
        return static_cast< NamedObject*>(const_cast< GenericState*>(this));
    return QState::qt_metacast(_clname);
}

int GenericState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GenericState::next()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
