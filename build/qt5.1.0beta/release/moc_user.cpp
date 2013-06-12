/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/models/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_User_t {
    QByteArrayData data[15];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_User_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_User_t qt_meta_stringdata_User = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 11),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 12),
QT_MOC_LITERAL(4, 31, 15),
QT_MOC_LITERAL(5, 47, 6),
QT_MOC_LITERAL(6, 54, 5),
QT_MOC_LITERAL(7, 60, 2),
QT_MOC_LITERAL(8, 63, 4),
QT_MOC_LITERAL(9, 68, 12),
QT_MOC_LITERAL(10, 81, 8),
QT_MOC_LITERAL(11, 90, 8),
QT_MOC_LITERAL(12, 99, 13),
QT_MOC_LITERAL(13, 113, 5),
QT_MOC_LITERAL(14, 119, 5)
    },
    "User\0nameChanged\0\0rolesChanged\0"
    "validityChanged\0exists\0login\0id\0name\0"
    "receptionist\0managerX\0managerZ\0"
    "administrator\0roles\0valid\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       8,   40, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,
       4,    0,   36,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QVariant,    6,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00095001,
       8, QMetaType::QString, 0x00495001,
       9, QMetaType::Bool, 0x00495001,
      10, QMetaType::Bool, 0x00495001,
      11, QMetaType::Bool, 0x00495001,
      12, QMetaType::Bool, 0x00495001,
      13, QMetaType::Int, 0x00495001,
      14, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       1,
       1,
       1,
       1,
       2,

       0        // eod
};

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        User *_t = static_cast<User *>(_o);
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->rolesChanged(); break;
        case 2: _t->validityChanged(); break;
        case 3: { QVariant _r = _t->exists((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::nameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::rolesChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::validityChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject User::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_User.data,
      qt_meta_data_User,  qt_static_metacall, 0, 0}
};


const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_User.stringdata))
        return static_cast<void*>(const_cast< User*>(this));
    return QObject::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = name(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isReceptionist(); break;
        case 3: *reinterpret_cast< bool*>(_v) = isManagerX(); break;
        case 4: *reinterpret_cast< bool*>(_v) = isManagerZ(); break;
        case 5: *reinterpret_cast< bool*>(_v) = isAdministrator(); break;
        case 6: *reinterpret_cast< int*>(_v) = roles(); break;
        case 7: *reinterpret_cast< bool*>(_v) = isValid(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void User::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void User::rolesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void User::validityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
