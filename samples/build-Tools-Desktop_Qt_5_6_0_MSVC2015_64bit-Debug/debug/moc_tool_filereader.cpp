/****************************************************************************
** Meta object code from reading C++ file 'tool_filereader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_filereader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_filereader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtFileReader_t {
    QByteArrayData data[8];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtFileReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtFileReader_t qt_meta_stringdata_Magus__QtFileReader = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Magus::QtFileReader"
QT_MOC_LITERAL(1, 20, 11), // "textureRead"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "pixmap"
QT_MOC_LITERAL(4, 40, 8), // "fileName"
QT_MOC_LITERAL(5, 49, 8), // "baseName"
QT_MOC_LITERAL(6, 58, 8), // "fileRead"
QT_MOC_LITERAL(7, 67, 4) // "path"

    },
    "Magus::QtFileReader\0textureRead\0\0"
    "pixmap\0fileName\0baseName\0fileRead\0"
    "path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtFileReader[] = {

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
       1,    3,   24,    2, 0x06 /* Public */,
       6,    3,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    4,    5,

       0        // eod
};

void Magus::QtFileReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtFileReader *_t = static_cast<QtFileReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textureRead((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->fileRead((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtFileReader::*_t)(const QPixmap & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtFileReader::textureRead)) {
                *result = 0;
            }
        }
        {
            typedef void (QtFileReader::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtFileReader::fileRead)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Magus::QtFileReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Magus__QtFileReader.data,
      qt_meta_data_Magus__QtFileReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtFileReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtFileReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtFileReader.stringdata0))
        return static_cast<void*>(const_cast< QtFileReader*>(this));
    return QObject::qt_metacast(_clname);
}

int Magus::QtFileReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Magus::QtFileReader::textureRead(const QPixmap & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Magus::QtFileReader::fileRead(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
