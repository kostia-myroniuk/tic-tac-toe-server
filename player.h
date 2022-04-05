#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QString>

class Player
{
public:
    Player(QTcpSocket* _socket, QString _nickname);
    bool EqualTo(Player* anotherPlayer);

private:
    QTcpSocket* socket;
    QString nickname;
};

#endif // PLAYER_H
