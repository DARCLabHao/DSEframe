#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QObject>
#include <QtCore>
#include <QProcess>

#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    void loadSettings();

    void saveSettings();

private slots:

    void on_actionNew_File_triggered();

    void on_actionLoad_File_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_runButton_clicked();

    void on_stopButton_clicked();

    void on_cmd_finished();

    void resetData();

    void updateData(const QString & filePath);

    int readCsvData(QString inputfilename, int num_line);

    void analyseData();

    void getNewOptimalPoints();

    double calDominance(int method_n);

    double calADRS(int method_n);

    double calHyperVolume(int method_n);

    void initGraph();

    void updateGraph();

    void setGraphData(QVector<QPointF> points, QCPGraph *graph);

    void on_showOpRaioButton_clicked();

    void on_showAllRadioButton_clicked();

    void on_dataTreeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_checkAllCheckBox_stateChanged(int state);

    void toggleGraphVisible(QCPLegend *legend, QCPAbstractLegendItem *item);

private:
    Ui::MainWindow *ui;

    QProcess *cmd_process;

    QString m_sSettingsFile;
    QString default_path;
    QString default_filename;

    QFileSystemWatcher *watcher;

    QVector< QTreeWidgetItem *> itm_parent;

    QVector< QPointF > op_points_all;
    QVector< QVector< QPointF > > op_points_local;
    QVector< QVector< QPointF > > data_points;

    int area_index;
    int latency_index;

    int x_max;
    int y_max;

    QString method_history;
    QString iteration_history;

    int method_cnt;
    int data_line_cnt;

    bool treeitem_change_enabled;
    bool checkall_checkbox_change_enabled;

    QList< QThread* > threads;

signals:
    void error(QString err);
};

#endif // MAINWINDOW_H
