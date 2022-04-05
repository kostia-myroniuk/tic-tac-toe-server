#ifndef GAME_H
#define GAME_H

#include <vector>

#include "board.h"
#include "player.h"
#include "turn.h"
#include "game_settings.h"

class Game
{
public:
    Game(GameSettings* settings);
    Board* GetBoard();
    QString JsonTurnHistory();
    bool MakeTurn(Turn* turn);

private:
    Board board;
    PlayerSide currentPlayerSide;
    std::vector<Turn*> turnHistory;

    PlayerSide OppositePlayerSide(PlayerSide playerSide);
    CellMark PlayerSideMark(PlayerSide playerSide);
};

#endif // GAME_H
