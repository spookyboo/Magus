/****************************************************************************
** Meta object code from reading C++ file 'tool_simple_texturewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_simple_texturewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_simple_texturewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtSimpleTextureWidget_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtSimpleTextureWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtSimpleTextureWidget_t qt_meta_stringdata_Magus__QtSimpleTextureWidget = {
    {
QT_MOC_LITERAL(0, 0, 28), // "Magus::QtSimpleTextureWidget"
QT_MOC_LITERAL(1, 29, 8), // "selected"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "name"
QT_MOC_LITERAL(4, 44, 13), // "doubleClicked"
QT_MOC_LITERAL(5, 58, 14), // "handleSelected"
QT_MOC_LITERAL(6, 73, 5), // "index"
QT_MOC_LITERAL(7, 79, 19), // "handleDoubleClicked"
QT_MOC_LITERAL(8, 99, 9) // "mouseOver"

    },
    "Magus::QtSimpleTextureWidget\0selected\0"
    "\0name\0doubleClicked\0handleSelected\0"
    "index\0handleDoubleClicked\0mouseOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtSimpleTextureWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   45,    2, 0x09 /* Protected */,
       7,    1,   48,    2, 0x09 /* Protected */,
       8,    1,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,

       0        // eod
};

void Magus::QtSimpleTextureWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtSimpleTextureWidget *_t = static_cast<QtSimpleTextureWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->doubleClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->handleSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->handleDoubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->mouseOver((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtSimpleTextureWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSimpleTextureWidget::selected)) {
                *result = 0;
            }
        }
        {
            typedef void (QtSimpleTextureWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSimpleTextureWidget::doubleClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Magus::QtSimpleTextureWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtSimpleTextureWidget.data,
      qt_meta_data_Magus__QtSimpleTextureWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtSimpleTextureWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtSimpleTextureWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtSimpleTextureWidget.stringdata0))
        return static_cast<void*>(const_cast< QtSimpleTextureWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtSimpleTextureWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtSimpleTextureWidget::selected(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtSimpleTextureWidget::doubleClicked(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
