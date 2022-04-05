#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <algorithm>

#include "board_size.h"

class GameSettings
{
public:
    GameSettings(int _boardSize, int _winSequenceSize);
    int GetBoardSize();
    int GetWinSequenceSize();

private:
    int boardSize;
    int winSequenceSize;
};

#endif // GAMESETTINGS_H
