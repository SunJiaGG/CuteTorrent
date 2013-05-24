/****************************************************************************
** Meta object code from reading C++ file 'MediaControls.h'
**
** Created: Wed 22. May 15:00:35 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoPlayer/MediaControls.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaControls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MediaControls[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      25,   14,   14,   14, 0x05,
      35,   14,   14,   14, 0x05,
      42,   14,   14,   14, 0x05,
      53,   14,   14,   14, 0x05,
      63,   14,   14,   14, 0x05,
      77,   71,   14,   14, 0x05,
      92,   71,   14,   14, 0x05,
     109,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     133,  128,   14,   14, 0x0a,
     152,  128,   14,   14, 0x0a,
     176,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MediaControls[] = {
    "MediaControls\0\0forvard()\0reverse()\0"
    "play()\0openFile()\0openURL()\0pause()\0"
    "value\0setVolume(int)\0setPosition(int)\0"
    "toggleFullScreen()\0time\0updateTime(qint64)\0"
    "updateTotalTime(qint64)\0updateMedaiObject()\0"
};

void MediaControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MediaControls *_t = static_cast<MediaControls *>(_o);
        switch (_id) {
        case 0: _t->forvard(); break;
        case 1: _t->reverse(); break;
        case 2: _t->play(); break;
        case 3: _t->openFile(); break;
        case 4: _t->openURL(); break;
        case 5: _t->pause(); break;
        case 6: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleFullScreen(); break;
        case 9: _t->updateTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->updateTotalTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 11: _t->updateMedaiObject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MediaControls::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MediaControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MediaControls,
      qt_meta_data_MediaControls, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MediaControls::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MediaControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MediaControls::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MediaControls))
        return static_cast<void*>(const_cast< MediaControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int MediaControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MediaControls::forvard()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MediaControls::reverse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MediaControls::play()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MediaControls::openFile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MediaControls::openURL()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MediaControls::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MediaControls::setVolume(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MediaControls::setPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MediaControls::toggleFullScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
