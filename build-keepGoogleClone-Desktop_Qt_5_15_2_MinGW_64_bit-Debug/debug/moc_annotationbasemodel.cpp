/****************************************************************************
** Meta object code from reading C++ file 'annotationbasemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../keepGoogleClone/annotationbasemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'annotationbasemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnnotationBaseModel_t {
    QByteArrayData data[15];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnnotationBaseModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnnotationBaseModel_t qt_meta_stringdata_AnnotationBaseModel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AnnotationBaseModel"
QT_MOC_LITERAL(1, 20, 4), // "data"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 38, 5), // "index"
QT_MOC_LITERAL(5, 44, 4), // "role"
QT_MOC_LITERAL(6, 49, 9), // "roleNames"
QT_MOC_LITERAL(7, 59, 21), // "QHash<int,QByteArray>"
QT_MOC_LITERAL(8, 81, 13), // "addAnnotation"
QT_MOC_LITERAL(9, 95, 4), // "name"
QT_MOC_LITERAL(10, 100, 11), // "description"
QT_MOC_LITERAL(11, 112, 5), // "color"
QT_MOC_LITERAL(12, 118, 16), // "removeAnnotation"
QT_MOC_LITERAL(13, 135, 2), // "id"
QT_MOC_LITERAL(14, 138, 16) // "updateAnnotation"

    },
    "AnnotationBaseModel\0data\0\0QModelIndex\0"
    "index\0role\0roleNames\0QHash<int,QByteArray>\0"
    "addAnnotation\0name\0description\0color\0"
    "removeAnnotation\0id\0updateAnnotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnnotationBaseModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x02 /* Public */,
       1,    1,   49,    2, 0x22 /* Public | MethodCloned */,
       6,    0,   52,    2, 0x02 /* Public */,
       8,    3,   53,    2, 0x02 /* Public */,
      12,    1,   60,    2, 0x02 /* Public */,
      14,    4,   63,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QVariant, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::QVariant, 0x80000000 | 3,    4,
    0x80000000 | 7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,    9,   10,   11,

       0        // eod
};

void AnnotationBaseModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnnotationBaseModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QHash<int,QByteArray> _r = _t->roleNames();
            if (_a[0]) *reinterpret_cast< QHash<int,QByteArray>*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->addAnnotation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->removeAnnotation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->updateAnnotation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AnnotationBaseModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlTableModel::staticMetaObject>(),
    qt_meta_stringdata_AnnotationBaseModel.data,
    qt_meta_data_AnnotationBaseModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnnotationBaseModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnnotationBaseModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnnotationBaseModel.stringdata0))
        return static_cast<void*>(this);
    return QSqlTableModel::qt_metacast(_clname);
}

int AnnotationBaseModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE