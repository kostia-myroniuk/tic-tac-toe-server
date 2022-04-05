#include "player.h"

Player::Player(QTcpSocket* _socket, QString _nickname)
{
    socket = _socket;
    nickname = _nickname;
}

bool Player::EqualTo(Player *anotherPlayer)
{
    return socket->peerAddress() == anotherPlayer->socket->peerAddress() &&
        socket->peerPort() == anotherPlayer->socket->peerPort();
}
