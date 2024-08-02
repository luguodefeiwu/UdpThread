#ifndef SHOWSYSTEM_H
#define SHOWSYSTEM_H

#include <QMainWindow>
#include <QTableWidget>
#include "database.h"
#include "editsystem.h"
#include "dialogtip.h"
#include "udprecvthread.h"
#include "udpsendthread.h"
#include "QVariantList"
#include <QDataStream>

namespace Ui {
class ShowSystem;
}

class ShowSystem : public QMainWindow
{
    Q_OBJECT
public:
    explicit ShowSystem(char* buffer, int length, systemDataSetting setting, QWidget *parent = 0);
    ~ShowSystem();

private:
    void initialize();

    void setSystemData();

    void initializeNet();

public:
    void setSendData(QByteArray buffer, QStringList dataType);

    void setStartAddress(int address);

    int getRecvDatalength();

    int getStartAddress();

    systemDataSetting getDB();

    void closeAllThread();

signals:
    void reviseSetting(bool);

    void haveRecvData(bool);

    void dataProcessed(QByteArray sendBuffer, QStringList dataType);

    void closeCurrentTab(ShowSystem *system);

private slots:
    void on_pushBtn_ReviseSystem_clicked();

    void on_pushButton_clicked();

    void showRecvData(bool flag);

    void updateTableWidget(QByteArray sendBuffer, QStringList dataType);

private:
    Ui::ShowSystem *ui;
    QTableWidgetItem *headItem;
    QTableWidgetItem *item;
    systemDataSetting db;
    QList<QVariant> list;
    QByteArray sendBuffer;

    UdpRecvThread *recvThread;
    UdpSendThread *sendThread;

    char* recvBuffer;
    int recvBufferLength;
    int startAddress;
};

#endif // SHOWSYSTEM_H
