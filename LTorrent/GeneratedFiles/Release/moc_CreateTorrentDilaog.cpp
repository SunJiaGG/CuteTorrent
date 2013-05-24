/****************************************************************************
** Meta object code from reading C++ file 'CreateTorrentDilaog.h'
**
** Created: Wed 22. May 15:00:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CreateTorrentDilaog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateTorrentDilaog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_torrentCreatorThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   22,   21,   21, 0x05,
      61,   56,   21,   21, 0x05,
      98,   89,   21,   21, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_torrentCreatorThread[] = {
    "torrentCreatorThread\0\0msg\0"
    "ShowCreationFailture(QString)\0path\0"
    "ShowCreationSucces(QString)\0progress\0"
    "updateProgress(int)\0"
};

void torrentCreatorThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        torrentCreatorThread *_t = static_cast<torrentCreatorThread *>(_o);
        switch (_id) {
        case 0: _t->ShowCreationFailture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ShowCreationSucces((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData torrentCreatorThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject torrentCreatorThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_torrentCreatorThread,
      qt_meta_data_torrentCreatorThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &torrentCreatorThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *torrentCreatorThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *torrentCreatorThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_torrentCreatorThread))
        return static_cast<void*>(const_cast< torrentCreatorThread*>(this));
    return QThread::qt_metacast(_clname);
}

int torrentCreatorThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void torrentCreatorThread::ShowCreationFailture(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void torrentCreatorThread::ShowCreationSucces(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void torrentCreatorThread::updateProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_CreateTorrentDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   20,   20,   20, 0x08,
      65,   20,   20,   20, 0x08,
      95,   20,   20,   20, 0x08,
     118,   20,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,
     143,   20,   20,   20, 0x08,
     157,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CreateTorrentDialog[] = {
    "CreateTorrentDialog\0\0AbortCreation()\0"
    "ShowCreationSucces(QString)\0"
    "ShowCreationFailture(QString)\0"
    "UpdateProgressBar(int)\0BrowseDir()\0"
    "BrowseFile()\0BeginCreate()\0Cancel()\0"
};

void CreateTorrentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CreateTorrentDialog *_t = static_cast<CreateTorrentDialog *>(_o);
        switch (_id) {
        case 0: _t->AbortCreation(); break;
        case 1: _t->ShowCreationSucces((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ShowCreationFailture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->UpdateProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->BrowseDir(); break;
        case 5: _t->BrowseFile(); break;
        case 6: _t->BeginCreate(); break;
        case 7: _t->Cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CreateTorrentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreateTorrentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateTorrentDialog,
      qt_meta_data_CreateTorrentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreateTorrentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreateTorrentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreateTorrentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateTorrentDialog))
        return static_cast<void*>(const_cast< CreateTorrentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateTorrentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CreateTorrentDialog::AbortCreation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
