/****************************************************************************
** Meta object code from reading C++ file 'showsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DataCenter/showsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowSystem_t {
    QByteArrayData data[15];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowSystem_t qt_meta_stringdata_ShowSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ShowSystem"
QT_MOC_LITERAL(1, 11, 13), // "reviseSetting"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "haveRecvData"
QT_MOC_LITERAL(4, 39, 13), // "dataProcessed"
QT_MOC_LITERAL(5, 53, 10), // "sendBuffer"
QT_MOC_LITERAL(6, 64, 8), // "dataType"
QT_MOC_LITERAL(7, 73, 15), // "closeCurrentTab"
QT_MOC_LITERAL(8, 89, 11), // "ShowSystem*"
QT_MOC_LITERAL(9, 101, 6), // "system"
QT_MOC_LITERAL(10, 108, 31), // "on_pushBtn_ReviseSystem_clicked"
QT_MOC_LITERAL(11, 140, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 162, 12), // "showRecvData"
QT_MOC_LITERAL(13, 175, 4), // "flag"
QT_MOC_LITERAL(14, 180, 17) // "updateTableWidget"

    },
    "ShowSystem\0reviseSetting\0\0haveRecvData\0"
    "dataProcessed\0sendBuffer\0dataType\0"
    "closeCurrentTab\0ShowSystem*\0system\0"
    "on_pushBtn_ReviseSystem_clicked\0"
    "on_pushButton_clicked\0showRecvData\0"
    "flag\0updateTableWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    2,   60,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    1,   70,    2, 0x08 /* Private */,
      14,    2,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QStringList,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QStringList,    5,    6,

       0        // eod
};

void ShowSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowSystem *_t = static_cast<ShowSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reviseSetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haveRecvData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->dataProcessed((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->closeCurrentTab((*reinterpret_cast< ShowSystem*(*)>(_a[1]))); break;
        case 4: _t->on_pushBtn_ReviseSystem_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->showRecvData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->updateTableWidget((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ShowSystem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ShowSystem::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowSystem::reviseSetting)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ShowSystem::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowSystem::haveRecvData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ShowSystem::*_t)(QByteArray , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowSystem::dataProcessed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ShowSystem::*_t)(ShowSystem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowSystem::closeCurrentTab)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ShowSystem::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ShowSystem.data,
      qt_meta_data_ShowSystem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ShowSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowSystem.stringdata0))
        return static_cast<void*>(const_cast< ShowSystem*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ShowSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ShowSystem::reviseSetting(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShowSystem::haveRecvData(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ShowSystem::dataProcessed(QByteArray _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ShowSystem::closeCurrentTab(ShowSystem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
