/****************************************************************************
** Meta object code from reading C++ file 'tool_extended_texturewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_extended_texturewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_extended_texturewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtTextureAndText_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtTextureAndText_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtTextureAndText_t qt_meta_stringdata_Magus__QtTextureAndText = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Magus::QtTextureAndText"
QT_MOC_LITERAL(1, 24, 8), // "selected"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "name"
QT_MOC_LITERAL(4, 39, 8), // "baseName"
QT_MOC_LITERAL(5, 48, 13), // "doubleClicked"
QT_MOC_LITERAL(6, 62, 14), // "handleSelected"
QT_MOC_LITERAL(7, 77, 19) // "handleDoubleClicked"

    },
    "Magus::QtTextureAndText\0selected\0\0"
    "name\0baseName\0doubleClicked\0handleSelected\0"
    "handleDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtTextureAndText[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   44,    2, 0x09 /* Protected */,
       7,    2,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void Magus::QtTextureAndText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtTextureAndText *_t = static_cast<QtTextureAndText *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->doubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->handleSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->handleDoubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtTextureAndText::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtTextureAndText::selected)) {
                *result = 0;
            }
        }
        {
            typedef void (QtTextureAndText::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtTextureAndText::doubleClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Magus::QtTextureAndText::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtTextureAndText.data,
      qt_meta_data_Magus__QtTextureAndText,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtTextureAndText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtTextureAndText::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtTextureAndText.stringdata0))
        return static_cast<void*>(const_cast< QtTextureAndText*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtTextureAndText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtTextureAndText::selected(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtTextureAndText::doubleClicked(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Magus__QtExtendedTextureListWidget_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtExtendedTextureListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtExtendedTextureListWidget_t qt_meta_stringdata_Magus__QtExtendedTextureListWidget = {
    {
QT_MOC_LITERAL(0, 0, 34), // "Magus::QtExtendedTextureListW..."
QT_MOC_LITERAL(1, 35, 18), // "textureFileDropped"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 4), // "name"
QT_MOC_LITERAL(4, 60, 8), // "baseName"
QT_MOC_LITERAL(5, 69, 12) // "assetDeleted"

    },
    "Magus::QtExtendedTextureListWidget\0"
    "textureFileDropped\0\0name\0baseName\0"
    "assetDeleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtExtendedTextureListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    2,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void Magus::QtExtendedTextureListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtExtendedTextureListWidget *_t = static_cast<QtExtendedTextureListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textureFileDropped((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->assetDeleted((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtExtendedTextureListWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureListWidget::textureFileDropped)) {
                *result = 0;
            }
        }
        {
            typedef void (QtExtendedTextureListWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureListWidget::assetDeleted)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Magus::QtExtendedTextureListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_Magus__QtExtendedTextureListWidget.data,
      qt_meta_data_Magus__QtExtendedTextureListWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtExtendedTextureListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtExtendedTextureListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtExtendedTextureListWidget.stringdata0))
        return static_cast<void*>(const_cast< QtExtendedTextureListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int Magus::QtExtendedTextureListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtExtendedTextureListWidget::textureFileDropped(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtExtendedTextureListWidget::assetDeleted(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Magus__QtExtendedTextureWidget_t {
    QByteArrayData data[15];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtExtendedTextureWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtExtendedTextureWidget_t qt_meta_stringdata_Magus__QtExtendedTextureWidget = {
    {
QT_MOC_LITERAL(0, 0, 30), // "Magus::QtExtendedTextureWidget"
QT_MOC_LITERAL(1, 31, 8), // "selected"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "name"
QT_MOC_LITERAL(4, 46, 8), // "baseName"
QT_MOC_LITERAL(5, 55, 13), // "doubleClicked"
QT_MOC_LITERAL(6, 69, 18), // "textureFileDropped"
QT_MOC_LITERAL(7, 88, 12), // "assetDeleted"
QT_MOC_LITERAL(8, 101, 14), // "handleSelected"
QT_MOC_LITERAL(9, 116, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 133, 4), // "item"
QT_MOC_LITERAL(11, 138, 19), // "handleDoubleClicked"
QT_MOC_LITERAL(12, 158, 24), // "handleTextureFileDropped"
QT_MOC_LITERAL(13, 183, 15), // "handleMouseOver"
QT_MOC_LITERAL(14, 199, 18) // "handleAssetDeleted"

    },
    "Magus::QtExtendedTextureWidget\0selected\0"
    "\0name\0baseName\0doubleClicked\0"
    "textureFileDropped\0assetDeleted\0"
    "handleSelected\0QListWidgetItem*\0item\0"
    "handleDoubleClicked\0handleTextureFileDropped\0"
    "handleMouseOver\0handleAssetDeleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtExtendedTextureWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       6,    2,   79,    2, 0x06 /* Public */,
       7,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   89,    2, 0x09 /* Protected */,
       8,    2,   92,    2, 0x09 /* Protected */,
      11,    1,   97,    2, 0x09 /* Protected */,
      11,    2,  100,    2, 0x09 /* Protected */,
      12,    2,  105,    2, 0x09 /* Protected */,
      13,    1,  110,    2, 0x09 /* Protected */,
      14,    2,  113,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void Magus::QtExtendedTextureWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtExtendedTextureWidget *_t = static_cast<QtExtendedTextureWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->doubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->textureFileDropped((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->assetDeleted((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->handleSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->handleSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->handleDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->handleDoubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->handleTextureFileDropped((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->handleMouseOver((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->handleAssetDeleted((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtExtendedTextureWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureWidget::selected)) {
                *result = 0;
            }
        }
        {
            typedef void (QtExtendedTextureWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureWidget::doubleClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (QtExtendedTextureWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureWidget::textureFileDropped)) {
                *result = 2;
            }
        }
        {
            typedef void (QtExtendedTextureWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtExtendedTextureWidget::assetDeleted)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Magus::QtExtendedTextureWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtExtendedTextureWidget.data,
      qt_meta_data_Magus__QtExtendedTextureWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtExtendedTextureWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtExtendedTextureWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtExtendedTextureWidget.stringdata0))
        return static_cast<void*>(const_cast< QtExtendedTextureWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtExtendedTextureWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Magus::QtExtendedTextureWidget::selected(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtExtendedTextureWidget::doubleClicked(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Magus::QtExtendedTextureWidget::textureFileDropped(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Magus::QtExtendedTextureWidget::assetDeleted(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
