/****************************************************************************
** Meta object code from reading C++ file 'databasecontentquestionstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/logic/databasecontentquestionstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasecontentquestionstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DatabaseContentQuestionState_t {
    QByteArrayData data[3];
    char stringdata[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DatabaseContentQuestionState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DatabaseContentQuestionState_t qt_meta_stringdata_DatabaseContentQuestionState = {
    {
QT_MOC_LITERAL(0, 0, 28),
QT_MOC_LITERAL(1, 29, 17),
QT_MOC_LITERAL(2, 47, 0)
    },
    "DatabaseContentQuestionState\0"
    "displayChoiceList\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseContentQuestionState[] = {

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

void DatabaseContentQuestionState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseContentQuestionState *_t = static_cast<DatabaseContentQuestionState *>(_o);
        switch (_id) {
        case 0: _t->displayChoiceList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DatabaseContentQuestionState::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseContentQuestionState::displayChoiceList)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DatabaseContentQuestionState::staticMetaObject = {
    { &QuestionState::staticMetaObject, qt_meta_stringdata_DatabaseContentQuestionState.data,
      qt_meta_data_DatabaseContentQuestionState,  qt_static_metacall, 0, 0}
};


const QMetaObject *DatabaseContentQuestionState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseContentQuestionState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseContentQuestionState.stringdata))
        return static_cast<void*>(const_cast< DatabaseContentQuestionState*>(this));
    return QuestionState::qt_metacast(_clname);
}

int DatabaseContentQuestionState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QuestionState::qt_metacall(_c, _id, _a);
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
void DatabaseContentQuestionState::displayChoiceList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
