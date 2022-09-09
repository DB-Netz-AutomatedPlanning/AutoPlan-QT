/****************************************************************************
** Meta object code from reading C++ file 'uploadnewdata.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/uploadnewdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploadnewdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UploadNewData_t {
    const uint offsetsAndSize[22];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UploadNewData_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UploadNewData_t qt_meta_stringdata_UploadNewData = {
    {
QT_MOC_LITERAL(0, 13), // "UploadNewData"
QT_MOC_LITERAL(14, 23), // "on_btnClickHere_clicked"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 25), // "on_btnGleisknoten_clicked"
QT_MOC_LITERAL(65, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(86, 19), // "on_btnHoehe_clicked"
QT_MOC_LITERAL(106, 20), // "on_btnKMLine_clicked"
QT_MOC_LITERAL(127, 25), // "on_btnGleiskanten_clicked"
QT_MOC_LITERAL(153, 18), // "on_btnLage_clicked"
QT_MOC_LITERAL(172, 24), // "on_btnUberhohung_clicked"
QT_MOC_LITERAL(197, 16) // "on_btnOK_clicked"

    },
    "UploadNewData\0on_btnClickHere_clicked\0"
    "\0on_btnGleisknoten_clicked\0"
    "on_btnCancel_clicked\0on_btnHoehe_clicked\0"
    "on_btnKMLine_clicked\0on_btnGleiskanten_clicked\0"
    "on_btnLage_clicked\0on_btnUberhohung_clicked\0"
    "on_btnOK_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UploadNewData[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UploadNewData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UploadNewData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnClickHere_clicked(); break;
        case 1: _t->on_btnGleisknoten_clicked(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_btnHoehe_clicked(); break;
        case 4: _t->on_btnKMLine_clicked(); break;
        case 5: _t->on_btnGleiskanten_clicked(); break;
        case 6: _t->on_btnLage_clicked(); break;
        case 7: _t->on_btnUberhohung_clicked(); break;
        case 8: _t->on_btnOK_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject UploadNewData::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_UploadNewData.offsetsAndSize,
    qt_meta_data_UploadNewData,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UploadNewData_t
, QtPrivate::TypeAndForceComplete<UploadNewData, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *UploadNewData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UploadNewData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UploadNewData.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UploadNewData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
