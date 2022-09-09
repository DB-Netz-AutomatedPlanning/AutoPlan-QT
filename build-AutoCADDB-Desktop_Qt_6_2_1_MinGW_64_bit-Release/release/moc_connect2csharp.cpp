/****************************************************************************
** Meta object code from reading C++ file 'connect2csharp.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/connect2csharp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connect2csharp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connect2CSharp_t {
    const uint offsetsAndSize[12];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Connect2CSharp_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Connect2CSharp_t qt_meta_stringdata_Connect2CSharp = {
    {
QT_MOC_LITERAL(0, 14), // "Connect2CSharp"
QT_MOC_LITERAL(15, 16), // "planningFinished"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 8), // "exitCode"
QT_MOC_LITERAL(42, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(63, 10) // "exitStatus"

    },
    "Connect2CSharp\0planningFinished\0\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connect2CSharp[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void Connect2CSharp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connect2CSharp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->planningFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Connect2CSharp::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Connect2CSharp.offsetsAndSize,
    qt_meta_data_Connect2CSharp,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Connect2CSharp_t
, QtPrivate::TypeAndForceComplete<Connect2CSharp, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>


>,
    nullptr
} };


const QMetaObject *Connect2CSharp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connect2CSharp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connect2CSharp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Connect2CSharp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
