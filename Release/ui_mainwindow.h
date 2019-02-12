/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycheckbox.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QAction *actionExit;
    QAction *actionLoad_File;
    QAction *actionNew_File;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *filNameGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *fileNameLabel;
    QGroupBox *dataGroup;
    QGridLayout *gridLayout;
    MyCheckBox *checkAllCheckBox;
    QTreeWidget *dataTreeWidget;
    QGroupBox *commandGroup;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QPushButton *stopButton;
    QPushButton *runButton;
    QGroupBox *graphGroup;
    QGridLayout *gridLayout_3;
    QCustomPlot *dataPlot;
    QHBoxLayout *dataSelectionHorizontalLayout;
    QRadioButton *showAllRadioButton;
    QRadioButton *showOpRaioButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1374, 758);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLoad_File = new QAction(MainWindow);
        actionLoad_File->setObjectName(QStringLiteral("actionLoad_File"));
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filNameGroupBox = new QGroupBox(centralWidget);
        filNameGroupBox->setObjectName(QStringLiteral("filNameGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filNameGroupBox->sizePolicy().hasHeightForWidth());
        filNameGroupBox->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(filNameGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        fileNameLabel = new QLabel(filNameGroupBox);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        sizePolicy.setHeightForWidth(fileNameLabel->sizePolicy().hasHeightForWidth());
        fileNameLabel->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(fileNameLabel, 0, 0, 1, 1);


        verticalLayout->addWidget(filNameGroupBox);

        dataGroup = new QGroupBox(centralWidget);
        dataGroup->setObjectName(QStringLiteral("dataGroup"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dataGroup->sizePolicy().hasHeightForWidth());
        dataGroup->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(dataGroup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkAllCheckBox = new MyCheckBox(dataGroup);
        checkAllCheckBox->setObjectName(QStringLiteral("checkAllCheckBox"));
        checkAllCheckBox->setCheckable(true);
        checkAllCheckBox->setChecked(true);
        checkAllCheckBox->setAutoRepeatDelay(298);
        checkAllCheckBox->setTristate(false);

        gridLayout->addWidget(checkAllCheckBox, 1, 0, 1, 1);

        dataTreeWidget = new QTreeWidget(dataGroup);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        dataTreeWidget->setHeaderItem(__qtreewidgetitem);
        dataTreeWidget->setObjectName(QStringLiteral("dataTreeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dataTreeWidget->sizePolicy().hasHeightForWidth());
        dataTreeWidget->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(dataTreeWidget, 0, 0, 1, 1);


        verticalLayout->addWidget(dataGroup);

        commandGroup = new QGroupBox(centralWidget);
        commandGroup->setObjectName(QStringLiteral("commandGroup"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(commandGroup->sizePolicy().hasHeightForWidth());
        commandGroup->setSizePolicy(sizePolicy4);
        gridLayout_2 = new QGridLayout(commandGroup);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit = new QTextEdit(commandGroup);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(textEdit, 0, 0, 3, 1);

        stopButton = new QPushButton(commandGroup);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(stopButton, 2, 1, 1, 1);

        runButton = new QPushButton(commandGroup);
        runButton->setObjectName(QStringLiteral("runButton"));
        sizePolicy6.setHeightForWidth(runButton->sizePolicy().hasHeightForWidth());
        runButton->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(runButton, 0, 1, 1, 1);


        verticalLayout->addWidget(commandGroup);


        horizontalLayout_3->addLayout(verticalLayout);

        graphGroup = new QGroupBox(centralWidget);
        graphGroup->setObjectName(QStringLiteral("graphGroup"));
        sizePolicy.setHeightForWidth(graphGroup->sizePolicy().hasHeightForWidth());
        graphGroup->setSizePolicy(sizePolicy);
        graphGroup->setAutoFillBackground(false);
        gridLayout_3 = new QGridLayout(graphGroup);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        dataPlot = new QCustomPlot(graphGroup);
        dataPlot->setObjectName(QStringLiteral("dataPlot"));
        sizePolicy5.setHeightForWidth(dataPlot->sizePolicy().hasHeightForWidth());
        dataPlot->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(dataPlot, 0, 0, 1, 1);

        dataSelectionHorizontalLayout = new QHBoxLayout();
        dataSelectionHorizontalLayout->setSpacing(6);
        dataSelectionHorizontalLayout->setObjectName(QStringLiteral("dataSelectionHorizontalLayout"));
        showAllRadioButton = new QRadioButton(graphGroup);
        showAllRadioButton->setObjectName(QStringLiteral("showAllRadioButton"));
        showAllRadioButton->setChecked(true);

        dataSelectionHorizontalLayout->addWidget(showAllRadioButton);

        showOpRaioButton = new QRadioButton(graphGroup);
        showOpRaioButton->setObjectName(QStringLiteral("showOpRaioButton"));
        showOpRaioButton->setAcceptDrops(false);
        showOpRaioButton->setChecked(false);

        dataSelectionHorizontalLayout->addWidget(showOpRaioButton);


        gridLayout_3->addLayout(dataSelectionHorizontalLayout, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(graphGroup);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1374, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionLoad_File);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionLoad_File->setText(QApplication::translate("MainWindow", "Load File", nullptr));
        actionNew_File->setText(QApplication::translate("MainWindow", "New File", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        filNameGroupBox->setTitle(QApplication::translate("MainWindow", "Current File Path:", nullptr));
        fileNameLabel->setText(QString());
        dataGroup->setTitle(QApplication::translate("MainWindow", "Result analyse", nullptr));
        checkAllCheckBox->setText(QApplication::translate("MainWindow", "All/None", nullptr));
        commandGroup->setTitle(QApplication::translate("MainWindow", "Executable Command", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        runButton->setText(QApplication::translate("MainWindow", "Run", nullptr));
        graphGroup->setTitle(QApplication::translate("MainWindow", "Design Space Exploration Plot", nullptr));
        showAllRadioButton->setText(QApplication::translate("MainWindow", "Show all", nullptr));
        showOpRaioButton->setText(QApplication::translate("MainWindow", "Show optimum", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
