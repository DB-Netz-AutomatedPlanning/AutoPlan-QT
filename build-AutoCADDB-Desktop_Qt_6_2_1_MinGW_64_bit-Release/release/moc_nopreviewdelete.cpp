/****************************************************************************
** Meta object code from reading C++ file 'nopreviewdelete.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/nopreviewdelete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nopreviewdelete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoPreviewDelete_t {
    const uint offsetsAndSize[16];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NoPreviewDelete_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NoPreviewDelete_t qt_meta_stringdata_NoPreviewDelete = {
    {
QT_MOC_LITERAL(0, 15), // "NoPreviewDelete"
QT_MOC_LITERAL(16, 20), // "on_btnLoad_6_clicked"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 38), // "on_comboAllFolder_6_currentTe..."
QT_MOC_LITERAL(77, 32), // "on_checkBoxEntireStation_toggled"
QT_MOC_LITERAL(110, 7), // "checked"
QT_MOC_LITERAL(118, 22), // "on_btnCancel_6_clicked"
QT_MOC_LITERAL(141, 22) // "on_btnDelete_6_clicked"

    },
    "NoPreviewDelete\0on_btnLoad_6_clicked\0"
    "\0on_comboAllFolder_6_currentTextChanged\0"
    "on_checkBoxEntireStation_toggled\0"
    "checked\0on_btnCancel_6_clicked\0"
    "on_btnDelete_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoPreviewDelete[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NoPreviewDelete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NoPreviewDelete *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnLoad_6_clicked(); break;
        case 1: _t->on_comboAllFolder_6_currentTextChanged(); break;
        case 2: _t->on_checkBoxEntireStation_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_btnCancel_6_clicked(); break;
        case 4: _t->on_btnDelete_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NoPreviewDelete::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_NoPreviewDelete.offsetsAndSize,
    qt_meta_data_NoPreviewDelete,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NoPreviewDelete_t
, QtPrivate::TypeAndForceComplete<NoPreviewDelete, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NoPreviewDelete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoPreviewDelete::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoPreviewDelete.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NoPreviewDelete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
