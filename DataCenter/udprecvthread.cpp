#include "udprecvthread.h"
#include <QDebug>
#include <QMutexLocker>

UdpRecvThread::UdpRecvThread(quint16 listenPort, char *buffer, int length, QObject *parent)
    : QThread(parent), localPort(listenPort), recvBuffer(buffer), recvDataLength(length), socket(new QUdpSocket(this))
{
//    if (!socket->bind(listenPort)) {
//        qWarning() << "Failed to bind port:" << listenPort;
//    } else {
//        qDebug() << "Successfully bound to port:" << listenPort;
//    }
}

UdpRecvThread::~UdpRecvThread()
{
    stop();
}

void UdpRecvThread::socketReBind()
{
    QMutexLocker locker(&mutex);
    socket->abort();
    qDebug() << "Socket unbound successfully";
}

void UdpRecvThread::stop()
{
    requestInterruption();
    quit();
    wait();
}

void UdpRecvThread::run()
{
    socket = new QUdpSocket();
    if (!socket->bind(QHostAddress::Any, localPort))
    {
        qWarning() << "Failed to bind port:" << localPort;
        delete socket;
        socket = nullptr;
        return;
    } else {
        qDebug() << "Successfully bound to port:" << localPort;
    }

    while (!isInterruptionRequested()) {
        if (socket->waitForReadyRead(10)) {
            while (socket->hasPendingDatagrams()) {
                QMutexLocker locker(&mutex);  // Ensure thread-safe access to recvBuffer

                qint64 bytesRead = socket->readDatagram(recvBuffer, recvDataLength);
                if (bytesRead == -1) {
                    qWarning() << "Failed to read datagram:" << socket->errorString();
                } else {
                    emit haveRecvData(true);  // Emit signal to notify data reception
                }
            }
        }
    }

    socket->close();
    delete socket;
    socket = nullptr;
}
