#ifndef NETWORKSEVER_H
#define NETWORKSEVER_H

#include <QTcpServer>
#include <memory>

class NetworkPlugin;
class NetworkClient;

class NetworkServer : public QTcpServer
{
    Q_OBJECT

    int nextClientId{1};

    std::vector<std::unique_ptr<NetworkClient>> clients;

    NetworkPlugin& conn;

public:
    explicit NetworkServer(NetworkPlugin& conn, QObject *parent = 0);
    ~NetworkServer();

    void startServer();
    void stopServer();

signals:

public slots:

protected:

    void incomingConnection(qintptr socketDescriptor);
public:
    void receiver(int connectionId, const std::string& data);
    bool queueToSend(int connectionId, const std::string& data);
    void sendAllQueued();
};

#endif // NETWORKSEVER_H