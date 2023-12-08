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

void Client::sendConfig(quint16 temperature, quint16 velocity)
{
    qDebug() << "Sending configuration datagram...";
    qDebug() << "Temperature == " << temperature << " velocity == " << velocity;
    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_6);
    stream << temperature << velocity;
    mSocket->writeDatagram(datagram, QHostAddress::LocalHost, SOCKET_PORT);
}
