#ifndef DIALOGTIP_H
#define DIALOGTIP_H

#include <QDialog>

namespace Ui {
class DialogTip;
}

class DialogTip : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTip(QWidget *parent = 0);
    ~DialogTip();

private:
    Ui::DialogTip *ui;
};

#endif // DIALOGTIP_H
