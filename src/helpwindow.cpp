#include "helpwindow.h"
#include "ui_helpwindow.h"

#include <QFile>
#include <QTextStream>

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Help");

    ui->label->setWordWrap(true);
    QString readme_path = QApplication::applicationDirPath() + "/README.txt";
    QFile file(readme_path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        if (!stream.atEnd()) {
            ui->label->setText(stream.readAll());
        }
    }
    file.close();
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
