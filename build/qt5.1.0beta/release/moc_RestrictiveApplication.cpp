/****************************************************************************
** Meta object code from reading C++ file 'RestrictiveApplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/models/RestrictiveApplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RestrictiveApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RestrictiveApplication_t {
    QByteArrayData data[26];
    char stringdata[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RestrictiveApplication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RestrictiveApplication_t qt_meta_stringdata_RestrictiveApplication = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 11),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 4),
QT_MOC_LITERAL(4, 41, 11),
QT_MOC_LITERAL(5, 53, 4),
QT_MOC_LITERAL(6, 58, 9),
QT_MOC_LITERAL(7, 68, 12),
QT_MOC_LITERAL(8, 81, 12),
QT_MOC_LITERAL(9, 94, 13),
QT_MOC_LITERAL(10, 108, 11),
QT_MOC_LITERAL(11, 120, 10),
QT_MOC_LITERAL(12, 131, 5),
QT_MOC_LITERAL(13, 137, 7),
QT_MOC_LITERAL(14, 145, 4),
QT_MOC_LITERAL(15, 150, 10),
QT_MOC_LITERAL(16, 161, 11),
QT_MOC_LITERAL(17, 173, 5),
QT_MOC_LITERAL(18, 179, 11),
QT_MOC_LITERAL(19, 191, 7),
QT_MOC_LITERAL(20, 199, 9),
QT_MOC_LITERAL(21, 209, 7),
QT_MOC_LITERAL(22, 217, 9),
QT_MOC_LITERAL(23, 227, 12),
QT_MOC_LITERAL(24, 240, 12),
QT_MOC_LITERAL(25, 253, 14)
    },
    "RestrictiveApplication\0userChanged\0\0"
    "name\0modeChanged\0mode\0userFound\0"
    "userNotFound\0userLoggedIn\0userLoggedOut\0"
    "badPassword\0userExists\0login\0setUser\0"
    "pass\0userLogOut\0currentUser\0User*\0"
    "currentMode\0AppMode\0CONNEXION\0ACCUEIL\0"
    "RECEPTION\0MANAGEMENT_X\0MANAGEMENT_Z\0"
    "ADMINISTRATION\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestrictiveApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   84, // properties
       1,   92, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,
       4,    1,   67,    2, 0x05,
       6,    0,   70,    2, 0x05,
       7,    0,   71,    2, 0x05,
       8,    0,   72,    2, 0x05,
       9,    0,   73,    2, 0x05,
      10,    0,   74,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      11,    1,   75,    2, 0x0a,
      13,    2,   78,    2, 0x0a,
      15,    0,   83,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   14,
    QMetaType::Bool,

 // properties: name, type, flags
      16, 0x80000000 | 17, 0x00495009,
      18, 0x80000000 | 19, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,

 // enums: name, flags, count, data
      19, 0x0,    6,   96,

 // enum data: key, value
      20, uint(RestrictiveApplication::CONNEXION),
      21, uint(RestrictiveApplication::ACCUEIL),
      22, uint(RestrictiveApplication::RECEPTION),
      23, uint(RestrictiveApplication::MANAGEMENT_X),
      24, uint(RestrictiveApplication::MANAGEMENT_Z),
      25, uint(RestrictiveApplication::ADMINISTRATION),

       0        // eod
};

void RestrictiveApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RestrictiveApplication *_t = static_cast<RestrictiveApplication *>(_o);
        switch (_id) {
        case 0: _t->userChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->modeChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->userFound(); break;
        case 3: _t->userNotFound(); break;
        case 4: _t->userLoggedIn(); break;
        case 5: _t->userLoggedOut(); break;
        case 6: _t->badPassword(); break;
        case 7: { bool _r = _t->userExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->setUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: { bool _r = _t->userLogOut();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RestrictiveApplication::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::userChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::modeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::userFound)) {
                *result = 2;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::userNotFound)) {
                *result = 3;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::userLoggedIn)) {
                *result = 4;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::userLoggedOut)) {
                *result = 5;
            }
        }
        {
            typedef void (RestrictiveApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestrictiveApplication::badPassword)) {
                *result = 6;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< User* >(); break;
        }
    }

}

const QMetaObject RestrictiveApplication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RestrictiveApplication.data,
      qt_meta_data_RestrictiveApplication,  qt_static_metacall, 0, 0}
};


const QMetaObject *RestrictiveApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestrictiveApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RestrictiveApplication.stringdata))
        return static_cast<void*>(const_cast< RestrictiveApplication*>(this));
    return QObject::qt_metacast(_clname);
}

int RestrictiveApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< User**>(_v) = user(); break;
        case 1: *reinterpret_cast< AppMode*>(_v) = mode(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setMode(*reinterpret_cast< AppMode*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RestrictiveApplication::userChanged(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RestrictiveApplication::modeChanged(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RestrictiveApplication::userFound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void RestrictiveApplication::userNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void RestrictiveApplication::userLoggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void RestrictiveApplication::userLoggedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void RestrictiveApplication::badPassword()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
