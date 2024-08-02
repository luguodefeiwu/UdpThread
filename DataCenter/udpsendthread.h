#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H

#include <QObject>
#include <QThread>
#include <QHostAddress>
#include <QUdpSocket>
#include <mutex>
#include <QMutexLocker>
#include "database.h"

class UdpSendThread : public QThread
{
    Q_OBJECT
private:
    QUdpSocket *sendSocket;
    QByteArray sendBuffer;
    QHostAddress targetAddress;
    quint16 targetPort;
    bool flag;
    QMutex mutex;

public:
    explicit UdpSendThread(QString IP, quint16 tPort, QObject *parent = nullptr);
    ~UdpSendThread();

    void stop();
    void setFlag(bool value);
    void setSendBuffer(QByteArray buffer);

signals:

public slots:

    // QThread interface
protected:
    void run() override;
};

#endif // UDPSENDTHREAD_H
