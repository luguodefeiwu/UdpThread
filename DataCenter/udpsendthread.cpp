#include "udpsendthread.h"
#include <QMutexLocker>

UdpSendThread::UdpSendThread(QString IP, quint16 port, QObject *parent)
    : QThread(parent), targetAddress(QHostAddress(IP)), targetPort(port), flag(false)
{
//    sendSocket = new QUdpSocket(this);
}

UdpSendThread::~UdpSendThread()
{
    stop();
}

void UdpSendThread::stop()
{
    setFlag(false);
    requestInterruption();
    quit();
    wait();
}

void UdpSendThread::setFlag(bool value)
{
    QMutexLocker locker(&mutex);
    flag = value;
}

void UdpSendThread::setSendBuffer(QByteArray buffer)
{
    QMutexLocker locker(&mutex);
    sendBuffer = buffer;
}

void UdpSendThread::run()
{
    sendSocket = new QUdpSocket();
    qDebug() << "IP: " << targetAddress;
    qDebug() << "Port: " << targetPort;

    while (true)
    {
        {
            QMutexLocker locker(&mutex);
            if (!flag) break;

            if (!sendBuffer.isEmpty())
            {
                qint64 bytesSent = sendSocket->writeDatagram(sendBuffer, targetAddress, targetPort);
                if (bytesSent == -1) {
                    qWarning() << "Failed to send datagram:" << sendSocket->errorString();
                }
            }
        }
        msleep(3000);  // 发送间隔
    }

    sendSocket->close();
    delete sendSocket;
    sendSocket = nullptr;
}
