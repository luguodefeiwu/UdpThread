#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QTabWidget>
#include <QMainWindow>
#include <QByteArray>
#include <QProcess>
#include <QApplication>

#include "editsystem.h"
#include "showsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    template <typename T>
    T* getWidgetFromTab(QTabWidget *tabWidget, int index) {
        if (index >= 0 && index < tabWidget->count()) {
            QWidget *widget = tabWidget->widget(index);
            return qobject_cast<T*>(widget);
        }
        return nullptr;
    }

private slots:
    void on_action_Exit_triggered();

    void on_action_CreateSystem_triggered();

    void on_mainTabWidget_currentChanged(int index);

    void showNewData(bool);

    void closeTab(ShowSystem *system);

    void processPendingDatagrams();

    void on_pushBtn_Listen_clicked();

private:
    void initialize();
    void createNewSystem(char* buffer,int startAddress, int len, systemDataSetting db);
    void printRecvBuffer();
    void setSendData();
    void sendRecvBuffer();
    void restart();

private:
    Ui::MainWindow *ui;
    EditSystem *dialog;
    int recvBufferLength;   //数据总长度
    int offset;             //偏移量
    char* currentBuffer;    //当前指针位置
    QByteArray recvBuffer;  //缓冲区
    QByteArray sendBuffer;
    mainStruct mainData;
    QString fileName;

    QUdpSocket *jsonSocket;
    QUdpSocket *sendSocket;
};

#endif // MAINWINDOW_H
