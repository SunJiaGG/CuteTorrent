/****************************************************************************
** Meta object code from reading C++ file 'OpenTorrentDialog.h'
**
** Created: Wed 22. May 15:00:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenTorrentDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenTorrentDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenTorrentDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      28,   18,   18,   18, 0x08,
      43,   18,   18,   18, 0x08,
      58,   18,   18,   18, 0x08,
      72,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenTorrentDialog[] = {
    "OpenTorrentDialog\0\0reject()\0BrowseButton()\0"
    "AccepTorrent()\0ChangeGroup()\0"
    "DownloadMetadataCompleted(openmagnet_info)\0"
};

void OpenTorrentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenTorrentDialog *_t = static_cast<OpenTorrentDialog *>(_o);
        switch (_id) {
        case 0: _t->reject(); break;
        case 1: _t->BrowseButton(); break;
        case 2: _t->AccepTorrent(); break;
        case 3: _t->ChangeGroup(); break;
        case 4: _t->DownloadMetadataCompleted((*reinterpret_cast< openmagnet_info(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OpenTorrentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenTorrentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OpenTorrentDialog,
      qt_meta_data_OpenTorrentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenTorrentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenTorrentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenTorrentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenTorrentDialog))
        return static_cast<void*>(const_cast< OpenTorrentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OpenTorrentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
