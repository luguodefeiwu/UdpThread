#ifndef UDPRECVTHREAD_H
#define UDPRECVTHREAD_H

#include <QThread>
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include "database.h"

class UdpRecvThread : public QThread
{
    Q_OBJECT

private:
    QUdpSocket *socket;
    char* recvBuffer;
    int recvDataLength;
    QMutex mutex;
    int localPort;

public:
    explicit UdpRecvThread(quint16 listenPort, char* buffer, int length, QObject *parent = nullptr);
    ~UdpRecvThread();

    void socketReBind();
    void stop();

signals:
    void haveRecvData(bool);

protected:
    void run() override;
};

#endif // UDPRECVTHREAD_H
