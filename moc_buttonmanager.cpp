/****************************************************************************
** Meta object code from reading C++ file 'buttonmanager.h'
**
** Created: Thu Aug 28 23:21:48 2025
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/buttonmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buttonmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Button[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      22,    7,    7,    7, 0x05,

 // properties: name, type, flags
      43,   35, 0x0a495103,
      48,   35, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_Button[] = {
    "Button\0\0textChanged()\0urlChanged()\0"
    "QString\0text\0url\0"
};

const QMetaObject Button::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Button,
      qt_meta_data_Button, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Button::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Button::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Button))
        return static_cast<void*>(const_cast< Button*>(this));
    return QObject::qt_metacast(_clname);
}

int Button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: textChanged(); break;
        case 1: urlChanged(); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = text(); break;
        case 1: *reinterpret_cast< QString*>(_v) = url(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: setUrl(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Button::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Button::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_ButtonManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       3,  194, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      31,   14,   14,   14, 0x05,
      68,   47,   14,   14, 0x05,
     122,   96,   14,   14, 0x05,
     155,   14,   14,   14, 0x05,
     180,  171,   14,   14, 0x05,
     225,  213,   14,   14, 0x05,
     265,   14,   14,   14, 0x05,
     282,   14,   14,   14, 0x05,
     296,   14,   14,   14, 0x05,
     312,   14,   14,   14, 0x05,
     328,   14,   14,   14, 0x05,
     349,   14,   14,   14, 0x05,
     400,  372,   14,   14, 0x05,
     430,   14,   14,   14, 0x05,
     482,  448,   14,   14, 0x05,
     521,   47,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     549,   14,   14,   14, 0x0a,
     577,   14,   14,   14, 0x0a,
     599,   14,   14,   14, 0x0a,
     628,  625,   14,   14, 0x0a,
     671,   14,   14,   14, 0x0a,
     698,   14,   14,   14, 0x0a,
     724,   14,   14,   14, 0x0a,
     748,   14,   14,   14, 0x0a,
     773,   14,   14,   14, 0x0a,
     793,   14,   14,   14, 0x0a,
     818,   14,   14,   14, 0x0a,
     843,   14,   14,   14, 0x0a,
     863,   14,   14,   14, 0x08,

 // methods: signature, parameters, type, tag, flags
     896,  887,   14,   14, 0x02,
     929,  923,   14,   14, 0x02,
     962,  947,   14,   14, 0x02,
     996,   14,   14,   14, 0x02,
    1008,   14,   14,   14, 0x02,
    1020,   14,   14,   14, 0x02,

 // properties: name, type, flags
    1051, 1035, 0x00495009,
    1067, 1059, 0x0a495001,
    1079, 1059, 0x0a495001,

 // properties: notify_signal_id
       7,
      11,
      12,

       0        // eod
};

static const char qt_meta_stringdata_ButtonManager[] = {
    "ButtonManager\0\0editRequested()\0"
    "saveCompleted()\0fileName,errorString\0"
    "saveFailed(QString,QString)\0"
    "currentFolder,currentFile\0"
    "saveAsCompleted(QString,QString)\0"
    "appToBeClosed()\0fileName\0"
    "openRecentToBeConfirmed(QString)\0"
    "op,fileName\0newOrOpenToBeConfirmed(QString,QString)\0"
    "buttonsChanged()\0buttonAdded()\0"
    "buttonRemoved()\0buttonUpdated()\0"
    "currentFileChanged()\0currentFolderChanged()\0"
    "currentFolder,saveRequested\0"
    "browseRequested(QString,bool)\0"
    "recentRequested()\0content,currentFolder,currentFile\0"
    "openCompleted(QString,QString,QString)\0"
    "openFailed(QString,QString)\0"
    "newOrOpenConfirmed(QString)\0"
    "openRecentConfirmed()\0saveBeforeClosed(QString)\0"
    ",,\0recentFileClicked(QString,QString,QString)\0"
    "fileOpenRequested(QString)\0"
    "newFolderChanged(QString)\0"
    "menuNewClicked(QString)\0"
    "menuOpenClicked(QString)\0menuSaveAsClicked()\0"
    "menuQuitClicked(QString)\0"
    "toolEditClicked(QString)\0toolRecentClicked()\0"
    "saveCurrentContent(int)\0text,url\0"
    "addButton(QString,QString)\0index\0"
    "removeButton(int)\0index,text,url\0"
    "updateButton(int,QString,QString)\0"
    "saveToIni()\0newConfig()\0saveAsConfig()\0"
    "QList<QObject*>\0buttons\0QString\0"
    "currentFile\0currentFolder\0"
};

const QMetaObject ButtonManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ButtonManager,
      qt_meta_data_ButtonManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ButtonManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ButtonManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ButtonManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ButtonManager))
        return static_cast<void*>(const_cast< ButtonManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ButtonManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: editRequested(); break;
        case 1: saveCompleted(); break;
        case 2: saveFailed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: saveAsCompleted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: appToBeClosed(); break;
        case 5: openRecentToBeConfirmed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: newOrOpenToBeConfirmed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: buttonsChanged(); break;
        case 8: buttonAdded(); break;
        case 9: buttonRemoved(); break;
        case 10: buttonUpdated(); break;
        case 11: currentFileChanged(); break;
        case 12: currentFolderChanged(); break;
        case 13: browseRequested((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: recentRequested(); break;
        case 15: openCompleted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 16: openFailed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: newOrOpenConfirmed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: openRecentConfirmed(); break;
        case 19: saveBeforeClosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: recentFileClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 21: fileOpenRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: newFolderChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: menuNewClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: menuOpenClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: menuSaveAsClicked(); break;
        case 26: menuQuitClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: toolEditClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: toolRecentClicked(); break;
        case 29: saveCurrentContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: addButton((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 31: removeButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: updateButton((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 33: saveToIni(); break;
        case 34: newConfig(); break;
        case 35: saveAsConfig(); break;
        default: ;
        }
        _id -= 36;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QObject*>*>(_v) = buttons(); break;
        case 1: *reinterpret_cast< QString*>(_v) = currentFile(); break;
        case 2: *reinterpret_cast< QString*>(_v) = currentFolder(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ButtonManager::editRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ButtonManager::saveCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ButtonManager::saveFailed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ButtonManager::saveAsCompleted(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ButtonManager::appToBeClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ButtonManager::openRecentToBeConfirmed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ButtonManager::newOrOpenToBeConfirmed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ButtonManager::buttonsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void ButtonManager::buttonAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void ButtonManager::buttonRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void ButtonManager::buttonUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void ButtonManager::currentFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void ButtonManager::currentFolderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void ButtonManager::browseRequested(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ButtonManager::recentRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void ButtonManager::openCompleted(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ButtonManager::openFailed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE
