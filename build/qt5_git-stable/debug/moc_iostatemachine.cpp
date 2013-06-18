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
    QByteArrayData data[29];
    char stringdata[336];
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
QT_MOC_LITERAL(4, 30, 8),
QT_MOC_LITERAL(5, 39, 4),
QT_MOC_LITERAL(6, 44, 8),
QT_MOC_LITERAL(7, 53, 10),
QT_MOC_LITERAL(8, 64, 12),
QT_MOC_LITERAL(9, 77, 5),
QT_MOC_LITERAL(10, 83, 12),
QT_MOC_LITERAL(11, 96, 13),
QT_MOC_LITERAL(12, 110, 12),
QT_MOC_LITERAL(13, 123, 5),
QT_MOC_LITERAL(14, 129, 17),
QT_MOC_LITERAL(15, 147, 15),
QT_MOC_LITERAL(16, 163, 17),
QT_MOC_LITERAL(17, 181, 15),
QT_MOC_LITERAL(18, 197, 7),
QT_MOC_LITERAL(19, 205, 10),
QT_MOC_LITERAL(20, 216, 8),
QT_MOC_LITERAL(21, 225, 5),
QT_MOC_LITERAL(22, 231, 17),
QT_MOC_LITERAL(23, 249, 15),
QT_MOC_LITERAL(24, 265, 3),
QT_MOC_LITERAL(25, 269, 25),
QT_MOC_LITERAL(26, 295, 15),
QT_MOC_LITERAL(27, 311, 13),
QT_MOC_LITERAL(28, 325, 9)
    },
    "IOStateMachine\0next\0\0clearAll\0sendText\0"
    "text\0editable\0resendText\0receiveInput\0"
    "input\0confirmInput\0validateInput\0"
    "replaceInput\0field\0cancelReplacement\0"
    "displayCalendar\0displayFileDialog\0"
    "setContentValue\0content\0addIOState\0"
    "IOState*\0state\0addIOStateMachine\0"
    "IOStateMachine*\0fsm\0addChildrenNextTransition\0"
    "QAbstractState*\0previousState\0nextState\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOStateMachine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x05,
       3,    0,  100,    2, 0x05,
       4,    2,  101,    2, 0x05,
       4,    1,  106,    2, 0x25,
       7,    2,  109,    2, 0x05,
       7,    1,  114,    2, 0x25,
       8,    1,  117,    2, 0x05,
      10,    0,  120,    2, 0x05,
      11,    0,  121,    2, 0x05,
      12,    1,  122,    2, 0x05,
      14,    0,  125,    2, 0x05,
      15,    0,  126,    2, 0x05,
      16,    0,  127,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      17,    2,  128,    2, 0x0a,
      19,    2,  133,    2, 0x0a,
      22,    1,  138,    2, 0x0a,
      25,    2,  141,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString,   18,   13,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QString,   21,   13,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 26,   27,   28,

       0        // eod
};

void IOStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOStateMachine *_t = static_cast<IOStateMachine *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->clearAll(); break;
        case 2: _t->sendText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->sendText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->resendText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->resendText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->confirmInput(); break;
        case 8: _t->validateInput(); break;
        case 9: _t->replaceInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->cancelReplacement(); break;
        case 11: _t->displayCalendar(); break;
        case 12: _t->displayFileDialog(); break;
        case 13: _t->setContentValue((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->addIOState((*reinterpret_cast< IOState*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->addIOStateMachine((*reinterpret_cast< IOStateMachine*(*)>(_a[1]))); break;
        case 16: _t->addChildrenNextTransition((*reinterpret_cast< QAbstractState*(*)>(_a[1])),(*reinterpret_cast< QAbstractState*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IOState* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IOStateMachine* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
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
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::clearAll)) {
                *result = 1;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::sendText)) {
                *result = 2;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::resendText)) {
                *result = 4;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::receiveInput)) {
                *result = 6;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::confirmInput)) {
                *result = 7;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::validateInput)) {
                *result = 8;
            }
        }
        {
            typedef void (IOStateMachine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::replaceInput)) {
                *result = 9;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::cancelReplacement)) {
                *result = 10;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::displayCalendar)) {
                *result = 11;
            }
        }
        {
            typedef void (IOStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOStateMachine::displayFileDialog)) {
                *result = 12;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void IOStateMachine::next()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IOStateMachine::clearAll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void IOStateMachine::sendText(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void IOStateMachine::resendText(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void IOStateMachine::receiveInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void IOStateMachine::confirmInput()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void IOStateMachine::validateInput()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void IOStateMachine::replaceInput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void IOStateMachine::cancelReplacement()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void IOStateMachine::displayCalendar()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void IOStateMachine::displayFileDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}
QT_END_MOC_NAMESPACE
