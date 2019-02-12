/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DEEF/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[43];
    char stringdata0[644];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "error"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "err"
QT_MOC_LITERAL(4, 22, 27), // "on_actionNew_File_triggered"
QT_MOC_LITERAL(5, 50, 28), // "on_actionLoad_File_triggered"
QT_MOC_LITERAL(6, 79, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(7, 103, 23), // "on_actionHelp_triggered"
QT_MOC_LITERAL(8, 127, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(9, 152, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(10, 173, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(11, 195, 15), // "on_cmd_finished"
QT_MOC_LITERAL(12, 211, 9), // "resetData"
QT_MOC_LITERAL(13, 221, 10), // "updateData"
QT_MOC_LITERAL(14, 232, 8), // "filePath"
QT_MOC_LITERAL(15, 241, 11), // "readCsvData"
QT_MOC_LITERAL(16, 253, 13), // "inputfilename"
QT_MOC_LITERAL(17, 267, 8), // "num_line"
QT_MOC_LITERAL(18, 276, 11), // "analyseData"
QT_MOC_LITERAL(19, 288, 19), // "getNewOptimalPoints"
QT_MOC_LITERAL(20, 308, 12), // "calDominance"
QT_MOC_LITERAL(21, 321, 8), // "method_n"
QT_MOC_LITERAL(22, 330, 7), // "calADRS"
QT_MOC_LITERAL(23, 338, 14), // "calHyperVolume"
QT_MOC_LITERAL(24, 353, 9), // "initGraph"
QT_MOC_LITERAL(25, 363, 11), // "updateGraph"
QT_MOC_LITERAL(26, 375, 12), // "setGraphData"
QT_MOC_LITERAL(27, 388, 16), // "QVector<QPointF>"
QT_MOC_LITERAL(28, 405, 6), // "points"
QT_MOC_LITERAL(29, 412, 9), // "QCPGraph*"
QT_MOC_LITERAL(30, 422, 5), // "graph"
QT_MOC_LITERAL(31, 428, 27), // "on_showOpRaioButton_clicked"
QT_MOC_LITERAL(32, 456, 29), // "on_showAllRadioButton_clicked"
QT_MOC_LITERAL(33, 486, 29), // "on_dataTreeWidget_itemChanged"
QT_MOC_LITERAL(34, 516, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(35, 533, 4), // "item"
QT_MOC_LITERAL(36, 538, 6), // "column"
QT_MOC_LITERAL(37, 545, 32), // "on_checkAllCheckBox_stateChanged"
QT_MOC_LITERAL(38, 578, 5), // "state"
QT_MOC_LITERAL(39, 584, 18), // "toggleGraphVisible"
QT_MOC_LITERAL(40, 603, 10), // "QCPLegend*"
QT_MOC_LITERAL(41, 614, 6), // "legend"
QT_MOC_LITERAL(42, 621, 22) // "QCPAbstractLegendItem*"

    },
    "MainWindow\0error\0\0err\0on_actionNew_File_triggered\0"
    "on_actionLoad_File_triggered\0"
    "on_actionExit_triggered\0on_actionHelp_triggered\0"
    "on_actionAbout_triggered\0on_runButton_clicked\0"
    "on_stopButton_clicked\0on_cmd_finished\0"
    "resetData\0updateData\0filePath\0readCsvData\0"
    "inputfilename\0num_line\0analyseData\0"
    "getNewOptimalPoints\0calDominance\0"
    "method_n\0calADRS\0calHyperVolume\0"
    "initGraph\0updateGraph\0setGraphData\0"
    "QVector<QPointF>\0points\0QCPGraph*\0"
    "graph\0on_showOpRaioButton_clicked\0"
    "on_showAllRadioButton_clicked\0"
    "on_dataTreeWidget_itemChanged\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_checkAllCheckBox_stateChanged\0state\0"
    "toggleGraphVisible\0QCPLegend*\0legend\0"
    "QCPAbstractLegendItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  142,    2, 0x08 /* Private */,
       5,    0,  143,    2, 0x08 /* Private */,
       6,    0,  144,    2, 0x08 /* Private */,
       7,    0,  145,    2, 0x08 /* Private */,
       8,    0,  146,    2, 0x08 /* Private */,
       9,    0,  147,    2, 0x08 /* Private */,
      10,    0,  148,    2, 0x08 /* Private */,
      11,    0,  149,    2, 0x08 /* Private */,
      12,    0,  150,    2, 0x08 /* Private */,
      13,    1,  151,    2, 0x08 /* Private */,
      15,    2,  154,    2, 0x08 /* Private */,
      18,    0,  159,    2, 0x08 /* Private */,
      19,    0,  160,    2, 0x08 /* Private */,
      20,    1,  161,    2, 0x08 /* Private */,
      22,    1,  164,    2, 0x08 /* Private */,
      23,    1,  167,    2, 0x08 /* Private */,
      24,    0,  170,    2, 0x08 /* Private */,
      25,    0,  171,    2, 0x08 /* Private */,
      26,    2,  172,    2, 0x08 /* Private */,
      31,    0,  177,    2, 0x08 /* Private */,
      32,    0,  178,    2, 0x08 /* Private */,
      33,    2,  179,    2, 0x08 /* Private */,
      37,    1,  184,    2, 0x08 /* Private */,
      39,    2,  187,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Int, QMetaType::QString, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Int,   21,
    QMetaType::Double, QMetaType::Int,   21,
    QMetaType::Double, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 29,   28,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34, QMetaType::Int,   35,   36,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, 0x80000000 | 40, 0x80000000 | 42,   41,   35,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_actionNew_File_triggered(); break;
        case 2: _t->on_actionLoad_File_triggered(); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_actionHelp_triggered(); break;
        case 5: _t->on_actionAbout_triggered(); break;
        case 6: _t->on_runButton_clicked(); break;
        case 7: _t->on_stopButton_clicked(); break;
        case 8: _t->on_cmd_finished(); break;
        case 9: _t->resetData(); break;
        case 10: _t->updateData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: { int _r = _t->readCsvData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->analyseData(); break;
        case 13: _t->getNewOptimalPoints(); break;
        case 14: { double _r = _t->calDominance((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 15: { double _r = _t->calADRS((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 16: { double _r = _t->calHyperVolume((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->initGraph(); break;
        case 18: _t->updateGraph(); break;
        case 19: _t->setGraphData((*reinterpret_cast< QVector<QPointF>(*)>(_a[1])),(*reinterpret_cast< QCPGraph*(*)>(_a[2]))); break;
        case 20: _t->on_showOpRaioButton_clicked(); break;
        case 21: _t->on_showAllRadioButton_clicked(); break;
        case 22: _t->on_dataTreeWidget_itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->on_checkAllCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->toggleGraphVisible((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPGraph* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPointF> >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractLegendItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPLegend* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::error)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
