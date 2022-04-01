#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <vector>
#include <algorithm>
#include <map>

const int MIN_BOARD_SIZE = 3;
const int MAX_BOARD_SIZE = 10;

enum class BoardState {
    UNFINISHED,
    PLAYER_X_WON,
    PLAYER_O_WON,
    DRAW
};

class Board
{
public:
    Board(int _size, int _winSequenceSize);
    int GetSize();
    int GetWinSequenceSize();
    Cell* GetCell(int row, int column);
    BoardState GetBoardState();

private:
    int size;
    int winSequenceSize;
    std::vector<Cell> cells;
};

#endif // BOARD_H
