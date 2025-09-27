/****************************************************************************
** Meta object code from reading C++ file 'recentfiles.h'
**
** Created: Thu Aug 28 23:21:48 2025
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/recentfiles.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recentfiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecentFiles[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   12,   12,   12, 0x0a,
      81,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RecentFiles[] = {
    "RecentFiles\0\0fileName,errorString\0"
    "openFailed(QString,QString)\0"
    "writeRecentFiles()\0clearFiles()\0"
};

const QMetaObject RecentFiles::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_RecentFiles,
      qt_meta_data_RecentFiles, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RecentFiles::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RecentFiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RecentFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecentFiles))
        return static_cast<void*>(const_cast< RecentFiles*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int RecentFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFailed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: writeRecentFiles(); break;
        case 2: clearFiles(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RecentFiles::openFailed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
