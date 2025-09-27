/****************************************************************************
** Meta object code from reading C++ file 'responseviewer.h'
**
** Created: Thu Aug 28 23:21:48 2025
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/responseviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'responseviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ResponseViewer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      44,   16,   15,   15, 0x05,
      74,   15,   15,   15, 0x05,
     111,   90,   15,   15, 0x05,
     165,  139,   15,   15, 0x05,
     207,  198,   15,   15, 0x05,
     248,  236,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     279,   15,   15,   15, 0x08,
     303,   15,   15,   15, 0x0a,
     328,   15,   15,   15, 0x0a,
     350,  348,   15,   15, 0x0a,
     383,   15,   15,   15, 0x0a,
     409,   15,   15,   15, 0x0a,
     434,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ResponseViewer[] = {
    "ResponseViewer\0\0currentFolder,saveRequested\0"
    "browseRequested(QString,bool)\0"
    "saveCompleted()\0fileName,errorString\0"
    "saveFailed(QString,QString)\0"
    "currentFolder,currentFile\0"
    "saveAsCompleted(QString,QString)\0"
    "fileName\0saveAsToBeConfirmed(QString)\0"
    "folder,file\0editorCleared(QString,QString)\0"
    "saveCurrentContent(int)\0"
    "menuCopyClicked(QString)\0menuSaveAsClicked()\0"
    ",\0saveAsRequested(QString,QString)\0"
    "newFolderChanged(QString)\0"
    "saveAsConfirmed(QString)\0"
    "saveBeforeClosed(QString)\0"
};

const QMetaObject ResponseViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ResponseViewer,
      qt_meta_data_ResponseViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResponseViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResponseViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResponseViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResponseViewer))
        return static_cast<void*>(const_cast< ResponseViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int ResponseViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: browseRequested((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: saveCompleted(); break;
        case 2: saveFailed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: saveAsCompleted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: saveAsToBeConfirmed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: editorCleared((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: saveCurrentContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: menuCopyClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: menuSaveAsClicked(); break;
        case 9: saveAsRequested((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: newFolderChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: saveAsConfirmed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: saveBeforeClosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ResponseViewer::browseRequested(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResponseViewer::saveCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ResponseViewer::saveFailed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ResponseViewer::saveAsCompleted(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ResponseViewer::saveAsToBeConfirmed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ResponseViewer::editorCleared(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
