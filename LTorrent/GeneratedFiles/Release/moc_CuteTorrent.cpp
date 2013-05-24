/****************************************************************************
** Meta object code from reading C++ file 'CuteTorrent.h'
**
** Created: Fri 24. May 10:41:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CuteTorrent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CuteTorrent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CuteTorrent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      39,   12,   12,   12, 0x08,
      53,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,
      86,   12,   12,   12, 0x08,
     104,   12,   12,   12, 0x08,
     127,   12,   12,   12, 0x08,
     153,   12,   12,   12, 0x08,
     177,   12,   12,   12, 0x08,
     208,   12,   12,   12, 0x08,
     235,   12,   12,   12, 0x08,
     247,   12,   12,   12, 0x08,
     265,   12,   12,   12, 0x08,
     291,   12,   12,   12, 0x08,
     319,   12,   12,   12, 0x08,
     335,  333,   12,   12, 0x08,
     369,   12,   12,   12, 0x08,
     388,  333,   12,   12, 0x08,
     432,  333,   12,   12, 0x08,
     471,   12,   12,   12, 0x08,
     497,   12,   12,   12, 0x08,
     521,   12,   12,   12, 0x08,
     537,   12,   12,   12, 0x08,
     552,   12,   12,   12, 0x08,
     569,   12,   12,   12, 0x08,
     586,   12,   12,   12, 0x08,
     602,   12,   12,   12, 0x08,
     618,   12,   12,   12, 0x08,
     634,   12,   12,   12, 0x08,
     653,   12,   12,   12, 0x08,
     681,  674,   12,   12, 0x08,
     730,   12,   12,   12, 0x08,
     751,   12,   12,   12, 0x08,
     767,   12,   12,   12, 0x08,
     782,   12,   12,   12, 0x08,
     800,   12,   12,   12, 0x08,
     820,  333,   12,   12, 0x08,
     845,   12,   12,   12, 0x08,
     858,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CuteTorrent[] = {
    "CuteTorrent\0\0HandleNewTorrent(QString)\0"
    "UpdateUL(int)\0UpdateDL(int)\0"
    "OpenFileSelected()\0OpenDirSelected()\0"
    "setLowForCurrentFile()\0setMediumForCurrentFile()\0"
    "setHighForCurrentFile()\0"
    "setNotDownloadForCurrentFile()\0"
    "fileTabContextMenu(QPoint)\0ShowAbout()\0"
    "checkForUpdates()\0ShowUpdateNitify(QString)\0"
    "ShowNoUpdateNitify(QString)\0retranslate()\0"
    ",\0ShowTorrentError(QString,QString)\0"
    "enableNitifyShow()\0"
    "showTorrentCompletedNotyfy(QString,QString)\0"
    "showTorrentInfoNotyfy(QString,QString)\0"
    "ShowCreateTorrentDialog()\0"
    "ShowOpenTorrentDialog()\0PauseSelected()\0"
    "StopSelected()\0ResumeSelected()\0"
    "DeleteSelected()\0UpdateInfoTab()\0"
    "UpdatePeerTab()\0UpdateFileTab()\0"
    "UpadteTrackerTab()\0OpenSettingsDialog()\0"
    "reason\0iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "updateTabWidget(int)\0ProcessMagnet()\0"
    "peformSearch()\0copyDiscribtion()\0"
    "clearPieceDisplay()\0updateItemWidth(int,int)\0"
    "AddTracker()\0AddPeer()\0"
};

void CuteTorrent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CuteTorrent *_t = static_cast<CuteTorrent *>(_o);
        switch (_id) {
        case 0: _t->HandleNewTorrent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->UpdateUL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->UpdateDL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OpenFileSelected(); break;
        case 4: _t->OpenDirSelected(); break;
        case 5: _t->setLowForCurrentFile(); break;
        case 6: _t->setMediumForCurrentFile(); break;
        case 7: _t->setHighForCurrentFile(); break;
        case 8: _t->setNotDownloadForCurrentFile(); break;
        case 9: _t->fileTabContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->ShowAbout(); break;
        case 11: _t->checkForUpdates(); break;
        case 12: _t->ShowUpdateNitify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->ShowNoUpdateNitify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->retranslate(); break;
        case 15: _t->ShowTorrentError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: _t->enableNitifyShow(); break;
        case 17: _t->showTorrentCompletedNotyfy((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->showTorrentInfoNotyfy((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->ShowCreateTorrentDialog(); break;
        case 20: _t->ShowOpenTorrentDialog(); break;
        case 21: _t->PauseSelected(); break;
        case 22: _t->StopSelected(); break;
        case 23: _t->ResumeSelected(); break;
        case 24: _t->DeleteSelected(); break;
        case 25: _t->UpdateInfoTab(); break;
        case 26: _t->UpdatePeerTab(); break;
        case 27: _t->UpdateFileTab(); break;
        case 28: _t->UpadteTrackerTab(); break;
        case 29: _t->OpenSettingsDialog(); break;
        case 30: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 31: _t->updateTabWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->ProcessMagnet(); break;
        case 33: _t->peformSearch(); break;
        case 34: _t->copyDiscribtion(); break;
        case 35: _t->clearPieceDisplay(); break;
        case 36: _t->updateItemWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: _t->AddTracker(); break;
        case 38: _t->AddPeer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CuteTorrent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CuteTorrent::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CuteTorrent,
      qt_meta_data_CuteTorrent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CuteTorrent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CuteTorrent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CuteTorrent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CuteTorrent))
        return static_cast<void*>(const_cast< CuteTorrent*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CuteTorrent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
