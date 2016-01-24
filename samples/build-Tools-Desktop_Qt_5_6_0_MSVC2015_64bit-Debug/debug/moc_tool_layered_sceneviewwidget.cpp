/****************************************************************************
** Meta object code from reading C++ file 'tool_layered_sceneviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_layered_sceneviewwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_layered_sceneviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtLayeredSceneViewWidget_t {
    QByteArrayData data[5];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtLayeredSceneViewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtLayeredSceneViewWidget_t qt_meta_stringdata_Magus__QtLayeredSceneViewWidget = {
    {
QT_MOC_LITERAL(0, 0, 31), // "Magus::QtLayeredSceneViewWidget"
QT_MOC_LITERAL(1, 32, 16), // "handleLayerAdded"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 7), // "layerId"
QT_MOC_LITERAL(4, 58, 4) // "name"

    },
    "Magus::QtLayeredSceneViewWidget\0"
    "handleLayerAdded\0\0layerId\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtLayeredSceneViewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

       0        // eod
};

void Magus::QtLayeredSceneViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtLayeredSceneViewWidget *_t = static_cast<QtLayeredSceneViewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleLayerAdded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Magus::QtLayeredSceneViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtLayeredSceneViewWidget.data,
      qt_meta_data_Magus__QtLayeredSceneViewWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtLayeredSceneViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtLayeredSceneViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtLayeredSceneViewWidget.stringdata0))
        return static_cast<void*>(const_cast< QtLayeredSceneViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtLayeredSceneViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
