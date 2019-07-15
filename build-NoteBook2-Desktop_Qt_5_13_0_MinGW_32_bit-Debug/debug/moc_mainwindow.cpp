/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NoteBook2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoteBook_t {
    QByteArrayData data[18];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoteBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoteBook_t qt_meta_stringdata_NoteBook = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NoteBook"
QT_MOC_LITERAL(1, 9, 12), // "Save_File_As"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "Open_File"
QT_MOC_LITERAL(4, 33, 9), // "Save_File"
QT_MOC_LITERAL(5, 43, 11), // "Create_File"
QT_MOC_LITERAL(6, 55, 15), // "Maybe_Save_File"
QT_MOC_LITERAL(7, 71, 10), // "closeEvent"
QT_MOC_LITERAL(8, 82, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 95, 5), // "event"
QT_MOC_LITERAL(10, 101, 11), // "Search_word"
QT_MOC_LITERAL(11, 113, 17), // "Text_Changed_Find"
QT_MOC_LITERAL(12, 131, 3), // "str"
QT_MOC_LITERAL(13, 135, 12), // "onSearchText"
QT_MOC_LITERAL(14, 148, 21), // "Text_Edit_Change_Find"
QT_MOC_LITERAL(15, 170, 15), // "Back_Color_Word"
QT_MOC_LITERAL(16, 186, 8), // "Copy_all"
QT_MOC_LITERAL(17, 195, 16) // "Open_Information"

    },
    "NoteBook\0Save_File_As\0\0Open_File\0"
    "Save_File\0Create_File\0Maybe_Save_File\0"
    "closeEvent\0QCloseEvent*\0event\0Search_word\0"
    "Text_Changed_Find\0str\0onSearchText\0"
    "Text_Edit_Change_Find\0Back_Color_Word\0"
    "Copy_all\0Open_Information"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoteBook[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NoteBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NoteBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Save_File_As(); break;
        case 1: _t->Open_File(); break;
        case 2: { bool _r = _t->Save_File();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->Create_File(); break;
        case 4: { bool _r = _t->Maybe_Save_File();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: _t->Search_word(); break;
        case 7: _t->Text_Changed_Find((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->onSearchText(); break;
        case 9: _t->Text_Edit_Change_Find(); break;
        case 10: _t->Back_Color_Word(); break;
        case 11: _t->Copy_all(); break;
        case 12: _t->Open_Information(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NoteBook::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_NoteBook.data,
    qt_meta_data_NoteBook,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NoteBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoteBook.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NoteBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
