#include "aboutwindow.h"
#include "ui_aboutwindow.h"

#include <QPixmap>

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("About DEEF");
    this->setFixedSize(this->size());

    QString image_path = QApplication::applicationDirPath() + "/darclab_logo_utd_grey.png";
    QPixmap image(image_path);
    const int w = ui->logoLabel->width();
    const int h = ui->logoLabel->height();
    ui->logoLabel->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
