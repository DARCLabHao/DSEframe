#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QWidget *parent)
    : QCheckBox(parent)
{

}

MyCheckBox::~MyCheckBox()
{

}

void MyCheckBox::nextCheckState() {
    if (this->checkState() == Qt::Checked) {
        this->setCheckState(Qt::Unchecked);
    }
    else {
        this->setCheckState(Qt::Checked);
    }
}
