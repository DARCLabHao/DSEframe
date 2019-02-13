#ifndef NEWFILE_H
#define NEWFILE_H

#include <QDialog>

namespace Ui {
class Newfile;
}

class Newfile : public QDialog
{
    Q_OBJECT

public:
    explicit Newfile(QWidget *parent = 0);
    ~Newfile();

    QString fileName;

private:

    void loadSettings();

    void saveSettings();

private slots:
    void on_directoryButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Newfile *ui;

    QString m_sSettingsFile;
    QString default_path;
    QString default_filename;
};

#endif // NEWFILE_H
