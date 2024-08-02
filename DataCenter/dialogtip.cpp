#include "dialogtip.h"
#include "ui_dialogtip.h"

DialogTip::DialogTip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTip)
{
    ui->setupUi(this);
    setWindowTitle("提示");
}

DialogTip::~DialogTip()
{
    delete ui;
}
