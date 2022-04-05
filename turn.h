#ifndef TURN_H
#define TURN_H

enum class PlayerSide {
    X,
    O
};

class Turn
{
public:
    Turn(int _row, int _column, PlayerSide _playerSide);
    int GetRow();
    int GetColumn();
    PlayerSide GetPlayerSide();

private:
    int row;
    int column;
    PlayerSide playerSide;
};

#endif // TURN_H
