/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(558, 575);
        gridLayout = new QGridLayout(HelpWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(HelpWindow);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QDialog *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("HelpWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
