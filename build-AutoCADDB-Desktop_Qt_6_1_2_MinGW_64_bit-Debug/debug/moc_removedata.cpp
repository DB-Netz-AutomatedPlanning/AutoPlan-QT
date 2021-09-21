/****************************************************************************
** Meta object code from reading C++ file 'removedata.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/removedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'removedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoveData_t {
    const uint offsetsAndSize[16];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RemoveData_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RemoveData_t qt_meta_stringdata_RemoveData = {
    {
QT_MOC_LITERAL(0, 10), // "RemoveData"
QT_MOC_LITERAL(11, 18), // "on_btnLoad_clicked"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 21), // "on_btnPreview_clicked"
QT_MOC_LITERAL(53, 36), // "on_comboAllFolder_currentText..."
QT_MOC_LITERAL(90, 32), // "on_comboFiles_currentTextChanged"
QT_MOC_LITERAL(123, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(144, 20) // "on_btnCancel_clicked"

    },
    "RemoveData\0on_btnLoad_clicked\0\0"
    "on_btnPreview_clicked\0"
    "on_comboAllFolder_currentTextChanged\0"
    "on_comboFiles_currentTextChanged\0"
    "on_btnDelete_clicked\0on_btnCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoveData[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    0,   51,    2, 0x08,    1 /* Private */,
       4,    0,   52,    2, 0x08,    2 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RemoveData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RemoveData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnLoad_clicked(); break;
        case 1: _t->on_btnPreview_clicked(); break;
        case 2: _t->on_comboAllFolder_currentTextChanged(); break;
        case 3: _t->on_comboFiles_currentTextChanged(); break;
        case 4: _t->on_btnDelete_clicked(); break;
        case 5: _t->on_btnCancel_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject RemoveData::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_RemoveData.offsetsAndSize,
    qt_meta_data_RemoveData,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RemoveData_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RemoveData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoveData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoveData.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RemoveData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
