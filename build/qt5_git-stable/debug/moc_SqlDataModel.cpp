/****************************************************************************
** Meta object code from reading C++ file 'SqlDataModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/models/SqlDataModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SqlDataModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SqlDataModel_t {
    QByteArrayData data[10];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SqlDataModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SqlDataModel_t qt_meta_stringdata_SqlDataModel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 13),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 16),
QT_MOC_LITERAL(5, 58, 13),
QT_MOC_LITERAL(6, 72, 12),
QT_MOC_LITERAL(7, 85, 5),
QT_MOC_LITERAL(8, 91, 6),
QT_MOC_LITERAL(9, 98, 9)
    },
    "SqlDataModel\0fieldsChanged\0\0tableChanged\0"
    "lastErrorChanged\0filterChanged\0"
    "rolesChanged\0table\0filter\0lastError\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlDataModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x05,
       3,    0,   40,    2, 0x05,
       4,    0,   41,    2, 0x05,
       5,    0,   42,    2, 0x05,
       6,    0,   43,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495003,
       9, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       1,
       3,
       2,

       0        // eod
};

void SqlDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqlDataModel *_t = static_cast<SqlDataModel *>(_o);
        switch (_id) {
        case 0: _t->fieldsChanged(); break;
        case 1: _t->tableChanged(); break;
        case 2: _t->lastErrorChanged(); break;
        case 3: _t->filterChanged(); break;
        case 4: _t->rolesChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SqlDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataModel::fieldsChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (SqlDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataModel::tableChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (SqlDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataModel::lastErrorChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (SqlDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataModel::filterChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (SqlDataModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataModel::rolesChanged)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SqlDataModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_SqlDataModel.data,
      qt_meta_data_SqlDataModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *SqlDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlDataModel.stringdata))
        return static_cast<void*>(const_cast< SqlDataModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int SqlDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = tableName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = filter(); break;
        case 2: *reinterpret_cast< QString*>(_v) = lastError(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTable(*reinterpret_cast< QString*>(_v)); break;
        case 1: setFilterCondition(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SqlDataModel::fieldsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SqlDataModel::tableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SqlDataModel::lastErrorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void SqlDataModel::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void SqlDataModel::rolesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
