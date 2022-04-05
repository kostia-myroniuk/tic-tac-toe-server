#include "server.h"
#include "connection_settings.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    connect(&server, &QTcpServer::newConnection, this, &Server::NewConnection);
}

QString Server::SocketAddressAndPort(QTcpSocket* socket)
{
    QString address = socket->peerAddress().toString();
    QString port = QString::number(socket->peerPort(), 10);
    return address + ":" + port;
}

void Server::Start()
{
    server.listen(tcp_connection_settings::address, tcp_connection_settings::port);
}

void Server::Quit()
{
    server.close();
}

void Server::NewConnection()
{
    QTcpSocket* socket = server.nextPendingConnection();
    connect(socket, &QTcpSocket::disconnected, this, &Server::Disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Server::ReadyRead);
    QString addressAndPort = SocketAddressAndPort(socket);
    qInfo() << "New socket connection: " << addressAndPort;
}

void Server::Disconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QString addressAndPort = SocketAddressAndPort(socket);
    qInfo() << "Socket disconnected: " << addressAndPort;
}

void Server::ReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (socket != nullptr) {
        QString addressAndPort = SocketAddressAndPort(socket);
        qInfo() << "Ready to read from socket: " << addressAndPort;
        qInfo() << "Message from socket:\n" << socket->readAll();
    }
}
