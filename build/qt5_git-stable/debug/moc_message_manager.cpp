/****************************************************************************
** Meta object code from reading C++ file 'message_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/views/message_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'message_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageManager_t {
    QByteArrayData data[7];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MessageManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MessageManager_t qt_meta_stringdata_MessageManager = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 9),
QT_MOC_LITERAL(2, 25, 5),
QT_MOC_LITERAL(3, 31, 4),
QT_MOC_LITERAL(4, 36, 5),
QT_MOC_LITERAL(5, 42, 13),
QT_MOC_LITERAL(6, 56, 7)
    },
    "MessageManager\0ErrorMode\0ERROR\0TEST\0"
    "DEBUG\0DEBUG_VERBOSE\0RELEASE\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    5,   18,

 // enum data: key, value
       2, uint(MessageManager::ERROR),
       3, uint(MessageManager::TEST),
       4, uint(MessageManager::DEBUG),
       5, uint(MessageManager::DEBUG_VERBOSE),
       6, uint(MessageManager::RELEASE),

       0        // eod
};

void MessageManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MessageManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MessageManager.data,
      qt_meta_data_MessageManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *MessageManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageManager.stringdata))
        return static_cast<void*>(const_cast< MessageManager*>(this));
    return QObject::qt_metacast(_clname);
}

int MessageManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
