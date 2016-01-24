/****************************************************************************
** Meta object code from reading C++ file 'tool_sceneviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_sceneviewwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_sceneviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtSceneViewWidget_t {
    QByteArrayData data[18];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtSceneViewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtSceneViewWidget_t qt_meta_stringdata_Magus__QtSceneViewWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Magus::QtSceneViewWidget"
QT_MOC_LITERAL(1, 25, 19), // "groupCreatedOrAdded"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 12), // "QTreeWidget*"
QT_MOC_LITERAL(4, 59, 9), // "sceneView"
QT_MOC_LITERAL(5, 69, 7), // "groupId"
QT_MOC_LITERAL(6, 77, 19), // "assetCreatedOrAdded"
QT_MOC_LITERAL(7, 97, 7), // "assetId"
QT_MOC_LITERAL(8, 105, 12), // "groupDeleted"
QT_MOC_LITERAL(9, 118, 7), // "sceneId"
QT_MOC_LITERAL(10, 126, 12), // "assetDeleted"
QT_MOC_LITERAL(11, 139, 21), // "groupVisibiltyChanged"
QT_MOC_LITERAL(12, 161, 21), // "assetVisibiltyChanged"
QT_MOC_LITERAL(13, 183, 13), // "groupSelected"
QT_MOC_LITERAL(14, 197, 13), // "assetSelected"
QT_MOC_LITERAL(15, 211, 15), // "clearSearchLine"
QT_MOC_LITERAL(16, 227, 21), // "searchLineTextChanged"
QT_MOC_LITERAL(17, 249, 4) // "text"

    },
    "Magus::QtSceneViewWidget\0groupCreatedOrAdded\0"
    "\0QTreeWidget*\0sceneView\0groupId\0"
    "assetCreatedOrAdded\0assetId\0groupDeleted\0"
    "sceneId\0assetDeleted\0groupVisibiltyChanged\0"
    "assetVisibiltyChanged\0groupSelected\0"
    "assetSelected\0clearSearchLine\0"
    "searchLineTextChanged\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtSceneViewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       6,    3,   79,    2, 0x06 /* Public */,
       8,    2,   86,    2, 0x06 /* Public */,
       8,    2,   91,    2, 0x06 /* Public */,
      10,    3,   96,    2, 0x06 /* Public */,
      10,    3,  103,    2, 0x06 /* Public */,
      11,    2,  110,    2, 0x06 /* Public */,
      12,    3,  115,    2, 0x06 /* Public */,
      13,    2,  122,    2, 0x06 /* Public */,
      14,    3,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  134,    2, 0x0a /* Public */,
      16,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void Magus::QtSceneViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtSceneViewWidget *_t = static_cast<QtSceneViewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->groupCreatedOrAdded((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->assetCreatedOrAdded((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->groupDeleted((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->groupDeleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->assetDeleted((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->assetDeleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->groupVisibiltyChanged((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->assetVisibiltyChanged((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->groupSelected((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->assetSelected((*reinterpret_cast< QTreeWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->clearSearchLine(); break;
        case 11: _t->searchLineTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::groupCreatedOrAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::assetCreatedOrAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::groupDeleted)) {
                *result = 2;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::groupDeleted)) {
                *result = 3;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::assetDeleted)) {
                *result = 4;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::assetDeleted)) {
                *result = 5;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::groupVisibiltyChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::assetVisibiltyChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::groupSelected)) {
                *result = 8;
            }
        }
        {
            typedef void (QtSceneViewWidget::*_t)(QTreeWidget * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtSceneViewWidget::assetSelected)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject Magus::QtSceneViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtSceneViewWidget.data,
      qt_meta_data_Magus__QtSceneViewWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtSceneViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtSceneViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtSceneViewWidget.stringdata0))
        return static_cast<void*>(const_cast< QtSceneViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtSceneViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtSceneViewWidget::groupCreatedOrAdded(QTreeWidget * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtSceneViewWidget::assetCreatedOrAdded(QTreeWidget * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Magus::QtSceneViewWidget::groupDeleted(QTreeWidget * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Magus::QtSceneViewWidget::groupDeleted(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Magus::QtSceneViewWidget::assetDeleted(QTreeWidget * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Magus::QtSceneViewWidget::assetDeleted(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Magus::QtSceneViewWidget::groupVisibiltyChanged(QTreeWidget * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Magus::QtSceneViewWidget::assetVisibiltyChanged(QTreeWidget * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Magus::QtSceneViewWidget::groupSelected(QTreeWidget * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Magus::QtSceneViewWidget::assetSelected(QTreeWidget * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
