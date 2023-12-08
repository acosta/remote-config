#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QUdpSocket;

struct ConfigData
{
    quint16 temperature;
    quint16 velocity;
};


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    ~Client();
    void sendConfig(ConfigData config);

private:
    QUdpSocket *mSocket = nullptr;
};

#endif // CLIENT_H
