/****************************************************************************
** Meta object code from reading C++ file 'qquickaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PreCheck/views/qquickaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qquickaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QQQuickAction_t {
    QByteArrayData data[24];
    char stringdata[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QQQuickAction_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QQQuickAction_t qt_meta_stringdata_QQQuickAction = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 9),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 7),
QT_MOC_LITERAL(5, 41, 11),
QT_MOC_LITERAL(6, 53, 15),
QT_MOC_LITERAL(7, 69, 8),
QT_MOC_LITERAL(8, 78, 18),
QT_MOC_LITERAL(9, 97, 7),
QT_MOC_LITERAL(10, 105, 11),
QT_MOC_LITERAL(11, 117, 11),
QT_MOC_LITERAL(12, 129, 15),
QT_MOC_LITERAL(13, 145, 17),
QT_MOC_LITERAL(14, 163, 14),
QT_MOC_LITERAL(15, 178, 3),
QT_MOC_LITERAL(16, 182, 14),
QT_MOC_LITERAL(17, 197, 7),
QT_MOC_LITERAL(18, 205, 4),
QT_MOC_LITERAL(19, 210, 10),
QT_MOC_LITERAL(20, 221, 8),
QT_MOC_LITERAL(21, 230, 6),
QT_MOC_LITERAL(22, 237, 7),
QT_MOC_LITERAL(23, 245, 7)
    },
    "QQQuickAction\0triggered\0\0toggled\0"
    "checked\0textChanged\0shortcutChanged\0"
    "shortcut\0keyShortcutChanged\0Qt::Key\0"
    "keyShortcut\0iconChanged\0iconNameChanged\0"
    "iconSourceChanged\0tooltipChanged\0arg\0"
    "enabledChanged\0trigger\0text\0iconSource\0"
    "iconName\0__icon\0tooltip\0enabled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QQQuickAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       8,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x05,
       3,    1,   70,    2, 0x05,
       5,    0,   73,    2, 0x05,
       6,    1,   74,    2, 0x05,
       8,    1,   77,    2, 0x05,
      11,    0,   80,    2, 0x05,
      12,    0,   81,    2, 0x05,
      13,    0,   82,    2, 0x05,
      14,    1,   83,    2, 0x05,
      16,    0,   86,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      17,    0,   87,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QUrl, 0x00495103,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QVariant, 0x00495001,
      22, QMetaType::QString, 0x00495103,
      23, QMetaType::Bool, 0x00495103,
       7, QMetaType::QString, 0x00495103,
      10, 0x80000000 | 9, 0x0009510a,

 // properties: notify_signal_id
       2,
       7,
       6,
       5,
       8,
       9,
       3,
       0,

       0        // eod
};

void QQQuickAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QQQuickAction *_t = static_cast<QQQuickAction *>(_o);
        switch (_id) {
        case 0: _t->triggered(); break;
        case 1: _t->toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->textChanged(); break;
        case 3: _t->shortcutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->keyShortcutChanged((*reinterpret_cast< Qt::Key(*)>(_a[1]))); break;
        case 5: _t->iconChanged(); break;
        case 6: _t->iconNameChanged(); break;
        case 7: _t->iconSourceChanged(); break;
        case 8: _t->tooltipChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->enabledChanged(); break;
        case 10: _t->trigger(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::triggered)) {
                *result = 0;
            }
        }
        {
            typedef void (QQQuickAction::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::toggled)) {
                *result = 1;
            }
        }
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::textChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (QQQuickAction::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::shortcutChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (QQQuickAction::*_t)(Qt::Key );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::keyShortcutChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::iconChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::iconNameChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::iconSourceChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (QQQuickAction::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::tooltipChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (QQQuickAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QQQuickAction::enabledChanged)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject QQQuickAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QQQuickAction.data,
      qt_meta_data_QQQuickAction,  qt_static_metacall, 0, 0}
};


const QMetaObject *QQQuickAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QQQuickAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QQQuickAction.stringdata))
        return static_cast<void*>(const_cast< QQQuickAction*>(this));
    return QObject::qt_metacast(_clname);
}

int QQQuickAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = text(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = iconSource(); break;
        case 2: *reinterpret_cast< QString*>(_v) = iconName(); break;
        case 3: *reinterpret_cast< QVariant*>(_v) = iconVariant(); break;
        case 4: *reinterpret_cast< QString*>(_v) = tooltip(); break;
        case 5: *reinterpret_cast< bool*>(_v) = isEnabled(); break;
        case 6: *reinterpret_cast< QString*>(_v) = shortcut(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: setIconSource(*reinterpret_cast< QUrl*>(_v)); break;
        case 2: setIconName(*reinterpret_cast< QString*>(_v)); break;
        case 4: setTooltip(*reinterpret_cast< QString*>(_v)); break;
        case 5: setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 6: setShortcut(*reinterpret_cast< QString*>(_v)); break;
        case 7: setKeyShortcut(*reinterpret_cast< Qt::Key*>(_v)); break;
        }
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
void QQQuickAction::triggered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QQQuickAction::toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QQQuickAction::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QQQuickAction::shortcutChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QQQuickAction::keyShortcutChanged(Qt::Key _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QQQuickAction::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QQQuickAction::iconNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void QQQuickAction::iconSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void QQQuickAction::tooltipChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QQQuickAction::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
