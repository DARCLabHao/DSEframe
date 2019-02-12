#include "newfile.h"
#include "ui_newfile.h"

#include <QFileDialog>
#include <QSettings>

Newfile::Newfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newfile)
{
    ui->setupUi(this);
    this->setWindowTitle("New file");

    m_sSettingsFile = QApplication::applicationDirPath() + "/demosettings.ini";
    loadSettings();

    ui->directoryLineEdit->setText(default_path);
    ui->fileNameLineEdit->setText(default_filename);
}

Newfile::~Newfile()
{
    delete ui;
}

void Newfile::loadSettings()
{
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    default_path = settings.value("directoryPath", "").toString();
    default_filename = settings.value("fileName", "").toString();
}

void Newfile::saveSettings()
{
    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    settings.setValue("directoryPath", default_path);
    settings.setValue("fileName", default_filename);
}

void Newfile::on_directoryButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this,
                                                         tr("Open Directory"),
                                                         default_path,
                                                         QFileDialog::ShowDirsOnly);
    if (!filePath.isEmpty()) {
        ui->directoryLineEdit->setText(filePath);
    }
}

void Newfile::on_buttonBox_accepted()
{
    default_filename = ui->fileNameLineEdit->text();
    default_path = ui->directoryLineEdit->text();
    saveSettings();

    fileName = default_path + "/" + default_filename;
}
