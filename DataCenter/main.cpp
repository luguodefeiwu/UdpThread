#include "mainwindow.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    checkAndCreateSettingsFile(getSettingsFilePath());
    qDebug() << "****** 当前配置文件位置 ******";
    qDebug() << getSettingsFilePath();
    qDebug() << "****** 系统初始化 ******";

    MainWindow w;
    w.show();

    return a.exec();
}
