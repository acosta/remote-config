#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QUdpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    ~Client();
    void sendConfig(quint16 temperature, quint16 velocity);

private:
    QUdpSocket *mSocket = nullptr;
};

#endif // CLIENT_H
