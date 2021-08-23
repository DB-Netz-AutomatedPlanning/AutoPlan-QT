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
    const uint offsetsAndSize[34];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_OpenGLClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_OpenGLClass_t qt_meta_stringdata_OpenGLClass = {
    {
QT_MOC_LITERAL(0, 11), // "OpenGLClass"
QT_MOC_LITERAL(12, 16), // "xRotationChanged"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 5), // "angle"
QT_MOC_LITERAL(36, 16), // "yRotationChanged"
QT_MOC_LITERAL(53, 16), // "zRotationChanged"
QT_MOC_LITERAL(70, 10), // "clearImage"
QT_MOC_LITERAL(81, 5), // "print"
QT_MOC_LITERAL(87, 12), // "setXRotation"
QT_MOC_LITERAL(100, 12), // "setYRotation"
QT_MOC_LITERAL(113, 12), // "setZRotation"
QT_MOC_LITERAL(126, 11), // "setPenColor"
QT_MOC_LITERAL(138, 8), // "newColor"
QT_MOC_LITERAL(147, 8), // "penColor"
QT_MOC_LITERAL(156, 11), // "setPenWidth"
QT_MOC_LITERAL(168, 8), // "newWidth"
QT_MOC_LITERAL(177, 8) // "penWidth"

    },
    "OpenGLClass\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "clearImage\0print\0setXRotation\0"
    "setYRotation\0setZRotation\0setPenColor\0"
    "newColor\0penColor\0setPenWidth\0newWidth\0"
    "penWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGLClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    0 /* Public */,
       4,    1,   89,    2, 0x06,    2 /* Public */,
       5,    1,   92,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   95,    2, 0x0a,    6 /* Public */,
       7,    0,   96,    2, 0x0a,    7 /* Public */,
       8,    1,   97,    2, 0x0a,    8 /* Public */,
       9,    1,  100,    2, 0x0a,   10 /* Public */,
      10,    1,  103,    2, 0x0a,   12 /* Public */,
      11,    1,  106,    2, 0x0a,   14 /* Public */,
      13,    0,  109,    2, 0x0a,   16 /* Public */,
      14,    1,  110,    2, 0x0a,   17 /* Public */,
      16,    0,  113,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Int,

       0        // eod
};

void OpenGLClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenGLClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->clearImage(); break;
        case 4: _t->print(); break;
        case 5: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setPenColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 9: { QColor _r = _t->penColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { int _r = _t->penWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OpenGLClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLClass::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OpenGLClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLClass::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OpenGLClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenGLClass::zRotationChanged)) {
                *result = 2;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void OpenGLClass::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OpenGLClass::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OpenGLClass::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
