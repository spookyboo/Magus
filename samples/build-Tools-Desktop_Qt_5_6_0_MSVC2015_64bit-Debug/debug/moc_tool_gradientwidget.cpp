/****************************************************************************
** Meta object code from reading C++ file 'tool_gradientwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tools/source/header/tool_gradientwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tool_gradientwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Magus__QtGradientWidget_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Magus__QtGradientWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Magus__QtGradientWidget_t qt_meta_stringdata_Magus__QtGradientWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Magus::QtGradientWidget"
QT_MOC_LITERAL(1, 24, 23), // "alphaSliderValueChanged"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "value"
QT_MOC_LITERAL(4, 55, 21), // "alphaEditValueChanged"
QT_MOC_LITERAL(5, 77, 15), // "valueChangedRGB"
QT_MOC_LITERAL(6, 93, 15), // "valueChangedHex"
QT_MOC_LITERAL(7, 109, 19), // "dialogButtonClicked"
QT_MOC_LITERAL(8, 129, 17), // "deleteAlphaMarker"
QT_MOC_LITERAL(9, 147, 17), // "deleteColorMarker"
QT_MOC_LITERAL(10, 165, 13) // "clearGradient"

    },
    "Magus::QtGradientWidget\0alphaSliderValueChanged\0"
    "\0value\0alphaEditValueChanged\0"
    "valueChangedRGB\0valueChangedHex\0"
    "dialogButtonClicked\0deleteAlphaMarker\0"
    "deleteColorMarker\0clearGradient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Magus__QtGradientWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Magus::QtGradientWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtGradientWidget *_t = static_cast<QtGradientWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alphaSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->alphaEditValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->valueChangedRGB(); break;
        case 3: _t->valueChangedHex(); break;
        case 4: _t->dialogButtonClicked(); break;
        case 5: _t->deleteAlphaMarker(); break;
        case 6: _t->deleteColorMarker(); break;
        case 7: _t->clearGradient(); break;
        default: ;
        }
    }
}

const QMetaObject Magus::QtGradientWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Magus__QtGradientWidget.data,
      qt_meta_data_Magus__QtGradientWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Magus::QtGradientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magus::QtGradientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Magus__QtGradientWidget.stringdata0))
        return static_cast<void*>(const_cast< QtGradientWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Magus::QtGradientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
