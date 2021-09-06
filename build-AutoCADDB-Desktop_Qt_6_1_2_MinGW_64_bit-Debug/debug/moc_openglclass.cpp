/****************************************************************************
** Meta object code from reading C++ file 'openglclass.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoCADDB/openglclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openglclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenGLClass_t {
    const uint offsetsAndSize[16];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_OpenGLClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_OpenGLClass_t qt_meta_stringdata_OpenGLClass = {
    {
QT_MOC_LITERAL(0, 11), // "OpenGLClass"
QT_MOC_LITERAL(12, 11), // "setPenColor"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 8), // "newColor"
QT_MOC_LITERAL(34, 8), // "penColor"
QT_MOC_LITERAL(43, 11), // "setPenWidth"
QT_MOC_LITERAL(55, 8), // "newWidth"
QT_MOC_LITERAL(64, 8) // "penWidth"

    },
    "OpenGLClass\0setPenColor\0\0newColor\0"
    "penColor\0setPenWidth\0newWidth\0penWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGLClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    0 /* Public */,
       4,    0,   41,    2, 0x0a,    2 /* Public */,
       5,    1,   42,    2, 0x0a,    3 /* Public */,
       7,    0,   45,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Int,

       0        // eod
};

void OpenGLClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenGLClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPenColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: { QColor _r = _t->penColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->penWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject OpenGLClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_OpenGLClass.offsetsAndSize,
    qt_meta_data_OpenGLClass,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_OpenGLClass_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *OpenGLClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenGLClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGLClass.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int OpenGLClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
