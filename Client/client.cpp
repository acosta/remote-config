#include "client.h"

#include <QUdpSocket>

const quint16 SOCKET_PORT = 1454;

Client::Client(QObject *parent)
    : QObject{parent},
    mSocket(new QUdpSocket(this))
{}

Client::~Client()
{
    if (mSocket->isOpen()) {
        mSocket->close();
    }
    delete mSocket;
}

void Client::sendConfig(ConfigData config)
{
    qDebug() << "Sending configuration datagram...";
    qDebug() << "Temperature == " << config.temperature << " velocity == " << config.velocity;
    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_6);
    stream << config.temperature << config.velocity;
    mSocket->writeDatagram(datagram, QHostAddress::LocalHost, SOCKET_PORT);
}
