/****************************************************************************
** Meta object code from reading C++ file 'editsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DataCenter/editsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditSystem_t {
    QByteArrayData data[10];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditSystem_t qt_meta_stringdata_EditSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EditSystem"
QT_MOC_LITERAL(1, 11, 26), // "on_pushBtn_AddRecv_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 29), // "on_pushBtn_DeleteRecv_clicked"
QT_MOC_LITERAL(4, 69, 26), // "on_pushBtn_AddSend_clicked"
QT_MOC_LITERAL(5, 96, 29), // "on_pushBtn_DeleteSend_clicked"
QT_MOC_LITERAL(6, 126, 26), // "on_pushBtn_Confirm_clicked"
QT_MOC_LITERAL(7, 153, 25), // "on_pushBtn_Cancel_clicked"
QT_MOC_LITERAL(8, 179, 44), // "on_comboBox_SourceSystem_curr..."
QT_MOC_LITERAL(9, 224, 4) // "arg1"

    },
    "EditSystem\0on_pushBtn_AddRecv_clicked\0"
    "\0on_pushBtn_DeleteRecv_clicked\0"
    "on_pushBtn_AddSend_clicked\0"
    "on_pushBtn_DeleteSend_clicked\0"
    "on_pushBtn_Confirm_clicked\0"
    "on_pushBtn_Cancel_clicked\0"
    "on_comboBox_SourceSystem_currentIndexChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void EditSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditSystem *_t = static_cast<EditSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushBtn_AddRecv_clicked(); break;
        case 1: _t->on_pushBtn_DeleteRecv_clicked(); break;
        case 2: _t->on_pushBtn_AddSend_clicked(); break;
        case 3: _t->on_pushBtn_DeleteSend_clicked(); break;
        case 4: _t->on_pushBtn_Confirm_clicked(); break;
        case 5: _t->on_pushBtn_Cancel_clicked(); break;
        case 6: _t->on_comboBox_SourceSystem_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EditSystem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditSystem.data,
      qt_meta_data_EditSystem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditSystem.stringdata0))
        return static_cast<void*>(const_cast< EditSystem*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
