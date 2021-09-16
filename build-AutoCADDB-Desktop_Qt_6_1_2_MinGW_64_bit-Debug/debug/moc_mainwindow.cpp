/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 6), // "addTab"
QT_MOC_LITERAL(43, 8), // "closeTab"
QT_MOC_LITERAL(52, 8), // "penColor"
QT_MOC_LITERAL(61, 8), // "penWidth"
QT_MOC_LITERAL(70, 14), // "openCalculator"
QT_MOC_LITERAL(85, 8), // "hideFile"
QT_MOC_LITERAL(94, 7), // "hideTab"
QT_MOC_LITERAL(102, 5), // "print"
QT_MOC_LITERAL(108, 4), // "exit"
QT_MOC_LITERAL(113, 13), // "openSvgDialog"
QT_MOC_LITERAL(127, 14), // "openSvgOptions"
QT_MOC_LITERAL(142, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(166, 16), // "fetchObjectProps"
QT_MOC_LITERAL(183, 4), // "save"
QT_MOC_LITERAL(188, 4), // "open"
QT_MOC_LITERAL(193, 15), // "exportToPicture"
QT_MOC_LITERAL(209, 16), // "importShapeFiles"
QT_MOC_LITERAL(226, 11) // "planningFnt"

    },
    "MainWindow\0on_actionSave_triggered\0\0"
    "addTab\0closeTab\0penColor\0penWidth\0"
    "openCalculator\0hideFile\0hideTab\0print\0"
    "exit\0openSvgDialog\0openSvgOptions\0"
    "on_actionOpen_triggered\0fetchObjectProps\0"
    "save\0open\0exportToPicture\0importShapeFiles\0"
    "planningFnt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    0 /* Private */,
       3,    0,  129,    2, 0x08,    1 /* Private */,
       4,    1,  130,    2, 0x08,    2 /* Private */,
       5,    0,  133,    2, 0x08,    4 /* Private */,
       6,    0,  134,    2, 0x08,    5 /* Private */,
       7,    0,  135,    2, 0x08,    6 /* Private */,
       8,    0,  136,    2, 0x08,    7 /* Private */,
       9,    0,  137,    2, 0x08,    8 /* Private */,
      10,    0,  138,    2, 0x08,    9 /* Private */,
      11,    0,  139,    2, 0x08,   10 /* Private */,
      12,    0,  140,    2, 0x08,   11 /* Private */,
      13,    0,  141,    2, 0x08,   12 /* Private */,
      14,    0,  142,    2, 0x08,   13 /* Private */,
      15,    0,  143,    2, 0x08,   14 /* Private */,
      16,    0,  144,    2, 0x08,   15 /* Private */,
      17,    0,  145,    2, 0x08,   16 /* Private */,
      18,    0,  146,    2, 0x08,   17 /* Private */,
      19,    0,  147,    2, 0x08,   18 /* Private */,
      20,    0,  148,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionSave_triggered(); break;
        case 1: _t->addTab(); break;
        case 2: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->penColor(); break;
        case 4: _t->penWidth(); break;
        case 5: _t->openCalculator(); break;
        case 6: _t->hideFile(); break;
        case 7: _t->hideTab(); break;
        case 8: _t->print(); break;
        case 9: _t->exit(); break;
        case 10: _t->openSvgDialog(); break;
        case 11: _t->openSvgOptions(); break;
        case 12: _t->on_actionOpen_triggered(); break;
        case 13: _t->fetchObjectProps(); break;
        case 14: _t->save(); break;
        case 15: _t->open(); break;
        case 16: _t->exportToPicture(); break;
        case 17: _t->importShapeFiles(); break;
        case 18: _t->planningFnt(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
