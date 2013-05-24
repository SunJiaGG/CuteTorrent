/****************************************************************************
** Meta object code from reading C++ file 'mediacontroller.h'
**
** Created: Wed 22. May 15:00:35 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoPlayer/mediacontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediacontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MediaController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      37,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   16,   16,   16, 0x0a,
      61,   16,   16,   16, 0x0a,
      69,   16,   16,   16, 0x0a,
      80,   16,   16,   16, 0x0a,
      90,   16,   16,   16, 0x0a,
     100,   16,   16,   16, 0x0a,
     112,  110,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MediaController[] = {
    "MediaController\0\0updateMediaObject()\0"
    "newFile(QString)\0play()\0pause()\0"
    "openFile()\0openURL()\0reverse()\0forvard()\0"
    ",\0updateStateStatus(Phonon::State,Phonon::State)\0"
};

void MediaController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MediaController *_t = static_cast<MediaController *>(_o);
        switch (_id) {
        case 0: _t->updateMediaObject(); break;
        case 1: _t->newFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->play(); break;
        case 3: _t->pause(); break;
        case 4: _t->openFile(); break;
        case 5: _t->openURL(); break;
        case 6: _t->reverse(); break;
        case 7: _t->forvard(); break;
        case 8: _t->updateStateStatus((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MediaController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MediaController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MediaController,
      qt_meta_data_MediaController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MediaController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MediaController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MediaController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MediaController))
        return static_cast<void*>(const_cast< MediaController*>(this));
    return QObject::qt_metacast(_clname);
}

int MediaController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MediaController::updateMediaObject()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MediaController::newFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
