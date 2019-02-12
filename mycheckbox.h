#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>

class MyCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    explicit MyCheckBox(QWidget *parent = Q_NULLPTR);
    ~MyCheckBox();

public slots:
    void nextCheckState() override;
};

#endif // MYCHECKBOX_H
