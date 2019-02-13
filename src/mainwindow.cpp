#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutwindow.h"
#include "helpwindow.h"
#include "newfile.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QThread>
#include <QFileSystemWatcher>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DSE Explorer Framework");

    watcher = new QFileSystemWatcher(this);
    connect(watcher, SIGNAL(fileChanged(const QString & )),
            this,    SLOT(updateData(const QString & )));

    resetData();

    m_sSettingsFile = QApplication::applicationDirPath() + "/demosettings.ini";
    loadSettings();
}

MainWindow::~MainWindow()
{
    if (ui->stopButton->isEnabled()) {
        on_stopButton_clicked();
    }

    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    default_path = settings.value("directoryPath", "").toString();
    default_filename = settings.value("fileName", "").toString();
}

void MainWindow::saveSettings()
{
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    settings.setValue("directoryPath", default_path);
    settings.setValue("fileName", default_filename);
}

void MainWindow::on_actionNew_File_triggered()
{
    Newfile *newfile = new Newfile(this);

    int result = newfile->exec();
    if (result == QDialog::Accepted) {
        resetData();

        QString fileName = newfile->fileName;
        QFile file(fileName);
        file.open(QFile::ReadWrite | QFile::Truncate);
        file.close();

        ui->fileNameLabel->setText(fileName);
        watcher->addPath(fileName);
    }
}

void MainWindow::on_actionLoad_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    default_path + "/" + default_filename,
                                                    tr("CSV File(*.csv);;All Files(*);;Text File(*.txt)"));
    if (!fileName.isEmpty()) {
        resetData();

        readCsvData(fileName, 0);
        analyseData();
        updateGraph();

        default_path = QFileInfo(fileName).path();
        default_filename = QFileInfo(fileName).fileName();
        saveSettings();

        ui->fileNameLabel->setText(fileName);
        watcher->addPath(fileName);
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionHelp_triggered()
{
    HelpWindow *help_window = new HelpWindow(this);
    help_window->exec();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow *about_window = new AboutWindow(this);
    about_window->exec();
}


void MainWindow::on_runButton_clicked()
{
    cmd_process = new QProcess(this);
    connect(cmd_process, SIGNAL(started()),
            this, SLOT(on_cmd_started()));
    connect(cmd_process, SIGNAL(finished(int,QProcess::ExitStatus)),
            this, SLOT(on_cmd_finished()));
    connect(cmd_process, SIGNAL(error(QProcess::ProcessError)),
            this, SLOT(cmd_error_occured(QProcess::ProcessError)));

    QString cmd = ui->textEdit->toPlainText();
    cmd_process->start(cmd);
}

void MainWindow::on_stopButton_clicked()
{
#ifdef  Q_OS_LINUX
    QProcess get_child;
    QStringList get_child_cmd;

    get_child_cmd << "--ppid" << QString::number(cmd_process->processId()) << "-o" << "pid" << "--no-heading";
    get_child.start("ps", get_child_cmd);
    get_child.waitForFinished(5000);

    QString child_str = get_child.readAllStandardOutput();
    int child = child_str.toInt();

    QProcess::execute("kill " + QString::number(child));
#endif // Q_OS_LINUX

    cmd_process->kill();
}

void MainWindow::on_cmd_started()
{
    qDebug() << "Command Started!";

    ui->stopButton->setEnabled(true);
    ui->runButton->setEnabled(false);
}

void MainWindow::on_cmd_finished()
{
    qDebug() << "Command Finished!";

    ui->stopButton->setEnabled(false);
    ui->runButton->setEnabled(true);
}

void MainWindow::cmd_error_occured(QProcess::ProcessError error)
{
    qDebug() << "Error! Error value = " << error;

    switch (error) {
    case QProcess::FailedToStart:
        break;
    default:
        cmd_process->kill();
        break;
    }
}

void MainWindow::resetData()
{
    method_history = "";
    iteration_history = "";
    method_cnt = -1;
    data_line_cnt = 0;

    ui->dataTreeWidget->clear();
    itm_parent.clear();

    data_points.clear();
    op_points_local.clear();
    op_points_all.clear();

    x_max = 0;
    y_max = 0;

    treeitem_change_enabled = false;
    checkall_checkbox_change_enabled = true;

    initGraph();

    watcher->removePaths(watcher->files());
}

void MainWindow::updateData(const QString & filePath)
{
    data_line_cnt = readCsvData(filePath, data_line_cnt);
    if (data_line_cnt == 0) {
        resetData();
    }
    else {
        analyseData();
        updateGraph();
    }

    watcher->addPath(filePath);
}

int MainWindow::readCsvData(QString inputfilename, int num_line)
{
    int line_cnt = 0;
    int i;

    QString line;
    QStringList list;

    QFile file(inputfilename);
    try {
        file.open(QFile::ReadOnly | QFile::Text);
    }
    catch (...) {
        QMessageBox::information(this, "Error", "Cannot open file!");
    }

    QTextStream in(&file);

    treeitem_change_enabled = false;

    //Read Data
    while(!in.atEnd()) {
        line = in.readLine();
        line_cnt++;

        // if the current data is has not been read before, then continue
        if (line_cnt > num_line) {
            list = line.split(",", QString::SkipEmptyParts);

            // Read head line
            if (line_cnt == 1) {
                ui->dataTreeWidget->setColumnCount(list.size());
                ui->dataTreeWidget->setHeaderLabels(list);

                area_index = list.indexOf(tr("AREA"));
                latency_index = list.indexOf(tr("Latency"));
            }

            // Read data
            else {
                if ((list.at(0) != method_history) || (list.at(1) != iteration_history)) {
                    method_cnt++;

                    method_history = list.at(0);
                    iteration_history = list.at(1);

                    data_points.resize(data_points.size() + 1);
                    op_points_local.resize(op_points_local.size() + 1);

                    itm_parent.append(new QTreeWidgetItem(ui->dataTreeWidget, list.mid(0, 2)));
                    itm_parent.last()->setCheckState(0, Qt::Checked);
                }
                itm_parent.last()->addChild(new QTreeWidgetItem(list));

                int area = list.at(area_index).toDouble();
                int latency = list.at(latency_index).toDouble();

                data_points[method_cnt] << QPointF(latency, area);

                x_max = (x_max > latency)? x_max : latency;
                y_max = (y_max > area)? y_max : area;

                // Decide if it is an optimal point for this interation
                bool decision_op = true;
                for(i = 0; i < op_points_local[method_cnt].size(); i++) {
                    if((area >= op_points_local[method_cnt][i].y()) && (latency >= op_points_local[method_cnt][i].x())) {
                        decision_op = false;
                        break;
                    }
                    else if (latency <= op_points_local[method_cnt][i].x()) {
                        break;
                    }
                }
                if (decision_op)
                {
                    // insert by latency order and remove points that no longer optimal
                    op_points_local[method_cnt].insert(i, QPointF(latency, area));

                    for (i = i + 1; i < op_points_local[method_cnt].size(); i++) {
                        if(area <= op_points_local[method_cnt][i].y()) {
                            op_points_local[method_cnt].remove(i);
                            i--;
                        }
                    }

                    // If it is optimal, then decide if it is optimal points for all
                    decision_op = true;
                    for(i = 0; i < op_points_all.size(); i++) {
                        if((area >= op_points_all[i].y()) && (latency >= op_points_all[i].x())) {
                            decision_op = false;
                            break;
                        }
                        else if (latency <= op_points_all[i].x()) {
                            break;
                        }
                    }
                    if (decision_op) {
                        op_points_all.insert(i, QPointF(latency, area));

                        for (i = i + 1; i < op_points_all.size(); i++) {
                            if(area <= op_points_all[i].y()) {
                                op_points_all.remove(i);
                                i--;
                            }
                        }
                    }
                }
            }
        }
    }

    file.close();

    treeitem_change_enabled = true;

    return line_cnt;
}

void MainWindow::analyseData()
{
    double adrs;
    double dominance;
    double hypervolume;

    for (int i = 0; i < itm_parent.size(); i++) {
        if (itm_parent.at(i)->checkState(0) == Qt::Checked) {
            adrs = calADRS(i);
            dominance = calDominance(i);
            hypervolume = calHyperVolume(i);
            itm_parent.at(i)->setText(2, "ADRS:");
            itm_parent.at(i)->setText(3, QString::number(adrs * 100.0, 10, 4) + "%");
            itm_parent.at(i)->setText(4, "Dominance:");
            itm_parent.at(i)->setText(5, QString::number(dominance * 100.0, 10, 4) + "%");
            itm_parent.at(i)->setText(6, "HyperVolume");
            itm_parent.at(i)->setText(7, QString::number(hypervolume * 100.0, 10, 4) + "%");
        }
        else {
            itm_parent.at(i)->setText(3, "");
            itm_parent.at(i)->setText(5, "");
            itm_parent.at(i)->setText(7, "");
        }
    }
}

void MainWindow::getNewOptimalPoints()
{
    int k;
    bool decision_op;

    op_points_all.clear();
    for (int i = 0; i < itm_parent.size(); i++) {
        if (itm_parent.at(i)->checkState(0) == Qt::Checked) {
            for (int j = 0; j < op_points_local[i].size(); j++) {
                QPointF point = op_points_local[i][j];

                decision_op = true;
                for (k = 0; k < op_points_all.size(); k++) {
                    if ((point.x() >= op_points_all[k].x()) && (point.y() >= op_points_all[k].y())) {
                        decision_op = false;
                        break;
                    }
                    else if (point.x() <= op_points_all[k].x()) {
                        break;
                    }
                }
                if (decision_op) {
                    op_points_all.insert(k, point);
                    for (k = k + 1; k < op_points_all.size(); k++) {
                        if (point.y() <= op_points_all[k].y()) {
                            op_points_all.remove(k);
                            k--;
                        }
                    }
                }
            }
        }
    }
}

/*
 *     Calculate dominance
 */
double MainWindow::calDominance(int method_n)
{
    int dominance_cnt = 0;
    for(int i = 0; i < op_points_local[method_n].size(); i++) {
        for(int j = 0; j < op_points_all.size(); j++) {
            if (op_points_local[method_n][i] == op_points_all[j]) {
                dominance_cnt++;
            }
        }
    }

    return (double)dominance_cnt/op_points_all.size();
}

/*
 *     Calculate ADRS
 */
double MainWindow::calADRS(int method_n)
{
    double distance = 0.0;
    double min_dis = 0.0;
    double adrs = 0.0;
    double adrs1 = 0.0;
    double adrs2 = 0.0;
    int mark = 0;
    QVector<double > norm_dis;

    for (int i = 0; i < op_points_all.size(); i++)
    {
        norm_dis.append(sqrt(pow(op_points_all[i].x(),2) + pow(op_points_all[i].y(),2)));
    }

    for(int i = 0; i < op_points_local[method_n].size(); i++)
    {
        for(int j = 0; j < op_points_all.size(); j++)
        {
            distance = sqrt(pow((op_points_local[method_n][i].x() - op_points_all[j].x()),2) +
                            pow((op_points_local[method_n][i].y() - op_points_all[j].y()),2));
            if (j == 0) {
                min_dis = distance;
                mark = j;
            }
            else {
                min_dis = (min_dis < distance)? min_dis : distance;
                mark = (min_dis < distance)? mark : j;
            }
        }
        adrs1 += min_dis / norm_dis.at(mark);
    }
    adrs1 /= op_points_local[method_n].size();

    for(int i = 0; i < op_points_all.size(); i++)
    {
        for(int j = 0; j < op_points_local[method_n].size(); j++)
        {
            distance = sqrt(pow((op_points_local[method_n][j].x() - op_points_all[i].x()),2) +
                            pow((op_points_local[method_n][j].y() - op_points_all[i].y()),2));
            if (j == 0) {
                min_dis = distance;
            }
            else {
                min_dis = (min_dis < distance)? min_dis : distance;
            }
        }
        adrs2 += min_dis / norm_dis.at(i);
    }
    adrs2 /= op_points_all.size();

    adrs = (adrs1 + adrs2) / 2;

    return adrs;
}

/*
 *     Calculate HyperVolume
 */
double MainWindow::calHyperVolume(int method_n)
{
    double hypervolume = 0.0;
    double hypervolume_base = 0.0;

    for (int i = 0; i < op_points_local[method_n].size(); i++) {
        if (i == 0) {
            hypervolume += (op_points_local[method_n][i].x() - op_points_all[0].x()) *
                           (op_points_local[method_n][i].y() + op_points_all[0].y()) * 0.5;
        }
        else {
            hypervolume += (op_points_local[method_n][i].x() - op_points_local[method_n][i - 1].x()) *
                           (op_points_local[method_n][i].y() + op_points_local[method_n][i - 1].y()) * 0.5;
        }
    }

    for (int i = (op_points_all.size() - 1); i >= 0; i--) {
        if (i == (op_points_all.size() - 1)) {
            hypervolume += (op_points_all[i].x() - op_points_local[method_n].last().x()) *
                           (op_points_all[i].y() + op_points_local[method_n].last().y()) * 0.5;
        }
        else {
            hypervolume += (op_points_all[i].x() - op_points_all[i + 1].x()) *
                           (op_points_all[i].y() + op_points_all[i + 1].y()) * 0.5;
            hypervolume_base += (op_points_all[i + 1].x() - op_points_all[i].x()) *
                                (op_points_all[i + 1].y() + op_points_all[i].y()) * 0.5;
        }
    }

    return hypervolume / hypervolume_base;
}

void MainWindow::initGraph()
{

    QCustomPlot *plot = ui->dataPlot;

    plot->clearGraphs();
    plot->xAxis->setLabel("Latency");
    plot->yAxis->setLabel("Area");
    plot->xAxis->setRange(0, x_max + 10.0);
    plot->yAxis->setRange(0, y_max + 100.0);
    plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag | QCP::iSelectPlottables);

    plot->legend->setVisible(false);
    plot->legend->setSelectableParts(QCPLegend::spItems);
    connect(plot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(toggleGraphVisible(QCPLegend*,QCPAbstractLegendItem*)));

    plot->addGraph();
    plot->graph()->setName("Base Line");
    plot->graph()->setPen(QPen(Qt::red));
    plot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond, 6));
    plot->graph()->setLineStyle(QCPGraph::lsLine);
    plot->graph()->removeFromLegend();
    setGraphData(op_points_all, plot->graph());

    plot->replot();
}

void MainWindow::updateGraph()
{
    QCustomPlot *plot = ui->dataPlot;

    plot->xAxis->setRange(0, x_max + 10.0);
    plot->yAxis->setRange(0, y_max + 100.0);
    plot->legend->clear();
    plot->legend->setVisible(true);

    setGraphData(op_points_all, plot->graph(0));
    plot->graph(0)->addToLegend();

    for (int i = 0; i < plot->graphCount() / 2; i++) {
        setGraphData(op_points_local[i], plot->graph(2 * i + 1));
        plot->graph(2 * i + 1)->setVisible((itm_parent.at(i)->checkState(0) == Qt::Checked) && (ui->showOpRaioButton->isChecked()));
        if (plot->graph(2 * i + 1)->visible()) {
            plot->graph(2 * i + 1)->addToLegend();
        }

        setGraphData(data_points[i],     plot->graph(2 * i + 2));
        plot->graph(2 * i + 2)->setVisible((itm_parent.at(i)->checkState(0) == Qt::Checked) && (ui->showAllRadioButton->isChecked()));
        if (plot->graph(2 * i + 2)->visible()) {
            plot->graph(2 * i + 2)->addToLegend();
        }
    }

    // Add new graphs
    for (int i = plot->graphCount() / 2; i < itm_parent.size(); i++) {
        // Add graph for optimal line for each iterations
        plot->addGraph();
        plot->graph()->setName(itm_parent.at(i)->text(0) + "_op");
        plot->graph()->setPen(QPen(QColor(qSin(i*0.6)*100+100, qSin(i*1.2+0.7)*100+100, qSin(i*0.8+0.6)*100+100)));
        plot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
        plot->graph()->setLineStyle(QCPGraph::lsLine);
        setGraphData(op_points_local[i], plot->graph());
        plot->graph()->setVisible((itm_parent.at(i)->checkState(0) == Qt::Checked) && (ui->showOpRaioButton->isChecked()));
        if (plot->graph()->visible()) {
            plot->graph()->addToLegend();
        }

        // Add graph for all points for each iterations
        plot->addGraph();
        plot->graph()->setName(itm_parent.at(i)->text(0) + "_all");
        plot->graph()->setPen(QPen(QColor(qSin(i*0.6)*100+100, qSin(i*1.2+0.7)*100+100, qSin(i*0.8+0.6)*100+100)));
        plot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));
        plot->graph()->setLineStyle(QCPGraph::lsNone);
        setGraphData(data_points[i],     plot->graph());
        plot->graph()->setVisible((itm_parent.at(i)->checkState(0) == Qt::Checked) && (ui->showAllRadioButton->isChecked()));
        if (plot->graph()->visible()) {
            plot->graph()->addToLegend();
        }
    }

    plot->replot();
}

void MainWindow::setGraphData(QVector<QPointF> points, QCPGraph *graph)
{
    QVector<double> x, y;

    for (int i = 0; i < points.size(); i++) {
        x << points[i].x();
        y << points[i].y();
    }
    graph->setData(x, y);
}

void MainWindow::toggleGraphVisible(QCPLegend *legend, QCPAbstractLegendItem *item)
{
    Q_UNUSED(legend)
    if (item) {
        item->setVisible(!item->visible());
    }
}

void MainWindow::on_showOpRaioButton_clicked()
{
    updateGraph();
}

void MainWindow::on_showAllRadioButton_clicked()
{
    updateGraph();
}


void MainWindow::on_dataTreeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(item)
    if ((treeitem_change_enabled) && (column == 0)) {
        treeitem_change_enabled = false;
        getNewOptimalPoints();
        analyseData();
        updateGraph();

        checkall_checkbox_change_enabled = false;
        int check_cnt = 0;
        for (int i = 0; i < itm_parent.size(); i++) {
            if (itm_parent.at(i)->checkState(0) == Qt::Checked) {
                check_cnt++;
            }
        }
        if (check_cnt == 0) {
            ui->checkAllCheckBox->setCheckState(Qt::Unchecked);
        }
        else if (check_cnt == itm_parent.size()) {
            ui->checkAllCheckBox->setCheckState(Qt::Checked);
        }
        else {
            ui->checkAllCheckBox->setCheckState(Qt::PartiallyChecked);
        }
        checkall_checkbox_change_enabled = true;

        treeitem_change_enabled = true;
    }
}

void MainWindow::on_checkAllCheckBox_stateChanged(int state)
{
    if (checkall_checkbox_change_enabled) {
        treeitem_change_enabled = false;
        for (int i = 0; i < itm_parent.size(); i++) {
            itm_parent.at(i)->setCheckState(0, static_cast<Qt::CheckState>(state));
        }

        getNewOptimalPoints();
        analyseData();
        updateGraph();
        treeitem_change_enabled = true;
    }
}

