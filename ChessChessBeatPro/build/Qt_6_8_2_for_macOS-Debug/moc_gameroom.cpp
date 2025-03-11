/****************************************************************************
** Meta object code from reading C++ file 'gameroom.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameroom.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8GameRoomE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN8GameRoomE = QtMocHelpers::stringData(
    "GameRoom",
    "back_to_select",
    "",
    "upKeyPressed",
    "downKeyPressed",
    "leftKeyPressed",
    "rightKeyPressed",
    "wKeyPressed",
    "aKeyPressed",
    "sKeyPressed",
    "dKeyPressed"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN8GameRoomE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    0,   70,    2, 0x06,    3 /* Public */,
       5,    0,   71,    2, 0x06,    4 /* Public */,
       6,    0,   72,    2, 0x06,    5 /* Public */,
       7,    0,   73,    2, 0x06,    6 /* Public */,
       8,    0,   74,    2, 0x06,    7 /* Public */,
       9,    0,   75,    2, 0x06,    8 /* Public */,
      10,    0,   76,    2, 0x06,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN8GameRoomE.offsetsAndSizes,
    qt_meta_data_ZN8GameRoomE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN8GameRoomE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameRoom, std::true_type>,
        // method 'back_to_select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'upKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'downKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'leftKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rightKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<GameRoom *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->back_to_select(); break;
        case 1: _t->upKeyPressed(); break;
        case 2: _t->downKeyPressed(); break;
        case 3: _t->leftKeyPressed(); break;
        case 4: _t->rightKeyPressed(); break;
        case 5: _t->wKeyPressed(); break;
        case 6: _t->aKeyPressed(); break;
        case 7: _t->sKeyPressed(); break;
        case 8: _t->dKeyPressed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::back_to_select; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::upKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::downKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::leftKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::rightKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::wKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::aKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::sKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (GameRoom::*)();
            if (_q_method_type _q_method = &GameRoom::dKeyPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *GameRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN8GameRoomE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GameRoom::back_to_select()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameRoom::upKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameRoom::downKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameRoom::leftKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameRoom::rightKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GameRoom::wKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GameRoom::aKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GameRoom::sKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GameRoom::dKeyPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
