/****************************************************************************
** Meta object code from reading C++ file 'iostatemachine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/logic/iostatemachine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iostatemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IOStateMachine_t {
    QByteArrayData data[27];
    char stringdata[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IOStateMachine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IOStateMachine_t qt_meta_stringdata_IOStateMachine = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 4),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 8),
QT_MOC_LITERAL(4, 30, 4),
QT_MOC_LITERAL(5, 35, 8),
QT_MOC_LITERAL(6, 44, 12),
QT_MOC_LITERAL(7, 57, 5),
QT_MOC_LITERAL(8, 63, 12),
QT_MOC_LITERAL(9, 76, 13),
QT_MOC_LITERAL(10, 90, 12),
QT_MOC_LITERAL(11, 103, 5),
QT_MOC_LITERAL(12, 109, 17),
QT_MOC_LITERAL(13, 127, 15),
QT_MOC_LITERAL(14, 143, 15),
QT_MOC_LITERAL(15, 159, 7),
QT_MOC_LITERAL(16, 167, 10),
QT_MOC_LITERAL(17, 178, 8),
QT_MOC_LITERAL(18, 187, 5),
QT_MOC_LITERAL(19, 193, 17),
QT_MOC_LITERAL(20, 211, 15),
QT_MOC_LITERAL(21, 227, 3),
QT_MOC_LITERAL(22, 231, 25),
QT_MOC_LITERAL(23, 257, 13),
QT_MOC_LITERAL(24, 271, 13),
QT_MOC_LITERAL(25, 285, 15),
QT_MOC_LITERAL(26, 301, 9)
    },
    "IOStateMachine\0next\0\0sendText\0text\0"
    "editable\0receiveInput\0input\0confirmInput\0"
    "validateInput\0replaceInput\0field\0"
    "cancelReplacement\0displayCalendar\0"
    "setContentValue\0content\0addIOState\0"
    "IOState*\0state\0addIOStateMachine\0"
    "IOStateMachine*\0fsm\0addChildrenNextTransition\0"
    "GenericState*\0previousState\0QAbstractState*\0"
    "nextState\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOStateMachine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x05,
       3,    2,   80,    2, 0x05,
       3,    1,   85,    2, 0x25,
       6,    1,   88,    2, 0x05,
       8,    0,   91,    2, 0x05,
       9,    0,   92,    2, 0x05,
      10,    1,   93,    2, 0x05,
      12,    0,   96,    2, 0x05,
      13,    0,   97,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      14,    2,   98,    2, 0x0a,
      16,    2,  103,    2, 0x0a,
      19,    1,  108,    2, 0x0a,
      22,    2,  111,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString,   15,   11,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QString,   18,   11,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 25,   24,   26,

       0        // eod
};

void IOStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOStateMachine *_t = static_cast<IOStateMachine *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->sendText((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->sendText((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 3: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->confirmInput(); break;
        case 5: _t->validateInput(); break;
        case 6: _t->replaceInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->cancelReplacement(); break;
        case 8: _t->displayCalendar(); break;
        case 9: _t->setContentValue((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->addIOState((*reinterpret_cast< IOState*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->addIOStateMachine((*reinterpret_cast< IOStateMachine*(*)>(_a[1]))); break;
        case 12: _t->addChildrenNextTransition((*reinterpret_cast< GenericState*(*)>(_a[1])),(*reinterpret_cast< QAbstractState*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IOState* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IOStateMachine* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GenericState* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractState* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::next)) {
                *result = 0;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QVariant , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::sendText)) {
                *result = 1;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::receiveInput)) {
                *result = 3;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::confirmInput)) {
                *result = 4;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::validateInput)) {
                *result = 5;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::replaceInput)) {
                *result = 6;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::cancelReplacement)) {
                *result = 7;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::displayCalendar)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject IOStateMachine::staticMetaObject = {
    { &QStateMachine::staticMetaObject, qt_meta_stringdata_IOStateMachine.data,
      qt_meta_data_IOStateMachine,  qt_static_metacall, 0, 0}
};


const QMetaObject *IOStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IOStateMachine.stringdata))
        return static_cast<void*>(const_cast< IOStateMachine*>(this));
    if (!strcmp(_clname, "NamedObject"))
        return static_cast< NamedObject*>(const_cast< IOStateMachine*>(this));
    return QStateMachine::qt_metacast(_clname);
}

int IOStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void IOStateMachine::next()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IOStateMachine::sendText(QVariant _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void IOStateMachine::receiveInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IOStateMachine::confirmInput()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void IOStateMachine::validateInput()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void IOStateMachine::replaceInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void IOStateMachine::cancelReplacement()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void IOStateMachine::displayCalendar()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
