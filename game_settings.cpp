#include "game_settings.h"

GameSettings::GameSettings(int _boardSize, int _winSequenceSize)
{
    boardSize = std::clamp(_boardSize, MIN_BOARD_SIZE, MAX_BOARD_SIZE);
    winSequenceSize = std::clamp(_winSequenceSize, MIN_BOARD_SIZE, boardSize);
}

int GameSettings::GetBoardSize()
{
    return boardSize;
}

int GameSettings::GetWinSequenceSize()
{
    return winSequenceSize;
}
