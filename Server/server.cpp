#include "server.h"

#include <QUdpSocket>

Server::Server(QObject *parent)
    : QObject{parent},
    mSocket(new QUdpSocket(this))
{
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(handleReceivedConfig()));
}

Server::~Server()
{
    if (mSocket->isOpen())
        mSocket->close();

    delete mSocket;
}

void Server::handleReceivedConfig()
{
    qDebug() << "Received config";
    QByteArray datagram;
    while (mSocket->hasPendingDatagrams()) {
        datagram.resize(mSocket->pendingDatagramSize());
        mSocket->readDatagram(datagram.data(), datagram.size());
        qDebug() << "data: " << datagram.constData();
    }
}
