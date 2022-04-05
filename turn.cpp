#include "turn.h"

Turn::Turn(int _row, int _column, PlayerSide _playerSide)
{
    row = _row;
    column = _column;
    playerSide = _playerSide;
}

int Turn::GetRow()
{
    return row;
}

int Turn::GetColumn()
{
    return column;
}

PlayerSide Turn::GetPlayerSide()
{
    return playerSide;
}
