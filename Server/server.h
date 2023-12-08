#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class QUdpSocket;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

private slots:
    void handleReceivedConfig();

private:
    void saveConfigToFile(quint16 temperature, quint16 velocity);

    QUdpSocket *mSocket = nullptr;
};

#endif // SERVER_H
