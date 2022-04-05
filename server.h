#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>

#include <vector>
#include <map>
#include <string>

#include "lobby.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

private:
    QTcpServer server;

    QString SocketAddressAndPort(QTcpSocket* socket);

signals:

public slots:
    void Start();
    void Quit();
    void NewConnection();
    void Disconnected();
    void ReadyRead();
};

#endif // SERVER_H
