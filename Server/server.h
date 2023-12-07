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
    QUdpSocket *mSocket = nullptr;
};

#endif // SERVER_H
