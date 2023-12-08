#include "server.h"

#include <QDateTime>
#include <QFile>
#include <QUdpSocket>

const quint16 SOCKET_PORT = 1454;

Server::Server(QObject *parent)
    : QObject{parent},
    mSocket(new QUdpSocket(this))
{
    mSocket->bind(QHostAddress::LocalHost, SOCKET_PORT, QUdpSocket::ShareAddress);
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
    qDebug() << "Received config at " << QDateTime::currentDateTime().toString();

    QByteArray receivedDatagram;
    do {
        receivedDatagram.resize(int(mSocket->pendingDatagramSize()));
        mSocket->readDatagram(receivedDatagram.data(), receivedDatagram.size());
    } while(mSocket->hasPendingDatagrams());

    quint16 temperature, velocity;
    QDataStream stream(&receivedDatagram, QIODevice::ReadOnly);
    stream.setVersion(QDataStream::Qt_6_6);
    stream >> temperature >> velocity;

    qDebug() << "Temperature: " << temperature << "Velocity: " << velocity;

    saveConfigToFile(temperature, velocity);
}

void Server::saveConfigToFile(quint16 temperature, quint16 velocity)
{
    QFile file("remote-config.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "File could not be opened!";
        return;
    }
    QTextStream stream(&file);
    stream << "temperature: " << temperature << " velocity: " << velocity;

    file.close();
}
