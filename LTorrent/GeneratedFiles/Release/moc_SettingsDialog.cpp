/****************************************************************************
** Meta object code from reading C++ file 'SettingsDialog.h'
**
** Created: Wed 22. May 15:00:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SettingsDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      34,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   15,   15,   15, 0x08,
      65,   15,   15,   15, 0x08,
      81,   15,   15,   15, 0x08,
      92,   15,   15,   15, 0x08,
     106,   15,   15,   15, 0x08,
     128,   15,   15,   15, 0x08,
     143,   15,   15,   15, 0x08,
     171,  166,   15,   15, 0x08,
     186,   15,   15,   15, 0x08,
     196,   15,   15,   15, 0x08,
     215,  209,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingsDialog[] = {
    "SettingsDialog\0\0needRetranslate()\0"
    "tasksChanged()\0ApplyAndClose()\0"
    "ApplySettings()\0addGroup()\0removeGroup()\0"
    "browseSavepathGroup()\0browseDTPath()\0"
    "showSelectedGroup(int)\0date\0SetDate(QDate)\0"
    "AddTask()\0DeleteTask()\0index\0"
    "UpdateSchedullerTab(int)\0"
};

void SettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsDialog *_t = static_cast<SettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->needRetranslate(); break;
        case 1: _t->tasksChanged(); break;
        case 2: _t->ApplyAndClose(); break;
        case 3: _t->ApplySettings(); break;
        case 4: _t->addGroup(); break;
        case 5: _t->removeGroup(); break;
        case 6: _t->browseSavepathGroup(); break;
        case 7: _t->browseDTPath(); break;
        case 8: _t->showSelectedGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SetDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 10: _t->AddTask(); break;
        case 11: _t->DeleteTask(); break;
        case 12: _t->UpdateSchedullerTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingsDialog,
      qt_meta_data_SettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsDialog))
        return static_cast<void*>(const_cast< SettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SettingsDialog::needRetranslate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SettingsDialog::tasksChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
