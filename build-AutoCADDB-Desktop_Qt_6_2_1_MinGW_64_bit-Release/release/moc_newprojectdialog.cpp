/****************************************************************************
** Meta object code from reading C++ file 'newprojectdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/newprojectdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprojectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewProjectDialog_t {
    const uint offsetsAndSize[14];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NewProjectDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NewProjectDialog_t qt_meta_stringdata_NewProjectDialog = {
    {
QT_MOC_LITERAL(0, 16), // "NewProjectDialog"
QT_MOC_LITERAL(17, 7), // "timeout"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 31), // "on_btnBrowseProjectPath_clicked"
QT_MOC_LITERAL(58, 31), // "on_btnBrowseProjectData_clicked"
QT_MOC_LITERAL(90, 30), // "on_btnCreateNewProject_clicked"
QT_MOC_LITERAL(121, 20) // "on_btnCancel_clicked"

    },
    "NewProjectDialog\0timeout\0\0"
    "on_btnBrowseProjectPath_clicked\0"
    "on_btnBrowseProjectData_clicked\0"
    "on_btnCreateNewProject_clicked\0"
    "on_btnCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewProjectDialog[] = {

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
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewProjectDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->on_btnBrowseProjectPath_clicked(); break;
        case 2: _t->on_btnBrowseProjectData_clicked(); break;
        case 3: _t->on_btnCreateNewProject_clicked(); break;
        case 4: _t->on_btnCancel_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject NewProjectDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_NewProjectDialog.offsetsAndSize,
    qt_meta_data_NewProjectDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NewProjectDialog_t
, QtPrivate::TypeAndForceComplete<NewProjectDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NewProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewProjectDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
