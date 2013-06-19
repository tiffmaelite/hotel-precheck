/****************************************************************************
** Meta object code from reading C++ file 'sql_data_field.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PreCheck/models/sql_data_field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sql_data_field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SqlDataFields_t {
    QByteArrayData data[11];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SqlDataFields_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SqlDataFields_t qt_meta_stringdata_SqlDataFields = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 11),
QT_MOC_LITERAL(4, 39, 11),
QT_MOC_LITERAL(5, 51, 16),
QT_MOC_LITERAL(6, 68, 4),
QT_MOC_LITERAL(7, 73, 4),
QT_MOC_LITERAL(8, 78, 4),
QT_MOC_LITERAL(9, 83, 9),
QT_MOC_LITERAL(10, 93, 13)
    },
    "SqlDataFields\0textChanged\0\0nameChanged\0"
    "roleChanged\0sortOrderChanged\0name\0"
    "text\0role\0sortOrder\0Qt::SortOrder\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlDataFields[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,
       4,    0,   36,    2, 0x05,
       5,    0,   37,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QByteArray, 0x00495001,
       9, 0x80000000 | 10, 0x0049510b,

 // properties: notify_signal_id
       1,
       0,
       2,
       3,

       0        // eod
};

void SqlDataFields::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqlDataFields *_t = static_cast<SqlDataFields *>(_o);
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->roleChanged(); break;
        case 3: _t->sortOrderChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SqlDataFields::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataFields::textChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (SqlDataFields::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataFields::nameChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (SqlDataFields::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataFields::roleChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (SqlDataFields::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SqlDataFields::sortOrderChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SqlDataFields::staticMetaObject = {
    { &QQuickItem::staticMetaObject, qt_meta_stringdata_SqlDataFields.data,
      qt_meta_data_SqlDataFields,  qt_static_metacall, 0, 0}
};


const QMetaObject *SqlDataFields::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlDataFields::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlDataFields.stringdata))
        return static_cast<void*>(const_cast< SqlDataFields*>(this));
    return QQuickItem::qt_metacast(_clname);
}

int SqlDataFields::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = text(); break;
        case 2: *reinterpret_cast< QByteArray*>(_v) = role(); break;
        case 3: *reinterpret_cast< Qt::SortOrder*>(_v) = sortOrder(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setText(*reinterpret_cast< QString*>(_v)); break;
        case 3: setSortOrder(*reinterpret_cast< Qt::SortOrder*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SqlDataFields::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SqlDataFields::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SqlDataFields::roleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void SqlDataFields::sortOrderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
