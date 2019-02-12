/********************************************************************************
** Form generated from reading UI file 'newfile.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILE_H
#define UI_NEWFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Newfile
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *fileNameLineEdit;
    QPushButton *directoryButton;
    QLabel *headLabel;
    QLabel *directoryLabel;
    QLabel *fileNameLabel;
    QLineEdit *directoryLineEdit;

    void setupUi(QDialog *Newfile)
    {
        if (Newfile->objectName().isEmpty())
            Newfile->setObjectName(QStringLiteral("Newfile"));
        Newfile->resize(573, 227);
        buttonBox = new QDialogButtonBox(Newfile);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(380, 190, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        fileNameLineEdit = new QLineEdit(Newfile);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));
        fileNameLineEdit->setGeometry(QRect(150, 120, 291, 21));
        directoryButton = new QPushButton(Newfile);
        directoryButton->setObjectName(QStringLiteral("directoryButton"));
        directoryButton->setGeometry(QRect(470, 80, 71, 21));
        headLabel = new QLabel(Newfile);
        headLabel->setObjectName(QStringLiteral("headLabel"));
        headLabel->setGeometry(QRect(30, 30, 151, 21));
        directoryLabel = new QLabel(Newfile);
        directoryLabel->setObjectName(QStringLiteral("directoryLabel"));
        directoryLabel->setGeometry(QRect(40, 80, 71, 21));
        fileNameLabel = new QLabel(Newfile);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(40, 120, 61, 21));
        directoryLineEdit = new QLineEdit(Newfile);
        directoryLineEdit->setObjectName(QStringLiteral("directoryLineEdit"));
        directoryLineEdit->setGeometry(QRect(150, 80, 291, 21));

        retranslateUi(Newfile);
        QObject::connect(buttonBox, SIGNAL(accepted()), Newfile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Newfile, SLOT(reject()));

        QMetaObject::connectSlotsByName(Newfile);
    } // setupUi

    void retranslateUi(QDialog *Newfile)
    {
        Newfile->setWindowTitle(QApplication::translate("Newfile", "Dialog", nullptr));
        fileNameLineEdit->setText(QApplication::translate("Newfile", "explorer.CSV", nullptr));
        directoryButton->setText(QApplication::translate("Newfile", "Browse...", nullptr));
        headLabel->setText(QApplication::translate("Newfile", "Add DSE result file (*.CSV)", nullptr));
        directoryLabel->setText(QApplication::translate("Newfile", "Directory:", nullptr));
        fileNameLabel->setText(QApplication::translate("Newfile", "File name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Newfile: public Ui_Newfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILE_H
