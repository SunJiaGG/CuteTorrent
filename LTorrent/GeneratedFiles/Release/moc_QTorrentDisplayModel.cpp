/****************************************************************************
** Meta object code from reading C++ file 'QTorrentDisplayModel.h'
**
** Created: Wed 22. May 15:00:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTorrentDisplayModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTorrentDisplayModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTorrentDisplayModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      43,   21,   21,   21, 0x05,
      80,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,   21,   21,   21, 0x0a,
     133,   21,   21,   21, 0x0a,
     169,   21,   21,   21, 0x0a,
     196,   21,   21,   21, 0x0a,
     227,   21,   21,   21, 0x0a,
     250,   21,   21,   21, 0x0a,
     268,   21,   21,   21, 0x0a,
     286,   21,   21,   21, 0x0a,
     295,   21,   21,   21, 0x0a,
     312,   21,   21,   21, 0x0a,
     322,   21,   21,   21, 0x0a,
     332,   21,   21,   21, 0x0a,
     347,   21,   21,   21, 0x0a,
     365,   21,   21,   21, 0x0a,
     380,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTorrentDisplayModel[] = {
    "QTorrentDisplayModel\0\0updateTabSender(int)\0"
    "TorrentCompletedProxySender(QString)\0"
    "TorrentErrorPoxySender(QString)\0"
    "AddTorrent(Torrent*)\0"
    "UpdateSelectedIndex(QItemSelection)\0"
    "TorrentErrorProxy(QString)\0"
    "TorrentCompletedProxy(QString)\0"
    "contextualMenu(QPoint)\0OpenDirSelected()\0"
    "DellTorrentOnly()\0Rehash()\0UpdateTrackers()\0"
    "DellAll()\0MountDT()\0playInPlayer()\0"
    "setSequentualDL()\0moveStorrage()\0"
    "updateVisibleTorrents()\0"
};

void QTorrentDisplayModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QTorrentDisplayModel *_t = static_cast<QTorrentDisplayModel *>(_o);
        switch (_id) {
        case 0: _t->updateTabSender((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->TorrentCompletedProxySender((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->TorrentErrorPoxySender((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->AddTorrent((*reinterpret_cast< Torrent*(*)>(_a[1]))); break;
        case 4: _t->UpdateSelectedIndex((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 5: _t->TorrentErrorProxy((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->TorrentCompletedProxy((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->contextualMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->OpenDirSelected(); break;
        case 9: _t->DellTorrentOnly(); break;
        case 10: _t->Rehash(); break;
        case 11: _t->UpdateTrackers(); break;
        case 12: _t->DellAll(); break;
        case 13: _t->MountDT(); break;
        case 14: _t->playInPlayer(); break;
        case 15: _t->setSequentualDL(); break;
        case 16: _t->moveStorrage(); break;
        case 17: _t->updateVisibleTorrents(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QTorrentDisplayModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QTorrentDisplayModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_QTorrentDisplayModel,
      qt_meta_data_QTorrentDisplayModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTorrentDisplayModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTorrentDisplayModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTorrentDisplayModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTorrentDisplayModel))
        return static_cast<void*>(const_cast< QTorrentDisplayModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int QTorrentDisplayModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void QTorrentDisplayModel::updateTabSender(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTorrentDisplayModel::TorrentCompletedProxySender(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QTorrentDisplayModel::TorrentErrorPoxySender(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
