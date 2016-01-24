/****************************************************************************
** Meta object code from reading C++ file 'tool_layerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_layerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_layerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtLayerWidget_t {
    QByteArrayData data[19];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtLayerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtLayerWidget_t qt_meta_stringdata_Magus__QtLayerWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Magus::QtLayerWidget"
QT_MOC_LITERAL(1, 21, 21), // "layerVisibiltyChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 7), // "layerId"
QT_MOC_LITERAL(4, 52, 4), // "name"
QT_MOC_LITERAL(5, 57, 7), // "visible"
QT_MOC_LITERAL(6, 65, 19), // "layerCreatedOrAdded"
QT_MOC_LITERAL(7, 85, 12), // "layerDeleted"
QT_MOC_LITERAL(8, 98, 13), // "layerSelected"
QT_MOC_LITERAL(9, 112, 23), // "contextMenuItemSelected"
QT_MOC_LITERAL(10, 136, 8), // "QAction*"
QT_MOC_LITERAL(11, 145, 6), // "action"
QT_MOC_LITERAL(12, 152, 12), // "tableClicked"
QT_MOC_LITERAL(13, 165, 5), // "index"
QT_MOC_LITERAL(14, 171, 12), // "groupDeleted"
QT_MOC_LITERAL(15, 184, 7), // "sceneId"
QT_MOC_LITERAL(16, 192, 7), // "groupId"
QT_MOC_LITERAL(17, 200, 12), // "assetDeleted"
QT_MOC_LITERAL(18, 213, 7) // "assetId"

    },
    "Magus::QtLayerWidget\0layerVisibiltyChanged\0"
    "\0layerId\0name\0visible\0layerCreatedOrAdded\0"
    "layerDeleted\0layerSelected\0"
    "contextMenuItemSelected\0QAction*\0"
    "action\0tableClicked\0index\0groupDeleted\0"
    "sceneId\0groupId\0assetDeleted\0assetId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtLayerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       6,    2,   61,    2, 0x06 /* Public */,
       7,    2,   66,    2, 0x06 /* Public */,
       8,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
      14,    2,   82,    2, 0x0a /* Public */,
      17,    3,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QModelIndex,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   18,

       0        // eod
};

void Magus::QtLayerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtLayerWidget *_t = static_cast<QtLayerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerVisibiltyChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->layerCreatedOrAdded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->layerDeleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->layerSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->contextMenuItemSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->tableClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->groupDeleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->assetDeleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtLayerWidget::*_t)(int , const QString & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtLayerWidget::layerVisibiltyChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QtLayerWidget::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtLayerWidget::layerCreatedOrAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (QtLayerWidget::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtLayerWidget::layerDeleted)) {
                *result = 2;
            }
        }
        {
            typedef void (QtLayerWidget::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtLayerWidget::layerSelected)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Magus::QtLayerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtLayerWidget.data,
      qt_meta_data_Magus__QtLayerWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtLayerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtLayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtLayerWidget.stringdata0))
        return static_cast<void*>(const_cast< QtLayerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtLayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtLayerWidget::layerVisibiltyChanged(int _t1, const QString & _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtLayerWidget::layerCreatedOrAdded(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Magus::QtLayerWidget::layerDeleted(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Magus::QtLayerWidget::layerSelected(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
