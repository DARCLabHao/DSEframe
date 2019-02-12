/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *logoLabel;
    QLabel *appNameLabel;
    QLabel *appInfoLabel;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(456, 429);
        AboutWindow->setSizeGripEnabled(false);
        logoLabel = new QLabel(AboutWindow);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(50, 30, 381, 121));
        appNameLabel = new QLabel(AboutWindow);
        appNameLabel->setObjectName(QStringLiteral("appNameLabel"));
        appNameLabel->setGeometry(QRect(50, 160, 321, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        appNameLabel->setFont(font);
        appInfoLabel = new QLabel(AboutWindow);
        appInfoLabel->setObjectName(QStringLiteral("appInfoLabel"));
        appInfoLabel->setGeometry(QRect(60, 210, 341, 181));

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "Dialog", nullptr));
        logoLabel->setText(QString());
        appNameLabel->setText(QApplication::translate("AboutWindow", "DSE Explorer Framework", nullptr));
        appInfoLabel->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Version: 1.0.0 (Build on Feb. 7 2019)</span><br/></p><p><span style=\" font-size:10pt;\">Based on Qt 5.10.0<br/></span></p><p><span style=\" font-size:10pt;\">All of the work has been done by the DARClab</span></p><p><span style=\" font-size:10pt;\">(Design Automation and Reconfigurable Computing Laboratory)</span></p><p><a href=\"https://www.utdallas.edu/~schaferb/darclab/\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">https://www.utdallas.edu/~schaferb/darclab/</span></a><span style=\" font-size:10pt;\"><br/></span></p><p><span style=\" font-size:10pt;\">The program is provided AS IS with NO WARRANTY OF ANY KIND.</span></p><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
