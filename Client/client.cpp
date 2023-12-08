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

void Client::connect()
{
    if (mSocket->isOpen())
        return;

    mSocket->bind(SOCKET_PORT, QUdpSocket::ShareAddress);
}

void Client::disconnect()
{
    mSocket->close();
}

void Client::sendConfig(quint16 temperature, quint16 velocity)
{
    qDebug() << "Seding the configuration with temperature == " << temperature << " velocity == " << velocity;
}
